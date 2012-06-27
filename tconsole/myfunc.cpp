#ifdef WIN32
#include "..\\stdafx.h"
#endif
#include "myfunc.h"
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

//#include <sys/sysinfo.h>
//#include <sys/statvfs.h>

//#include <proc/readproc.h>
//#include <sys/utsname.h>

namespace ps {

char *itoa(int arValue, char *arResult, int arBase)
{
	char	*ptr = arResult, *ptr1 = arResult, tmp_char;
	int		tmp_value;

	if (arBase < 2 || arBase > 36) {
		*arResult = '\0';
		return arResult;
	}

	do {
		tmp_value = arValue;
		arValue /= arBase;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - arValue * arBase)];
	} while (arValue);

	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return arResult;
}

int atoi16(const char *arBuffer)
{
	uint8		uCount, uLength;
	int			sResult;
	char		ch;

	uLength = strlen(arBuffer);
	for (uCount = 0, sResult = 0; uCount < uLength; uCount++) {
		sResult *= 16;
		ch = arBuffer[uCount];
		if ((ch >= '0') && (ch <= '9')) sResult += ch - '0';
		else if ((ch >= 'a') && (ch <= 'f')) sResult += ch - 'a' + 10;
		else if ((ch >= 'A') && (ch <= 'F')) sResult += ch - 'A' + 10;
		else {
			sResult = -1;
			break;
		}
	}
	return sResult;
}

struct tm *getTimeLocal(const char *arFormat, char *arBuffer, int arSize)
{
	time_t      tTime;
	struct tm   *stTimeTemp = NULL;

	tTime = time(NULL);
	stTimeTemp = localtime(&tTime);
	if ((arFormat != NULL) && (arBuffer != NULL) && (arSize != 0)) {
		strftime(arBuffer, arSize, arFormat, stTimeTemp);
	}
	return stTimeTemp;
}

uint32 getTime()
{
	return static_cast<uint32>(ps_time(NULL));
}

uint32 hexToStr(uint8 *arBuffer, uint16 arSize, char *arStringOut = NULL, uint16 arSizeOut = 0)
{
    uint32          uCount, uOffset;
    uint8           uTemp;

    if (arStringOut != NULL) {
        for (uCount = 0; uCount < arSize; uCount++) {
            uOffset = uCount * 3;
			if (uOffset + 2 >= arSizeOut) return 0;

            ps::itoa(arBuffer[uCount], &arStringOut[uOffset], 16);

            uTemp = arBuffer[uCount];
            if (uTemp < 16) {
                arStringOut[uOffset + 1]    = arStringOut[uOffset];
                arStringOut[uOffset]        = '0';
            }
            arStringOut[uOffset + 2] = ' ';
        }
		if ((uCount * 3) >= arSizeOut) return 0;
		else arStringOut[uCount * 3] = 0;
    }
    return arSize * 3 + 1;
}

std::string trim(std::string arString)
{
	arString.erase(arString.find_last_not_of("\t\r\n\v\f ") + 1, arString.max_size());
	arString.erase(0, arString.find_first_not_of("\t\r\n\v\f "));
	return arString;
}

procid spawn(const char *arProgram)
{
#ifdef WIN32
//	return _spawnl(_P_DETACH, arProgram, NULL);
    STARTUPINFO				si;
    PROCESS_INFORMATION		pi;
	WCHAR					wCommandLine[512]	= {0};
	procid					prId;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED,
		arProgram, strlen(arProgram), wCommandLine, 512);

	if (CreateProcess(NULL, wCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) prId = pi.hProcess;
	else prId = INVALID_HANDLE_VALUE;

	return prId;
#else
	procid		childPid;
	char		**argList;

	childPid = fork();
	if (0 == childPid) {
		argList = explode(' ', arProgram);
		execv(argList[0], argList);
		fprintf(stderr, "an error occurred in execv\n");
		exit(0);
	}
	return childPid;
#endif
}

