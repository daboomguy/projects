/*
 * File:   CAesCrypter.h
 * Author: mikhail
 *
 * Created on 28 Ноябрь 2011 г., 11:18
 */

#ifndef _CAESCRYPTER_H
#define	_CAESCRYPTER_H

#include "typenix.h"
#include "alldefine.h"
#include "aes.h"
#include <cstdlib>
#include <string>
#include <typeinfo>
#include "ibuffer.h"
#include <iterator>


using namespace std;

class CAesCrypter : public BufferInterface {
public:
  std::string scapVersion;
  uint8 importKey(uint32 arNode, uint8 *arKey, uint32 arKeySize);
  static const uint32 uSizeKey=32;

	aes_context ctx;
  aes_context aes_enc;
	aes_context aes_dec;

  uint32 uCut;
  uint32 uPut;

  uint8	scap2_sess_key[uSizeKey];
	uint8 keys_ap3_auth[uSizeKey];

  uint8	iv_enc[16];
	uint8	iv_dec[16];

	uint8 randServer[16];
	uint8 randClient[16];

  CAesCrypter() : BufferInterface(), scapVersion("SCAP v2.1 "),
                  ctx(), aes_enc(), aes_dec(), uCut(16), uPut(16)
                  {
    //logsave("CAesCrypter() create");
    //InputBuffer.setName("CAesCrypter");
    //OutputBuffer.setName("CAesCrypter");
  }

  CAesCrypter(const CAesCrypter &temp) {
    DeepCopy(&temp);
  }

  const CAesCrypter &operator=(const CAesCrypter &temp) {
    DeepCopy(&temp);
    return *this;
  }

  void DeepCopy(const CAesCrypter *temp) {
    scapVersion.assign(temp->scapVersion);
  	ctx=temp->ctx;
    aes_enc=temp->aes_enc;
    aes_dec=temp->aes_dec;
    std::copy(temp->scap2_sess_key, temp->scap2_sess_key+uSizeKey, scap2_sess_key);
    std::copy(temp->keys_ap3_auth, temp->keys_ap3_auth+uSizeKey, keys_ap3_auth);

    std::copy(temp->iv_enc, temp->iv_enc+16, iv_enc);
    std::copy(temp->iv_dec, temp->iv_dec+16, iv_dec);

    std::copy(temp->randServer, temp->randServer+16, randServer);
    std::copy(temp->randClient, temp->randClient+16, randClient);

    //InputBuffer.setName("CAesCrypter");
    //OutputBuffer.setName("CAesCrypter");
  }


  virtual ~CAesCrypter() { /*logsave("~CAesCrypter() delete");*/ };
  uint32 Enc(uint8 *arSrc, uint32 arSrcSize, uint8 *arDst, uint32 arDstSize);
  uint32 Dec(uint8 *arSrc, uint32 arSrcSize, uint8 *arDst, uint32 arDstSize);
  void ClearEncVars();

  void Cut(uint32 arSize) {
    //logsave("AES: set CUT %d", arSize);
    uCut=arSize;
  }

  void Put(uint32 arSize) {
    //logsave("AES: set PUT %d", arSize);
    uPut=arSize;
  }
/*
  template<class B> friend CAesCrypter *operator>>(B &arInput, CAesCrypter *obj) {
    if (arInput.InputBuffer.empty() || arInput.InputBuffer.size()<16)
      return obj;

    uint32 iLen=arInput.InputBuffer.size();
    //logsave("AesCrypter: %d size", iLen);

    if (!obj->InputBuffer.empty())
      obj->InputBuffer.clear();

    iLen-=(iLen%16);
    if (obj->uCut!=0 && iLen>obj->uCut)
      iLen=obj->uCut;

    //logsave("AesCrypter: cut %d size", iLen);
    MyDefaultBuffer temp;
    temp.reserve(iLen)
    std::copy(arInput.InputBuffer.begin(), arInput.InputBuffer.begin()+iLen, temp.begin());
    temp.SetSize(iLen);

    // Распаковываем в темповый буффер чтоб вычислить длину пакета
    if (!obj->Dec(temp.begin(), iLen, obj->InputBuffer.begin(), iLen))
      throw "can't decode";

    obj->InputBuffer.SetSize(iLen);

    arInput.InputBuffer.MoveLeft(iLen);
    return obj;
  }

  template<class B> friend CAesCrypter & operator << (B &arInput, CAesCrypter & obj) {
    uint32 iLen=arInput.OutputBuffer.size();
    if (!obj.OutputBuffer.empty())
      obj.OutputBuffer.clear();

    if (iLen>obj.uPut) {
      iLen=obj.uPut-obj.uPut%16;
      //logsave("crypt (1) ILEN %d", iLen);
    }
    else {
      if ((iLen%16)>0) {
        iLen+=16-iLen%16;
      }
    }

    //logsave("crypt (2) ILEN %d", iLen);
    if (iLen>obj.OutputBuffer.capacity())
      iLen-=(obj.OutputBuffer.capacity()%16);

    //logsave("crypt (3) ILEN %d", iLen);


    if (!obj.Enc(arInput.OutputBuffer.begin(), iLen, obj.OutputBuffer.begin(), iLen))
      throw "can't decode";

    obj.OutputBuffer.SetSize(iLen);

    arInput.OutputBuffer.MoveLeft(iLen);
    iLen=arInput.OutputBuffer.size();
    //logsave("crypt (5) ILEN %d", iLen);

    return obj;
  }
*/
};

#endif	/* _CAESCRYPTER_H */

