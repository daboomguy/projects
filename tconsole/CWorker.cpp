#include "CWorker.h"
#include <wx/event.h>
#include "wx/log.h"
#include <errno.h>
#include "frmMain.h"
#include "crc32.h"
#include <fstream>
#include <sstream>
#include "pugixml.hpp"
#include <tr1/functional>
#include <memory.h>
#include <tr1/memory>
#include <stdlib.h>

static struct event_base *base;
static struct sockaddr_storage connect_to_addr;
static int connect_to_addrlen;
bool CWorker::isConnected=false;
bool CWorker::isTryConnect=false;
struct bufferevent * CWorker::connector=NULL;

CWorker::CWorker(frmMain *arMain, const char *arConfigPath)
: wxThread(wxTHREAD_DETACHED), pMain(arMain), state(PREAUTH)
{
  //ctor
  base=event_base_new();
  if (!base) {
    throw "event_base_new()";
  }
  config=CConfig::getInstance(arConfigPath);
  crybase=CCryptoKeyBase::getInstance(config->settings.key_path.c_str());
  iLocalId=config->settings.my_node;
  tmKA=evtimer_new(base, timeout, this);
  crypt.ClearEncVars();
}

CWorker::~CWorker()
{
  //dtor
  event_base_free(base);
  config->free();
}

void *CWorker::Entry()
{
  while (true) {
    if (!isConnected && !isTryConnect)
      connect(config->settings.vit_connectors.front().getCurrentIpPort().c_str());

    do {
      event_base_loop(base, EVLOOP_NONBLOCK);
    }
    while (!isConnected && isTryConnect);


    Process();
    wxMilliSleep(100);
  }
  return 0;
}

void CWorker::KeepAliving()
{
  if (ka_state==KA_NEED_SEND) {
    ka_state=KA_SEND;
    uint8 ka[16]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    crypt.Enc(ka, 16, ka, 16);
    Write(ka, 16);
    setTimeout(config->settings.vit_connectors.front().keep_alive_recv);
    //wxMessageOutputDebug().Printf("send keepalive");
  }
  else if (ka_state==KA_RECV) {
    ka_state=KA_NEED_SEND;
    setTimeout(config->settings.vit_connectors.front().keep_alive_send -
               config->settings.vit_connectors.front().keep_alive_recv);
  }
  else {
    //wxMessageOutputDebug().Printf("keepalive timeout, disconnect");
    disconnect();
  }
}

void CWorker::connect(wxString IpPort)
{
  memset(&connect_to_addr, 0, sizeof(connect_to_addr));
	connect_to_addrlen=sizeof(connect_to_addr);


	if (evutil_parse_sockaddr_port(IpPort.c_str(), (struct sockaddr*)&connect_to_addr, &connect_to_addrlen)<0)
		return;

  connector=bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE|BEV_OPT_DEFER_CALLBACKS);

  bufferevent_setcb(connector, read, NULL, event, this);
  bufferevent_enable(connector, EV_READ|EV_WRITE);

  //wxMessageOutputDebug().Printf("Try connect to "+IpPort);

  if (bufferevent_socket_connect(connector, (struct sockaddr*)&connect_to_addr, connect_to_addrlen)<0) {
    if (errno) {
      wxMessageOutputDebug().Printf("Error (%d): %s" , errno, strerror(errno));
    }
    bufferevent_free(connector);
  }

  isTryConnect=true;
  return ;
}

void CWorker::read(struct bufferevent *bev, void *ctx)
{
  int length=0;
//  char *buffer[1024]={0};

  struct evbuffer *in_temp_buffer=NULL;

  in_temp_buffer=bufferevent_get_input(bev);
  length=evbuffer_get_length(in_temp_buffer);

  if (length<=0)
    return;

//  wxMessageOutputDebug().Printf("OnRead %d bytes", length);
  //wxMessageOutputDebug().Printf("Len1 %d bytes", (uint32)((CWorker *)ctx)->InputBuffer.size());
  uint32 oldsize=((CWorker *)ctx)->InputBuffer.size();
  ((CWorker *)ctx)->InputBuffer.resize(oldsize+length);
  evbuffer_remove(in_temp_buffer, &((CWorker *)ctx)->InputBuffer[oldsize], length);
  bufferevent_disable(connector, EV_READ);
  //wxMessageOutputDebug().Printf("Len2 %d bytes", (uint32)((CWorker *)ctx)->InputBuffer.size());
}

