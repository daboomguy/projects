#ifndef _CRC32_H_INCLUDED
#define _CRC32_H_INCLUDED

#include "pstype.h"


#define UPDC32(octet, crc) (crc_32_tab[((crc) ^ (octet)) & 0xff] ^ ((crc) >> 8))


uint32 crc32buffer(const uint8 *arBuffer, int arLen);



#endif