void kill(procid arPid)
{
#ifdef WIN32
	HANDLE		hEvent;

	hEvent = CreateEventW(NULL, TRUE, FALSE, TEXT("Local\\translator_efthcxml"));
	if (hEvent != NULL) {
		SetEvent(hEvent);
		CloseHandle(hEvent);
	}
#else
	::kill(arPid, SIGTERM);
#endif
}


char **explode(char arDelimiter, const char *const arString, int arLimit)
{
	char			**chList;
	const char		*ptrCur, *ptrPrev;
	uint16			uStrLength, uCnDelim, uElemLength;
	sint16			uCount, uCountPrev;

	uStrLength = strlen(arString);
	for (uCount = 0, uCountPrev = -1, uCnDelim = 0; uCount < uStrLength; uCount++) {
		if (arString[uCount] == arDelimiter) {
			if ((uCount - uCountPrev) > 1) uCnDelim++;
			uCountPrev = uCount;
		}
	}
	uCnDelim++;

	if ((arLimit > 0) && (uCnDelim > arLimit)) uCnDelim = arLimit;
	chList = (char**) malloc(sizeof(char*) * (uCnDelim + 1));

	for (uCount = 0, ptrPrev = arString; uCount < uCnDelim; uCount++) {
		ptrCur = strchr(ptrPrev, arDelimiter);
		if (ptrCur != NULL) {
			uElemLength = ptrCur - ptrPrev;
			if (uElemLength > 0) {
				chList[uCount] = (char*) malloc(sizeof(char) * (uElemLength + 1));
				memcpy(chList[uCount], ptrPrev, uElemLength);
				chList[uCount][uElemLength] = 0;
			}
			ptrPrev = ptrCur + 1;
		} else break;
	}
	if ((uCount < uCnDelim) && ((ptrPrev - arString) < uStrLength)) {
		uElemLength = uStrLength + arString - ptrPrev;
		chList[uCount] = (char*) malloc(sizeof(char) * (uElemLength + 1));
		memcpy(chList[uCount], ptrPrev, uElemLength);
		chList[uCount][uElemLength] = 0;
		uCount++;
	}
	chList[uCount] = NULL;

	return chList;
}

#ifdef WIN32
// � Linux ��� ������� �� ����������

std::string WideToMulti(const std::wstring arString, uint32 arCP)
{
	std::string				strOut;
	const int strLength = ::WideCharToMultiByte(arCP, 0,
		arString.data(), arString.length(),
		NULL, 0, NULL, NULL);
	strOut.resize(strLength);
	::WideCharToMultiByte(arCP, 0,
		arString.data(), arString.length(),
		&strOut[0], strOut.length(), NULL, NULL);
	return strOut;
}

std::wstring MultiToWide(const std::string arString, uint32 arCP)
{
	std::wstring			strOut;
	const int strLength = ::MultiByteToWideChar(arCP, 0,
		arString.data(), arString.length(), NULL, 0);
	strOut.resize(strLength);
	::MultiByteToWideChar(arCP, 0,
		arString.data(), arString.length(), &strOut[0], strOut.length());
	return strOut;
}
#endif

std::string ansiToUtf(const std::string arString)
{
#ifdef WIN32
	return WideToMulti(MultiToWide(arString, CP_ACP), CP_UTF8);
#else
	return std::string(arString);
#endif
}

std::string asciiToUtf(const std::string arString)
{
#ifdef WIN32
	return WideToMulti(MultiToWide(arString, CP_OEMCP), CP_UTF8);
#else
	return std::string(arString);
#endif
}

std::string ansiToAscii(const std::string arString)
{
#ifdef WIN32
	return WideToMulti(MultiToWide(arString, CP_ACP), CP_OEMCP);
#else
	return std::string(arString);
#endif
}

std::string asciiToAnsi(const std::string arString)
{
#ifdef WIN32
	return WideToMulti(MultiToWide(arString, CP_OEMCP), CP_ACP);
#else
	return std::string(arString);
#endif
}