void CWorker::event(struct bufferevent *bev, short what, void *ctx)
{
  wxString msg=wxEmptyString;
  if (what & BEV_EVENT_EOF) {
    if (errno) {
      msg.Printf("error(%d): %s" , errno, strerror(errno));
    }
    msg.Printf("DISCONNECTED ("+msg+")");
    bufferevent_free(bev);
    isConnected=false;
    wxThreadEvent event(wxEVT_THREAD, frmMain::ID_THREAD_STATE);
    event.SetString(msg);
    event.SetInt(1);
    wxQueueEvent((wxEvtHandler *)((CWorker *)ctx)->pMain, event.Clone());
    event_del(((CWorker *)ctx)->tmKA);
  }
  else if (what & BEV_EVENT_ERROR) {
    if (errno) {
      msg.Printf("error (%d): %s" , errno, strerror(errno));
    }
    msg.Printf("DISCONNECTED ("+msg+")");
    bufferevent_free(bev);
    isConnected=false;
    wxThreadEvent event(wxEVT_THREAD, frmMain::ID_THREAD_STATE);
    event.SetString(msg);
    event.SetInt(1);
    wxQueueEvent((wxEvtHandler *)((CWorker *)ctx)->pMain, event.Clone());
    event_del(((CWorker *)ctx)->tmKA);
  }
  else if (what & BEV_EVENT_CONNECTED) {
    msg=wxT("CONNECTED");
    isConnected=true;
    ((CWorker *)ctx)->InputBuffer.clear();
    ((CWorker *)ctx)->OutputBuffer.clear();
    ((CWorker *)ctx)->dec.clear();
    ((CWorker *)ctx)->state=PREAUTH;
  }
//  wxMessageOutputDebug().Printf(msg);
  isTryConnect=false;
}

void CWorker::timeout(evutil_socket_t fd, short event, void *ctx)
{
  //wxMessageOutputDebug().Printf("OnTimeout");
  if (((CWorker*)ctx)->state!=AUTHED) {
    //wxMessageOutputDebug().Printf("Auth time out, disconnect!");
    ((CWorker*)ctx)->disconnect();
  }
  ((CWorker*)ctx)->KeepAliving();
}

