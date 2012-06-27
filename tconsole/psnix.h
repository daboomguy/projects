#ifndef PSNIX_H
#define PSNIX_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <stdlib.h>
#include <memory.h>
#include "typenix.h"
#include <netinet/tcp.h>

#define PS_SHUTDOWN_RECEIVE	0
#define PS_SHUTDOWN_SEND	1
#define PS_SHUTDOWN_BOTH	2

#define PS_INVALID_SOCKET	-1
#define PS_SOCKET_ERROR		-1

#define PS_EAGAIN			EAGAIN
#ifdef EINPROGRESS
#define PS_EINPROGRESS		EINPROGRESS
#else
#define PS_EINPROGRESS		EAGAIN
#endif
#define PS_ENOTTY			ENOTTY

typedef struct sockaddr_in	PS_SOCKADDR_IN;
typedef int					PS_SOCKET;

typedef struct PS_INFO { sint16 dummy; } PS_INFO;

typedef hostent*			PS_LPHOSTENT;
// --------------

void				PSInit(PS_INFO *arInfo);
sint16				PSStartUp(PS_INFO *arInfo);
PS_LPHOSTENT			PSGetHostByName(const char *arHostName);
void				PSNonBlock(PS_SOCKET arSocket);
void				PSKeepAlive(PS_SOCKET arSocket, uint32 arKATime, uint32 arKAInterval, uint32 arKAProbes);
void				PSFillAddrIn(PS_SOCKADDR_IN *arAddrIn, PS_LPHOSTENT arHostEnt, uint16 arPort);
void				PSFillAddrIn(PS_SOCKADDR_IN *arAddrIn, uint32 arAddr, uint16 arPort);
sint16				PSConnect(PS_SOCKET arSocket, PS_SOCKADDR_IN *arAddrIn, uint16 arAddrSize);
sint16				PSBind(PS_SOCKET arSocket, PS_SOCKADDR_IN *arAddrIn, uint16 arAddrSize);
sint16				PSList(PS_SOCKET arSocket);
PS_SOCKET			PSAccept(PS_SOCKET arSocket, PS_SOCKADDR_IN *arAddrIn, int *arAddrSize);
sint16				PSRecv(PS_SOCKET arSocket, uint8 *arBuffer, uint16 arSize);
sint16				PSRecvFrom(PS_SOCKET arSocket, uint8 *arBuffer, uint16 arSize, PS_SOCKADDR_IN *arAddrIn, int *arAddrSize);
sint16				PSSend(PS_SOCKET arSocket, uint8 *arBuffer, uint16 arSize, uint16 arFlag=0);
sint16				PSSendTo(PS_SOCKET arSocket, uint8 *arBuffer, uint16 arSize, PS_SOCKADDR_IN *arAddrIn, int arAddrSize);
sint16				PSShutdown(PS_SOCKET arSocket, sint16 arSDType);
void				PSCleanup(void);
sint16				PSGetLastError(void);
sint16				PSClose(PS_SOCKET arSocket);

void				PSSleep(uint32 arPause);
sint16				PSGetHostIp(in_addr *arIpArr, sint16 arSize);

#endif
