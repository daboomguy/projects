#ifndef MYFUNC_H
#define MYFUNC_H

#include <time.h>
#include <string>
#include "pstype.h"
#ifdef WIN32
#include <windows.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
//#include <iconv.h>
#endif

#ifdef WIN32
#define ps_time(a)	_time32(a)
#else
#define ps_time(a)	time(a)
#endif

namespace ps {
#ifdef WIN32
	typedef HANDLE		procid;
#else
	typedef pid_t		procid;
#endif

	char			*itoa(int arValue, char *arResult, int arBase);
	struct tm		*getTimeLocal(const char *arFormat, char *arBuffer = NULL, int arSize = 0);
	uint32			getTime();
	uint32			hexToStr(uint8 *arBuffer, uint16 arSize, char *arStringOut, uint16 arSizeOut);
	std::string		trim(std::string arString);
	procid			spawn(const char *arProgram);
	void			kill(procid arPid);
	char			**explode(char arDelimiter, const char *const arString, int arLimit = 0);
	int				atoi16(const char *arBuffer);

#ifdef WIN32
	// � Linux ��� ������� �� ����������
	std::string		WideToMulti(const std::wstring arString, uint32 arCP);
	std::wstring	MultiToWide(const std::string arString, uint32 arCP);
#endif
	std::string		ansiToUtf(const std::string arString);
	std::string		asciiToUtf(const std::string arString);
	std::string		ansiToAscii(const std::string arString);
	std::string		asciiToAnsi(const std::string arString);
	std::string		utfToAnsi(const std::string arString);
	std::string		utfToAscii(const std::string arString);

	void			Seed(long dum);
	double    unirand0(void);
	void			getRand(int len,uint8 *buf);

  std::string getIpPort(const std::string &arIp, uint32 arPort);
  std::string getIp(const char * arIpPort);
  uint32 getPort(const char * arIpPort);
  uint64 ObtainMem();
  uint64 FreeHddSpace(const char *arPath);
  uint32 SystemLoads();
  std::string SysName();

  bool StrToInt(std::string &arString, uint32 *arValue);
  std::string IntToStr(uint32 arValue);
}

#endif