void CWorker::Process()
{
  switch (state) {
    case PREAUTH:
      preauth();
      return;
    break;
    case AUTHING:
      auth();
      return;
    break;
  }

  uint32 uMessSize=0;

  bufferevent_enable(connector, EV_READ);
  //processing
  if (!InputBuffer.empty()) {

    MyDefaultBuffer cut, cur_dec;
    uint32 iLen=InputBuffer.size();

    iLen-=(iLen%16);
//    wxMessageOutputDebug().Printf("Len %d bytes", iLen);

    cur_dec.resize(iLen);

    std::copy(InputBuffer.begin(), InputBuffer.begin()+iLen, std::back_inserter(cut));
    InputBuffer.erase(InputBuffer.begin(), InputBuffer.begin()+iLen);

    crypt.Dec(&cut[0], iLen, &cur_dec[0], iLen);
    std::copy(cur_dec.begin(), cur_dec.begin()+iLen, std::back_inserter(dec));
    bufferevent_enable(connector, EV_READ);
  }

  if (!dec.empty()) {

    memcpy(&uMessSize, &dec[0], 2);
//    std::cout << "SS1=" << dec.size() << " SIZE=" << uMessSize << std::endl;

    if (uMessSize==0) {
      uMessSize=16;
      //wxMessageOutputDebug().Printf("VIT %d (%d): get keepalive",
      //  config->settings.vit_connectors.front().destination.node, iLocalId);
      ka_state=KA_RECV;
    }
    else {
      uMessSize+=2;         // прибавляем первые 2 байта
      if ((uMessSize)%16>0) {
        uMessSize+=16-(uMessSize)%16;
      }

      if (uMessSize>dec.size())
        return;

      CProto::VITHeader vth;
      std::fill((uint8 *)&vth, (uint8 *)&vth+sizeof(CProto::VITHeader), 0);
      std::copy(dec.begin()+2, dec.begin()+(2+sizeof(CProto::VITHeader)), (uint8 *)&vth);
/*
        wxMessageOutputDebug().Printf("SN=%d SI=%d DN=%d DI=%d SZ=%d\n"
               , vth.Source_NODE
               , vth.Source_INTERFACE
               , vth.Dest_NODE
               , vth.Dest_INTERFACE
               , vth.Size);
*/
      if (mClients.find(vth.Source_NODE)==mClients.end()) {
        wxMessageOutputDebug().Printf("VIT %d (%d): not find Node %d",
          config->settings.vit_connectors.front().destination.node, iLocalId, vth.Source_NODE);
      }
      else {
        MyDefaultBuffer answer;
        uint32 delta=0;
        if (vth.Source_INTERFACE==CProto::CONSOLE_INTERFACE_NUMBER)
          delta=10;

        std::copy(dec.begin()+(2+sizeof(CProto::VITHeader)+delta),
                  dec.begin()+(2+sizeof(CProto::VITHeader)+delta+(vth.Size-delta)),
                  std::back_inserter(answer));

        if (vth.Source_INTERFACE==CProto::ITF_CONFIG) {
          BuildXML(answer);
        }
        else if (vth.Source_INTERFACE==CProto::ITF_LIST_INTERFACE_NUMBER) {
          const char *p="REFRESH";
          answer.clear();
          std::copy(p, p+strlen(p), std::back_inserter(answer));
        }
        else if (vth.Source_INTERFACE==CProto::CONSOLE_INTERFACE_NUMBER) {
          uint16 uAnswer=0;
          memcpy(&uAnswer, &dec[2+sizeof(CProto::VITHeader)], 2);

          switch (uAnswer) {
            case EFILECMD::FILE_ANSWER:
            {
              const char *p="Good answer on query to send file!";
              answer.clear();
              std::copy(p, p+strlen(p), std::back_inserter(answer));
              sendContentFile(vth.Source_NODE, vth.Source_INTERFACE);
            }
            break;
            case EFILECMD::FILE_ERROR:
            {
              const char *p="Bad answer on query to send file!";
              answer.clear();
              std::copy(p, p+strlen(p), std::back_inserter(answer));
            }
            break;
            case EFILECMD::FILE_GOOD_TRANS:
            {
              const char *p="Config file was sended succefully!";
              answer.clear();
              std::copy(p, p+strlen(p), std::back_inserter(answer));
            }
            break;
          }
        }

        wxString out;
        for (MyDefaultBuffer::iterator it=answer.begin(); it!=answer.end(); ++it) {
          ((*it)=='\0') ? out+=' ' : out+=wxUniChar(*it);
        }

        wxThreadEvent event(wxEVT_THREAD, frmConsole::ID_OUT);
        event.SetInt(vth.Source_INTERFACE);
        event.SetString(out);
        //wxQueueEvent((wxEvtHandler *)mClients[vth.Source_NODE], event.Clone());
        ((wxEvtHandler *)mClients[vth.Source_NODE])->AddPendingEvent(event);
        //mClients[vth.Source_NODE](vth.Source_INTERFACE, out);
        answer.clear();
      }
    }
    dec.erase(dec.begin(), dec.begin()+uMessSize);
//    std::cout << "DEC SZ=" << dec.size() << std::endl;
  }
}

