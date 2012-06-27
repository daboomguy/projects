/*
 * File:   CAesCrypter.cpp
 * Author: mikhail
 *
 * Created on 28 Ноябрь 2011 г., 11:18
 */
#include "CAesCrypter.h"
#include "alldefine.h"
#include "crc32.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string.h>
#include "myfunc.h"
//--------------------------------------------------------------------------------------------
uint8 CAesCrypter::importKey(uint32 arNode, uint8 *arKey, uint32 arKeySize)
{
	uint32 crc, crc1;
	uint8	aesIV[16] = {0};
	uint8	uKeysd[100];

	// Ключ шифрования базы (шифруется отдельно каждый ключ).
	uint8	uAesKey[] = {
		0x9d, 0xce, 0xd1, 0xbe, 0x3a, 0xcc, 0xa4, 0x92,
		0x53, 0xe8, 0x91, 0x5e, 0xce, 0x40, 0x96, 0x12,
		0x0b, 0x7b, 0xcc, 0x34, 0x86, 0xc7, 0x8d, 0x3b,
		0xa3, 0x66, 0x21, 0x2b, 0x59, 0xb0, 0x1f, 0x5e
	};

	uAesKey[0]	^= (arNode >> 0x00) & 0xFF;
	uAesKey[8]	^= (arNode >> 0x08) & 0xFF;
	uAesKey[16]	^= (arNode >> 0x10) & 0xFF;
	uAesKey[24]	^= (arNode >> 0x18) & 0xFF;

	aes_setkey_dec(&ctx, uAesKey, 256);
	aes_crypt_cbc(&ctx, AES_DECRYPT, arKeySize, aesIV, arKey, uKeysd);

	crc=crc32buffer(uKeysd, 68);

	memcpy(&crc1, &uKeysd[68], sizeof(crc1));
	if (crc != crc1) {
//		logsave("File corrupted (bad crc).");
		return 0;
	}


	memcpy(&crc1, &uKeysd[64], sizeof(crc1));
	if (arNode != crc1) {
//		logsave("File corrupted (node mismatch).");
		return 0;
	}

	memcpy(keys_ap3_auth, &uKeysd[32], uSizeKey);

	return 1;
}
//--------------------------------------------------------------------------------------------
uint32 CAesCrypter::Enc(uint8 *arSrc, uint32 arSrcSize, uint8 *arDst, uint32 arDstSize)
{
  if (arSrcSize>arDstSize)
    return 0;

  aes_crypt_cbc(&aes_enc, AES_ENCRYPT, arSrcSize, iv_enc, arSrc, arDst);
  return 1;
}
//--------------------------------------------------------------------------------------------
uint32 CAesCrypter::Dec(uint8 *arSrc, uint32 arSrcSize, uint8 *arDst, uint32 arDstSize)
{
  if (arSrcSize>arDstSize)
    return 0;

  if ((arSrcSize%16) > 0)
    arSrcSize+=16-arSrcSize%16;

  aes_crypt_cbc(&aes_dec, AES_DECRYPT, arSrcSize, iv_dec, arSrc, arDst);
  return 1;
}
//--------------------------------------------------------------------------------------------
void CAesCrypter::ClearEncVars()
{
  std::fill(iv_enc, iv_enc+sizeof(iv_enc), '\0');
  std::fill(iv_dec, iv_dec+sizeof(iv_dec), '\0');
  std::fill(randServer, randServer+sizeof(randServer), '\0');
  std::fill(randClient, randClient+sizeof(randClient), '\0');
}
//--------------------------------------------------------------------------------------------
