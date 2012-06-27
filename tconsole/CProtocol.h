/*
 * File:   CProtocol.h
 * Author: buzz
 *
 * Created on 28 Ноябрь 2011 г., 21:32
 */

#ifndef CPROTOCOL_H
#define	CPROTOCOL_H

#include "typenix.h"
#include "ibuffer.h"

class CProto {
  static const uint8 uDUTTypeasText[][16];
public:
	//Тип сообщения - младший октет Type - 0x000000FF
	enum TDinamicDUTHeaderAdditionType {
		DDHT_ORDINARY			= 0,			//Сообщение с данными
		DDHT_BOTS					= 1,			//Запрос о начале установления сессии
		DDHT_EOTS					= 2,			//Запрос о завершении сессии
		DDHT_FOTS					= 3,			//Запрос об аварийном завершение сессии
		DDHT_KEEPALIVE		= 4,			//Контроль работоспособности сессии
		DDHT_CONFIRMATION	= 5,			//Подтверждение переданных данных
		DDHT_BUSY					= 6				//Занято
	};

	typedef struct TDinamicDUTHeaderAddition {
		uint32		Type;				//Тип сообщения (четыре октета) TDinamicDUTHeaderAdditionType
		uint32		LSN;				//Номер логической сессии отправителя
		uint32		RLSN;				//Номер логической сессии получателя
		uint16		cX0;				//Для динамического сервера DUT = C=X0
		uint16		cX1;				//Для динамического сервера DUT = C=X1
		uint8			cX2;				//Для динамического сервера DUT = C=X2
		uint8			cX3;				//Для динамического сервера DUT = C=X3
		uint8			cX4;				//Для динамического сервера DUT = C=X4
		uint8			cX5;				//Для динамического сервера DUT = C=X5
    //TDinamicDUTHeaderAddition() : Type(0), LSN(0), RLSN(0), cX0(0), cX1(0), cX2(0), cX3(0), cX4(0), cX5(0) {}
    //virtual ~TDinamicDUTHeaderAddition() {}
	} tdhAdd;

	typedef struct TDinamicDUTHeaderAddition2 : TDinamicDUTHeaderAddition	{
		uint32		ReadKeepAlive_Time;
		uint32		WriteKeepAlive_Time;
		uint32		Connect_TimeOut;
		uint32		Connection_Time;
		uint32		ConnectionIdle_Time;
		uint16		TTL;
		uint16		TTL2;
		uint32		cX6;				//Описатель протокола соединения
		uint32		DOL;				//Указатель наличия доп данных
    //TDinamicDUTHeaderAddition2() : ReadKeepAlive_Time(0), WriteKeepAlive_Time(0), Connect_TimeOut(0),
    //                               Connection_Time(0), ConnectionIdle_Time(0), TTL(0), TTL2(0), cX6(0), DOL(0) {}
    const uint8 * getComandAsString() {
      return &uDUTTypeasText[(Type & 0x00000100) ? Type & 0x00000011 : Type][0];
    }

	} tdhAdd2;

	// Номера интерфейсов
	enum TInterfaceNumbers 	{
		// Интерфейс Telnet
		ITF_TELNET									=	21,
		// Консольный интерфейс
		CONSOLE_INTERFACE_NUMBER		=	100,
		// Интерфейса списка узлов
		NODES_LIST_INTERFACE_NUMBER	=	101,
		// Трэйс
		TRACE_INTERFACE_NUMBER			=	102,
		// Интерфейс списка доступных интерфейсов
		ITF_LIST_INTERFACE_NUMBER		=	103,
		// Интерфейс конфигурации узла
		ITF_CONFIG									=	104,
		// Интерфейс просмотра и изменения конфигурации сервера
		ITF_SERVER_CONFIG						=	105,
		// Интерфейс редактирования VIP интерфейсов сервера
		ITF_VIP_EDITOR							=	106,
		// Интерфейс конфигурации роутера
		ITF_CONF_EDITOR							=	110,
		// Интерфейс ответа веб управлению
		ITF_CONF_WEB								=	111,
		// VIP интерфейс роутера
		DDUT_INTERFACE_NUMBER				=	200
	};

  typedef struct _SCAP2_SESS_SETTINGS
  {
    uint32 KeepAliveSend;
    uint32 aux1;
    uint32 aux2;
    uint32 aux3;
    uint32 aux4;
    uint32 aux5;
    uint32 aux6;
    uint32 aux7;
  } SCAP2_SESS_SETTINGS;

  typedef struct _VITHeader
  {
    uint32 Source_NODE;            // узел - источник пакета
    uint32 Flags;                  // режимы пакета
    uint32 Dest_NODE;              // узел - назначение пакета
    uint16 Dest_INTERFACE;         // интерфейс - назначение пакета
    uint16 Source_INTERFACE;       // интерфейс - источника пакета
    uint16 Size;                   // размер прикладных данных (DCMH+Data)
    uint16 TTL;                    // максимальное количество маршрутизаций пакета
    uint16 Mode;                   // режимы пакета
    uint16 TTL2;                   // максимальное время нахождения в очередях
  } VITHeader;

  typedef struct _ItfTrace
  {
    uint16 ver;                    // версия заголовка
    uint16 type;                   // тип сообщения
    uint16 data_size;              // размер дополнительных данных
    uint16 reserved;               // не используется
    uint32 uid;                    // уникальный идентификатор трэйса
    uint32 tim;                    // метка времени создания трэйса
  } ItfTrace;

  typedef struct _SPreAuth {
    uint8 scapVersion[10];
    uint16 iNode;
    uint8 random[16];
    uint8 aux[16];
  } SPreAuthPacket;

  CProto() {}
  virtual ~CProto() {}
};


class CProtocol : public CProto, public BufferInterface {

  inline uint8 Lo(uint16 arValue) { return arValue & 0xff; }
  inline uint8 Hi(uint16 arValue) { return arValue >> 8; }

  static const uint32 iPacketSize=4000;
  uint16 uPacketNumber;
public:
  TDinamicDUTHeaderAddition2 ddhaOut;
  TDinamicDUTHeaderAddition2 ddhaIn;
  _VITHeader header;

  CProtocol() : ddhaOut(), ddhaIn(), header() {
    //logsave("CProtocol() create");
    //InputBuffer.setName("CProtocol");
    //OutputBuffer.setName("CProtocol");
    uPacketNumber=0;
  }

  virtual ~CProtocol() { /*logsave("~CProtocol() delete");*/ }
  uint32 Pack(uint8 *arSrc, uint32 arLength);
  uint32 UnPack(uint8 *arSrc, uint32 arLength);
  static void Sign(uint8 *arSrc, uint32 arLength);
  void Put(uint32 arSize) {}

  template<class A> friend CProtocol * operator>>(A &arInput, CProtocol *obj) {
    uint32 iLen=arInput.InputBuffer.size();

    uint32 iPacket=CProtocol::iPacketSize;
    if (iPacket>iLen)
      iPacket=iLen;

    MyDefaultBuffer temp(arInput.InputBuffer.begin(), iPacket);
    if (!obj->Pack(temp[0], temp.size()))
      throw "can't pack";

    arInput.InputBuffer.MoveLeft(iPacket);
    return obj;
  }

  template<class A> friend CProtocol & operator<<(A &arInput, CProtocol &obj) {
    if (!obj.UnPack(arInput.OutputBuffer.begin(), arInput.OutputBuffer.size()))
      throw "can't unpack";

    arInput.OutputBuffer.clear();
    return obj;
  }
};

#endif	/* CPROTOCOL_H */