void CWorker::preauth()
{
  CProto::SPreAuthPacket ipacket;
  CProto::SPreAuthPacket opacket;
  std::vector<uint8> pkey;

  opacket.iNode=CConfig::getInstance()->settings.my_node;

  if (!InputBuffer.empty()) {
    //wxMessageOutputDebug().Printf("VIT %d: PreAuthorization", iLocalId);
    // Пытаемся понять с кем сконнектились
    //uint8* iit=(uint8 *)wxStrdup(InputBuffer.mb_str());
    std::copy(InputBuffer.begin(), InputBuffer.begin()+sizeof(ipacket), (uint8*)&ipacket);
    //wxMessageOutputDebug().Printf("VIT %d: Recv welcome from Node %d", iLocalId, ipacket.iNode);
    // Получили все данные с той стороны
    CCryptoKeyBase *cryptoBase=CCryptoKeyBase::getInstance();

    if (!cryptoBase->getKeyByNode(opacket.iNode, pkey)) {
      wxMessageOutputDebug().Printf("VIT %d: Can't find key by node %d", iLocalId, opacket.iNode);
      InputBuffer.clear();
      disconnect();
      return;
    }

    if (!crypt.importKey(opacket.iNode, &pkey[0], pkey.size())) {
      wxMessageOutputDebug().Printf("VIT %d: Can't load key by node %d", iLocalId, opacket.iNode);
      InputBuffer.clear();
      disconnect();
      return;
    }

    ps::getRand(sizeof(crypt.randClient), crypt.randClient);

    std::copy(crypt.scapVersion.begin(), crypt.scapVersion.end(), opacket.scapVersion);
    opacket.scapVersion[sizeof(opacket.scapVersion)-1]='\0';

    std::copy(ipacket.random, ipacket.random+sizeof(ipacket.random), crypt.randServer);
    std::copy(crypt.randClient, crypt.randClient+sizeof(crypt.randClient), opacket.random);
    std::copy(ipacket.random, ipacket.random+sizeof(ipacket.random), opacket.aux);

    aes_setkey_enc(&crypt.ctx, (const unsigned char * )crypt.keys_ap3_auth, 256);
    aes_crypt_ecb(&crypt.ctx, AES_ENCRYPT, (const unsigned char*)opacket.aux, (unsigned char *)opacket.aux);

    InputBuffer.clear();
    OutputBuffer.clear();
    OutputBuffer.resize(sizeof(opacket));
    std::copy((uint8 *)&opacket, (uint8 *)&opacket+sizeof(opacket), OutputBuffer.begin());
    //getOChannel()->getTail().lock()->OutputBuffer.SetSize(sizeof(opacket));
    Write(&OutputBuffer[0], OutputBuffer.size());
    state=AUTHING;

    setTimeout(config->settings.vit_connectors.front().keep_alive_send);
    bufferevent_enable(connector, EV_READ);
  }
}