std::string utfToAnsi(const std::string arString)
{
#ifdef WIN32
	return WideToMulti(MultiToWide(arString, CP_UTF8), CP_ACP);
#else
	return std::string(arString);
#endif
}

std::string utfToAscii(const std::string arString)
{
#ifdef WIN32
	return WideToMulti(MultiToWide(arString, CP_UTF8), CP_OEMCP);
#else
	return std::string(arString);
#endif
}

/* Минимальный компактный генератор случайных чисел Парка и Миллера */
/* константы Льюиса-Гудмана-Миллера */
#define IA 16807
#define IM 2147483647
#define AM (1./IM)
/* константы Шаржа */
#define IQ 12773
#define IR 2836
/* Специальная маска (см. ниже) */
#define MASK 123456789
static long dummy;
/* начальное значение для всех генераторов */
void Seed(long dum)
{dummy=dum;}
/* возвращает случайное число на промежутке от 0 до 1 */
double unirand0(void)
{
	long k;double ans;dummy^=MASK; /* избегаем dummy==0 */
	k=dummy/IQ;
	if((dummy=IA*(dummy-k*IQ)-IR*k)<0)
		dummy+=IM;
	ans=AM*dummy;
	dummy^=MASK;
	/* восстанавливаем dummy */
	return(ans);
}
void getRand(int len,uint8 *buf)
{
  double ch;
	for (int i=0;i<len;i++) {
    ch=unirand0();
    int j=(uint8)(ch*1000)/2;
    while(j>256) j/=2;
    buf[i]=j;
	}
}

std::string getIpPort(const std::string &arIp, uint32 arPort)
{
  std::stringstream sIpPort;
  sIpPort << arIp << ":" << arPort;
  return sIpPort.str();
}

std::string getIp(const char * arIpPort)
{
  std::string rc;
  char **p=ps::explode(':', arIpPort, 2);

  if (p[0]!=NULL) {
    rc.append(p[0]);
    free(p[0]);
  }
  if (p[1]!=NULL) {
    free(p[1]);
  }

  return rc;
}

uint32 getPort(const char * arIpPort)
{
  uint32 rc=0;
  char **p=ps::explode(':', arIpPort, 2);

  if (p[0]!=NULL) {
    free(p[0]);
  }
  if (p[1]!=NULL) {
    rc=atoi(p[1]);
    free(p[1]);
  }

  return rc;
}

uint64 ObtainMem()
{
//  struct proc_t usage;
//  look_up_our_self(&usage);
// return usage.vsize;
/*
  struct sysinfo s_info;
  int error;
  unsigned long fram;
  error = sysinfo( &s_info );
  if (error == 0)
    fram = s_info.mem_unit;
  return (fram);
 */
 return 0;
}

uint64 FreeHddSpace(const char *arPath)
{
  return 0;
  /*
  uint64 free=0;
  struct statvfs fiData;

  if (!((statvfs(arPath, &fiData))<0)) {
    free=fiData.f_bfree*fiData.f_bsize;
  }
  return free;
  */
}

uint32 SystemLoads()
{
//  struct proc_t usage;
//  look_up_our_self(&usage);
//  return usage.pcpu;
return 0;
}

std::string SysName()
{
  return 0;
/*
  struct utsname ver;
  uname(&ver);
  std::stringstream stream;
  stream << ver.sysname << " " << ver.release << " " << ver.version;
  return stream.str();
  */
}

bool StrToInt(std::string &arString, uint32 *arValue)
{
  std::stringstream stream(arString);
  bool rc=true;
  try {
    stream >> (*arValue);
  }
  catch (...) {
    rc=false;
  }
  return rc;
}

std::string IntToStr(uint32 arValue)
{
  std::stringstream stream;
  try {
    stream << (arValue);
  }
  catch (...) {
    return "";
  }
  return std::string(stream.str());
}

}

