/*
 * File:   CProtocol.cpp
 * Author: buzz
 *
 * Created on 28 Ноябрь 2011 г., 21:32
 */

#include "CProtocol.h"
#include "crc32.h"
#include <iterator>
#include "sha1.h"
#include "config.h"
#include <wx/msgout.h>

const uint8 CProto::uDUTTypeasText[][16]={
	"ORDINARY", "BOTS", "EOTS", "FOTS", "KEEPALIVE", "CONFIRMATION", "BUSY"
};


uint32 CProtocol::Pack(uint8 *arSrc, uint32 arLength)
{
  uint32 ddhaSize=sizeof(struct CProto::TDinamicDUTHeaderAddition);

  if ((ddhaOut.Type & 0x00000100) || (ddhaOut.Type==CProto::DDHT_BOTS))
    ddhaSize=sizeof(struct CProto::TDinamicDUTHeaderAddition2);

  header.Size=ddhaSize+arLength;

  uint32 uPacketSize=sizeof(VITHeader)+header.Size+20; //20 bytes SIGN
  //logsave("uPacketSize=%d", uPacketSize);
  //if (uPacketNumber>65000)
  //  uPacketNumber=0;

  //ddhaOut.cX1=++uPacketNumber;

  uint8 *pos=&InputBuffer[0];

  uint8 uSize[2];
  uSize[0]=Lo(uPacketSize);
  uSize[1]=Hi(uPacketSize);

  std::copy(uSize, uSize+sizeof(uSize), pos);
  pos+=sizeof(uSize);

  uint8 *p=(uint8 *)&(header);
  std::copy(p, p+sizeof(VITHeader), pos);
  pos+=sizeof(VITHeader);

  p=(uint8 *)&(ddhaOut);
  std::copy(p, p+ddhaSize, pos);
  pos+=ddhaSize;

  if (arLength>0) {
    std::copy(arSrc, arSrc+arLength, pos);
    pos+=arLength;
  }

  uint8 bb[20];
  std::fill(bb, bb+sizeof(bb)/sizeof(bb[0]), 0);

  unsigned long crc=crc32buffer((unsigned char *)&InputBuffer[0], pos-(&InputBuffer[0]));
  //logsave("PACK: crc %lld %d", crc, pos-InputBuffer.begin());
  memcpy(bb, &crc, sizeof(crc));

  std::copy(bb, bb+sizeof(bb)/sizeof(bb[0]), pos);
  pos+=sizeof(bb)/sizeof(bb[0]);

  InputBuffer.resize(pos-(&InputBuffer[0]));

  wxMessageOutputDebug().Printf("packed %d bytes", (uint32)InputBuffer.size());
	return InputBuffer.size();
}

uint32 CProtocol::UnPack(uint8 *arSrc, uint32 arLength)
{
  uint32 ddhaSize=sizeof(struct CProto::TDinamicDUTHeaderAddition);
  CProto::VITHeader hh;
  std::copy(arSrc+2, arSrc+(2+sizeof(CProto::VITHeader)), (uint8 *)&hh);

  if (header.Dest_NODE==0) {
    header.Dest_NODE=hh.Source_NODE;
  }

  if (header.Dest_INTERFACE==0) {
    header.Dest_INTERFACE=hh.Source_INTERFACE;
  }

  std::copy(arSrc+(2+sizeof(CProto::VITHeader)), arSrc+(2+sizeof(CProto::VITHeader)+ddhaSize), (uint8 *)&ddhaIn);

  if ((ddhaIn.Type & 0x00000100) || ddhaIn.Type==CProto::DDHT_BOTS) {
    ddhaSize=sizeof(struct CProto::TDinamicDUTHeaderAddition2);
    std::copy(arSrc+(2+sizeof(CProto::VITHeader)), arSrc+(2+sizeof(CProto::VITHeader)+ddhaSize), (uint8 *)&ddhaIn);
    ddhaIn.Type&=0x00000011;
    //ddhaIn.Type|=0x00000100;
  }

  if (!OutputBuffer.empty())
    OutputBuffer.clear();

  unsigned long crc=0, crc1=0;
  uint32 msg_size=0, LenMess=0;
  memcpy(&msg_size, &arSrc[0], 2);

  memcpy(&crc1, &arSrc[msg_size-20+2], sizeof(crc1));
  /*
  if (CConfig::getInstance()->IsManageInterface(header.Dest_INTERFACE)) {
    uint8 hash[20]={0};
    sha1::calc(arSrc, msg_size-20+2, hash);
    memcpy(&crc, hash, sizeof(crc));
  }
  else*/
    crc=crc32buffer(&arSrc[0], msg_size-20+2);
  //logsave("UNPACK: crc %lld==%lld %d", crc, crc1, msg_size-20+2);

	if (crc1!=crc) {
    wxMessageOutputDebug().Printf("SERVER: Error! Bad message sign!");
    throw "SERVER: Error! Bad message sign!";
  }

  uint32 uOffSet=2+sizeof(VITHeader)+ddhaSize;
  if (hh.Size>ddhaSize) {
    LenMess=hh.Size-ddhaSize;
  }
  else {
    LenMess=msg_size-(sizeof(VITHeader)+ddhaSize+20);
  }

  if (LenMess>0) {
    std::copy(arSrc+uOffSet, arSrc+(uOffSet+LenMess), OutputBuffer.begin());
  }
/*
  if (CConfig::getInstance()->settings.dump) {
    std::copy(OutputBuffer.begin(), OutputBuffer.end(), std::ostream_iterator<uint32>(std::cout, " "));
    std::cout << std::endl;
  }
  */

  OutputBuffer.resize(LenMess);
//  logsave("CProtocol: unpacked %d bytes", LenMess);
	return LenMess;
}

void CProtocol::Sign(uint8 *arSrc, uint32 arLength)
{
  uint8 hash[20];
  CProto::VITHeader hh;
  std::copy(arSrc+2, arSrc+(2+sizeof(CProto::VITHeader)), (uint8 *)&hh);

  sha1::calc(arSrc, 2+sizeof(VITHeader)+hh.Size, hash);
  std::copy(hash, hash+20, arSrc+(2+sizeof(VITHeader)+hh.Size));
}