void CWorker::auth()
{
  if (InputBuffer.empty())
    return;

  OutputBuffer.clear();
  //wxMessageOutputDebug().Printf("VIT %d: Authorization", iLocalId);
  uint8 *arBuffer=(uint8 *)&InputBuffer[0];

  uint8 key_ap3_auth_inv[CAesCrypter::uSizeKey];
  for (uint32 i=0; i<CAesCrypter::uSizeKey; i++) {
    key_ap3_auth_inv[i]=crypt.keys_ap3_auth[i]^0xFF;
  }

  aes_setkey_enc(&crypt.ctx, key_ap3_auth_inv, 256);
  aes_crypt_ecb(&crypt.ctx, AES_ENCRYPT, crypt.randClient, crypt.scap2_sess_key+0);
  aes_crypt_ecb(&crypt.ctx, AES_ENCRYPT, crypt.randServer, crypt.scap2_sess_key+16);

  uint8 rnd_cl_dec[16]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  aes_setkey_dec(&crypt.ctx, crypt.scap2_sess_key, 256);
  aes_crypt_ecb(&crypt.ctx, AES_DECRYPT, (const unsigned char*)arBuffer, rnd_cl_dec);

  if (memcmp(crypt.randClient, rnd_cl_dec, 16)!=0) {
    wxMessageOutputDebug().Printf("VIT %d: Error! Authentication failed: bad cryptogram", iLocalId);
    InputBuffer.clear();
    disconnect();
    return;
  }

  //wxMessageOutputDebug().Printf("VIT %d: Session key valid", iLocalId);
  aes_setkey_enc(&crypt.aes_enc, crypt.scap2_sess_key, 256);
  aes_setkey_dec(&crypt.aes_dec, crypt.scap2_sess_key, 256);

  std::fill(crypt.iv_enc, crypt.iv_enc+16, 0);
  std::fill(crypt.iv_dec, crypt.iv_dec+16, 0);

  uint32 mTimerKeepAlive=config->settings.vit_connectors.front().keep_alive_send;
  CProtocol::SCAP2_SESS_SETTINGS sc2ss={mTimerKeepAlive, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

  crypt.Enc((uint8 *)&sc2ss, sizeof(CProtocol::SCAP2_SESS_SETTINGS),
            (uint8 *)&sc2ss, sizeof(CProtocol::SCAP2_SESS_SETTINGS));

  OutputBuffer.clear();
  //OutputBuffer.reserve(sizeof(CProtocol::SCAP2_SESS_SETTINGS));
  std::copy((uint8 *)&sc2ss, (uint8 *)&sc2ss+sizeof(CProtocol::SCAP2_SESS_SETTINGS), std::back_inserter(OutputBuffer));
  //OutputBuffer.resize(sizeof(CProtocol::SCAP2_SESS_SETTINGS));

  Write(&OutputBuffer[0], OutputBuffer.size());
  state=AUTHED;
  ka_state=KA_NEED_SEND;

  setTimeout(2000);

  InputBuffer.clear();

  wxThreadEvent event(wxEVT_THREAD, frmMain::ID_THREAD_STATE);
  event.SetString("CONNECTED");
  event.SetInt(0);
  wxQueueEvent((wxEvtHandler *)pMain, event.Clone());
  bufferevent_enable(connector, EV_READ);
}

void CWorker::disconnect()
{
  evutil_make_socket_closeonexec(bufferevent_getfd(connector));
  bufferevent_free(connector);
}

bool CWorker::Write(uint8 *arBuffer, uint32 arLength)
{
  struct evbuffer *dst;

  dst=bufferevent_get_output(connector);
  if (evbuffer_add(dst, arBuffer, arLength)<0) {
    //wxMessageOutputDebug().Printf("evbuffer_add return -1");
  }
  //wxMessageOutputDebug().Printf("VIT %d (%d): write %d bytes",
  //  config->settings.vit_connectors.front().destination.node, iLocalId, arLength);

  return true;
}

void CWorker::setTimeout(uint32 arTimeout)
{
  if (!arTimeout)
    return;

  struct timeval tv;
  evutil_timerclear(&tv);
  tv.tv_sec=arTimeout/1000;
  tv.tv_usec=arTimeout%1000;
  event_del(tmKA);
  event_add(tmKA, &tv);
}

void CWorker::RegisterNode(frmConsole *arConsole, uint32 arNode)
{
  if (wxMutexLocker(mutex).IsOk()) {
    std::map<uint32, frmConsole *>::iterator it=mClients.find(arNode);
    if (it!=mClients.end()) {
      mClients.erase(arNode);
    }

    mClients.insert(std::make_pair(arNode, arConsole));
    //wxMessageOutputDebug().Printf("VIT %d: Register node %d", iLocalId, arNode);
  }
}

void CWorker::UnregisterNode(uint32 arNode)
{
  if (wxMutexLocker(mutex).IsOk()) {
    std::map<uint32, frmConsole *>::iterator it=mClients.find(arNode);
    if (it!=mClients.end()) {
      mClients.erase(arNode);
      //wxMessageOutputDebug().Printf("VIT %d: Unregister node %d", iLocalId, arNode);
    }
  }
}

void CWorker::sendContentFile(uint32 arNode, uint32 arInterface)
{
  std::ifstream fConfigFile;
  MyDefaultBuffer cmd(10, 0), file;

	fConfigFile.open(lastConfigFilePath, std::fstream::binary);
	if (!fConfigFile.is_open()) {
		throw "Error. Config not found 1";
	}

  uint16 uSize=0;
  fConfigFile.seekg(0, std::ios::end);
  uSize=fConfigFile.tellg();
  fConfigFile.seekg(0);
  file.resize(uSize);
  fConfigFile.read((char *)&file[0], uSize);
  fConfigFile.close();

  uint16 c=CWorker::EFILECMD::FILE_TRANSFER;

  memcpy(&cmd[0], &c, 2);
  memcpy(&cmd[6], &uSize, 2);
  cmd[8]=57;
  cmd[9]=86;

  std::copy(lastConfigFileName.begin(), lastConfigFileName.end(), std::back_inserter(cmd));
  cmd.push_back('\0');
  std::copy(file.begin(), file.end(), std::back_inserter(cmd));
  SendCommand(arNode, arInterface, cmd);
}

void CWorker::SendFile(uint32 arNode, uint32 arInterface,
                std::string& arFullPath, std::string& arFileName)
{
  lastConfigFileName=arFileName;
  lastConfigFilePath=arFullPath;

  std::ifstream fConfigFile;

	fConfigFile.open(lastConfigFilePath, std::fstream::binary);
	if (!fConfigFile.is_open()) {
		throw "Error. Config not found 1";
	}

  uint16 uSize=0;
  fConfigFile.seekg(0, std::ios::end);
  uSize=fConfigFile.tellg();
  fConfigFile.seekg(0);
  fConfigFile.close();

  MyDefaultBuffer cmd(10, 0);
  uint16 c=CWorker::EFILECMD::FILE_QUERY;

  memcpy(&cmd[0], &c, 2);
  memcpy(&cmd[2], &uSize, 2);
  cmd[6]=155;
  cmd[7]=121;
  cmd[8]=231;
  cmd[9]=219;

  std::copy(lastConfigFileName.begin(), lastConfigFileName.end(), std::back_inserter(cmd));
  SendCommand(arNode, arInterface, cmd);
}

void CWorker::SendCommand(uint32 arNode, uint32 arInterface, MyDefaultBuffer &arCommand)
{
  CProto::VITHeader vHeader;
  uint32 l=2+20+sizeof(vHeader)+arCommand.size();
  if ((l%16)>0) {
    l+=16-l%16;
  }

  // Пакуем
  MyDefaultBuffer packet(l, 0);
  uint8 *p=&packet[0];
  uint8 *b=p;

  vHeader.Dest_NODE=arNode;
  vHeader.Dest_INTERFACE=arInterface;

  vHeader.Source_NODE=CConfig::getInstance()->settings.my_node;
  vHeader.Source_INTERFACE=arInterface;

  uint32 msg_size=0;
  vHeader.Size=arCommand.size();
  msg_size=sizeof(CProto::VITHeader)+(arCommand.size())+20;

  memcpy(p, &msg_size, 2);
  p+=2;

  uint8 *h=(uint8 *)&vHeader;
  std::copy(h, h+sizeof(CProto::VITHeader), p);
  p+=sizeof(CProto::VITHeader);

  std::copy(arCommand.begin(), arCommand.end(), p);
  p+=(arCommand.size());

  proto.Sign(b, 2+sizeof(CProto::VITHeader)+vHeader.Size);
  //unsigned long crc=crc32buffer(b, 2+sizeof(CProto::VITHeader)+vHeader.Size);
  //memcpy((unsigned char *)&b[2+sizeof(CProto::VITHeader)+vHeader.Size], &crc, sizeof(crc));
  p+=20;

  crypt.Enc(b, l, b, l);
  Write(b, l);
}

void CWorker::addNode(pugi::xml_node *arParent,
                      MyDefaultBuffer::iterator &arI,
                      uint32 arSize, const char *arName)
{
  std::string sElemValue="";
  std::copy(++arI, arI+(arSize), std::back_inserter(sElemValue));

//  std::for_each(arI, arI+(arSize-1),
//                std::tr1::bind(&CWorker::put, this, sElemValue, std::tr1::placeholders::_1));

//  std::cout << sElemValue << std::endl;

  pugi::xml_node node=arParent->append_child();
  node.set_name(arName);
  node.append_child(pugi::node_pcdata).set_value(sElemValue.c_str());
}

void CWorker::BuildXML(MyDefaultBuffer &arOut)
{
  uint32 uElemLen=0;

  pugi::xml_document doc;
  std::ostringstream ss;

  doc.append_child().set_name("configuration");
  pugi::xml_node configuration=doc.child("configuration");

  configuration.append_child().set_name("general");
  configuration.append_child().set_name("gprs");
  configuration.append_child().set_name("server");
  configuration.append_child().set_name("vip");
  configuration.append_child().set_name("scripts");
  configuration.append_child().set_name("serialport");
  configuration.append_child().set_name("ethernet");
  configuration.append_child().set_name("virtualchannels");



  pugi::xml_node general=configuration.child("general");
  pugi::xml_node gprs=configuration.child("gprs");
  pugi::xml_node server=configuration.child("server");
  pugi::xml_node vip=configuration.child("vip");
  pugi::xml_node scripts=configuration.child("scripts");
  pugi::xml_node serialport=configuration.child("serialport");
  pugi::xml_node ethernet=configuration.child("ethernet");
  ethernet.append_child().set_name("sockets");
  pugi::xml_node sockets=ethernet.child("sockets");
  pugi::xml_node virtualchannels=configuration.child("virtualchannels");

  pugi::xml_node row;

  //ss << "<configuration>\n";
  for (MyDefaultBuffer::iterator it=arOut.begin(); it!=arOut.end(); ++it) {
    if ((uint32)(*it)==0 && (uint32)(*(it+1))==127) {
      uElemLen=(uint32)*(++(++it));
      addNode(&configuration, ++it, --uElemLen, "version");
    }
    else if ((*it)==1 && (*(it+1))==127) {
      uElemLen=(uint32)*(++(++it));
      addNode(&configuration, ++it, --uElemLen, "modify");
      it+=uElemLen;
    }
/*****************************GENERAL******************************************/
    else if ((*it)==100 && (*(it+1))==0) {
      //printf("100\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "ip_conn_timeout");
      it+=uElemLen-1;
    }
    else if ((*it)==110 && (*(it+1))==0) {
      //printf("110\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "gprs_conn_timeout");
      it+=uElemLen-1;
    }
    else if ((*it)==120 && (*(it+1))==0) {
      //printf("120\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "max_ip_pwrup_delay");
      it+=uElemLen-1;
    }
    else if ((*it)==130 && (*(it+1))==0) {
      //printf("130\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "csq_min_value");
      it+=uElemLen-1;
    }
    else if ((*it)==140 && (*(it+1))==0) {
      //printf("140\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "ip_packet_max_len");
      it+=uElemLen-1;
    }
    else if ((*it)==150 && (*(it+1))==0) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "trace_answer");
      it+=uElemLen-1;
    }
    else if ((*it)==160 && (*(it+1))==0) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "debug");
      it+=uElemLen-1;
    }
    else if ((*it)==170 && (*(it+1))==0) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&serialport, ++it, uElemLen, "baudrate");
      it+=uElemLen-1;
    }
    else if ((*it)==171 && (*(it+1))==0) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&serialport, ++it, uElemLen, "flow_control");
      it+=uElemLen-1;
    }
    else if ((*it)==180 && (*(it+1))==0) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&general, ++it, uElemLen, "channel_priority");
      it+=uElemLen-1;
    }
