#ifndef CWORKER_H
#define CWORKER_H

#include <wx/thread.h>
#include <wx/string.h>
#include <wx/event.h>
#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif

#include <event2/bufferevent_ssl.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>

#include "config.h"
#include "CAesCrypter.h"
#include "CProtocol.h"
#include "CCryptoKeyBase.h"
#include "frmConsole.h"

#include <map>
#include <sstream>


class frmMain;
class CWorker : public wxThread , public BufferInterface
{

  void put(std::string& arBuffer, uint8 arC) {
    printf(">%d\n", arC);
    if (arC!=0) {
      arBuffer.append(1, arC);
    }
  }

  std::map<uint32, frmConsole *> mClients;

  enum {
    PREAUTH=0,
    AUTHING,
    AUTHED
  };

  enum {
    KA_SEND=0,
    KA_NEED_SEND,
    KA_RECV
  };

  std::string lastConfigFileName;
  std::string lastConfigFilePath;


  wxMutex mutex;

  struct event *tmKA;
  frmMain *pMain;

  CConfig *config;
  CCryptoKeyBase *crybase;

  uint32 state;
  uint32 ka_state;

  uint32 authTimer;
  uint32 iLocalId;
  uint32 iRemoteId;
  uint32 iLastNode;


  CProtocol proto;
  CAesCrypter crypt;
  MyDefaultBuffer dec;

  void KeepAliving();
  void Process();
  void preauth();
  void auth();

  void setTimeout(uint32 arTimeout);
  static bool isConnected;
  static bool isTryConnect;

  static struct bufferevent *connector;

  static void read(struct bufferevent *bev, void *ctx);
  static void event(struct bufferevent *bev, short what, void *ctx);
  static void timeout(evutil_socket_t fd, short event, void *ctx);


  void connect(wxString IpPort);
  void disconnect();
  bool Write(uint8 *arBuffer, uint32 arLength);
  void BuildXML(MyDefaultBuffer &arOut);
  void addNode(pugi::xml_node *arParent,
               MyDefaultBuffer::iterator &arI,
               uint32 arSize, const char *arName);

  void sendContentFile(uint32 arNode, uint32 arInterface);
  void OnAction(uint32 arInterface, wxString &arStr);

 public:
  enum EFILECMD {
    FILE_QUERY=510,
    FILE_ANSWER=520,
    FILE_TRANSFER=530,
    FILE_ERROR=540,
    FILE_GOOD_TRANS=550
  };

  CWorker(frmMain *arMain, const char *arConfigPath);
  virtual ~CWorker();

  virtual void *Entry();
  virtual void OnExit() {}

//	void RegisterNode(Action &arConsole, uint32 arNode);
	void RegisterNode(frmConsole *arConsole, uint32 arNode);

  void UnregisterNode(uint32 arNode);
  void SendCommand(uint32 arNode, uint32 arInterface, MyDefaultBuffer& arCommand);
  void SendFile(uint32 arNode, uint32 arInterface,
                std::string& arFullPath, std::string& arFileName);
};

#endif // CWORKER_H