/*****************************GPRS******************************************/
    else if ((*it)==177 && (*(it+1))==4) {
      row=gprs.append_child("row");
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "operator_id");
      it+=uElemLen-1;
    }
    else if ((*it)==178 && (*(it+1))==4) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "username");
      it+=uElemLen-1;
    }
    else if ((*it)==179 && (*(it+1))==4) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "password");
      it+=uElemLen-1;
    }
    else if ((*it)==180 && (*(it+1))==4) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "apn");
      it+=uElemLen-1;
    }
    else if ((*it)==181 && (*(it+1))==4) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "auto_disconnect");
      it+=uElemLen-1;
    }
/*****************************SERVER******************************************/
    else if ((*it)==21 && (*(it+1))==5) {
      row=server.append_child("row");
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_node");
      it+=uElemLen-1;
    }
    else if ((*it)==22 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_ip");
      it+=uElemLen-1;
    }
    else if ((*it)==23 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_port");
      it+=uElemLen-1;
    }
    else if ((*it)==24 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "ka_send");
      it+=uElemLen-1;
    }
    else if ((*it)==25 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "ka_recv");
      it+=uElemLen-1;
    }
/*****************************VIP******************************************/
    else if ((*it)==121 && (*(it+1))==5) {
      row=vip.append_child("row");
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_node");
      it+=uElemLen-1;
    }
    else if ((*it)==122 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_itf");
      it+=uElemLen-1;
    }
    else if ((*it)==123 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "flags");
      it+=uElemLen-1;
    }
    else if ((*it)==124 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "ka_send");
      it+=uElemLen-1;
    }
    else if ((*it)==125 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "ka_recv");
      it+=uElemLen-1;
    }
    else if ((*it)==126 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "idle_time");
      it+=uElemLen-1;
    }
    else if ((*it)==127 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "connect_timeout");
      it+=uElemLen-1;
    }
    else if ((*it)==128 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "connection_time");
      it+=uElemLen-1;
    }
    else if ((*it)==129 && (*(it+1))==5) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "reserve_host");
      it+=uElemLen-1;
    }
/*****************************ETHERNET******************************************/
    else if ((*it)==65 && (*(it+1))==6) {
      row=ethernet.append_child("row");

      uint32 uId=(uint32)*(it-4);
      pugi::xml_node node=row.append_child();
      node.set_name("id");
      node.append_child(pugi::node_pcdata).set_value(ps::IntToStr(uId).c_str());

      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "mac");
      it+=uElemLen-1;
    }
    else if ((*it)==66 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "ip");
      it+=uElemLen-1;
    }
    else if ((*it)==67 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "mask");
      it+=uElemLen-1;
    }
    else if ((*it)==68 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "gateway");
      it+=uElemLen-1;
    }
/*****************************SOCKETS******************************************/
    else if ((*it)==165 && (*(it+1))==6) {
      row=sockets.append_child("row");
      //printf("150\n");
      uint32 uId=(uint32)*(it-4);
      pugi::xml_node node=row.append_child();
      node.set_name("id");
      node.append_child(pugi::node_pcdata).set_value(ps::IntToStr(uId).c_str());
      uElemLen=(uint32)*(++(++it));

      addNode(&row, ++it, uElemLen, "type");
      it+=uElemLen-1;
    }
    else if ((*it)==166 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "dest_ip");
      it+=uElemLen-1;
    }
    else if ((*it)==167 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "dst_port");
      it+=uElemLen-1;
    }
    else if ((*it)==168 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "ndc");
      it+=uElemLen-1;
    }
    else if ((*it)==169 && (*(it+1))==6) {
      //printf("150\n");
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "local_port");
      it+=uElemLen-1;
    }
/*****************************SCRIPTS******************************************/
    else if ((*it)==221 && (*(it+1))==5) {
      row=scripts.append_child("row");
      //printf("150\n");
      uint32 uId=(uint32)*(it-4);
      pugi::xml_node node=row.append_child();
      node.set_name("id");
      node.append_child(pugi::node_pcdata).set_value(ps::IntToStr(uId).c_str());

      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "value");
      it+=uElemLen-1;
    }
/*****************************VCH******************************************/
    else if ((*it)==9 && (*(it+1))==7) {
      row=virtualchannels.append_child("row");
      //printf("150\n");
      uint32 uId=(uint32)*(it-4);
      pugi::xml_node node=row.append_child();
      node.set_name("id");
      node.append_child(pugi::node_pcdata).set_value(ps::IntToStr(uId+1).c_str());

      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "mode");
      it+=uElemLen-1;
    }
    else if ((*it)==10 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "work_mode");
      it+=uElemLen-1;
    }
    else if ((*it)==11 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "script_number");
      it+=uElemLen-1;
    }
    else if ((*it)==12 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "vip_number");
      it+=uElemLen-1;
    }
    else if ((*it)==13 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_serial_port");
      it+=uElemLen-1;
    }
    else if ((*it)==14 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_0");
      it+=uElemLen-1;
    }
    else if ((*it)==15 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_1");
      it+=uElemLen-1;
    }
    else if ((*it)==16 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_2");
      it+=uElemLen-1;
    }
    else if ((*it)==17 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_3");
      it+=uElemLen-1;
    }
    else if ((*it)==18 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_4");
      it+=uElemLen-1;
    }
    else if ((*it)==19 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_5");
      it+=uElemLen-1;
    }
    else if ((*it)==20 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_6");
      it+=uElemLen-1;
    }
    else if ((*it)==21 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "itf_mask_sock_7");
      it+=uElemLen-1;
    }
    else if ((*it)==22 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "dp_mode");
      it+=uElemLen-1;
    }
    else if ((*it)==23 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "dp_window_size");
      it+=uElemLen-1;
    }
    else if ((*it)==24 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "dp_retry_count");
      it+=uElemLen-1;
    }
    else if ((*it)==25 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "dp_retry_timeout");
      it+=uElemLen-1;
    }
    else if ((*it)==26 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "relay_control");
      it+=uElemLen-1;
    }
    else if ((*it)==27 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "relay_timeout");
      it+=uElemLen-1;
    }
    else if ((*it)==28 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_interface");
      it+=uElemLen-1;
    }
    else if ((*it)==29 && (*(it+1))==7) {
      uElemLen=(uint32)*(++(++it));
      addNode(&row, ++it, uElemLen, "server_pch");
      it+=uElemLen-1;
    }
  }
  //ss << "</configuration>\n";
  doc.save(ss);

  arOut.clear();
  std::string xml(ss.str());

  //std::cout << "LEN=" << xml.size() << std::endl;
  //std::cout << xml << std::endl;

  std::copy(xml.begin(), xml.end(), std::back_inserter(arOut));
}





