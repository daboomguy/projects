#ifndef CONFIG_H
#define CONFIG_H


#ifdef WIN32
#include "..\\lib\\pstype.h"
#include "..\\lib\\pugixml.hpp"
#include <windows.h>
#define MAX_PATH        260
#else
#include "pstype.h"
#include "pugixml.hpp"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#endif

#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <iostream>
#include <iterator>

using std::string;

#define MAX_STR_SCRIPT 5
#define COUNT_OF_RETRY 1

#ifndef MAX_PATH
#define MAX_PATH		255
#endif

struct SRoute {
  uint32 node;
  uint32 interface;
  SRoute() : node(0), interface(0) {}
  SRoute(uint32 arNode, uint32 arInterface) : node(arNode), interface(arInterface) {}
  SRoute(const SRoute &temp) { node=temp.node; interface=temp.interface; }
  SRoute &operator=(const SRoute &temp) { node=temp.node; interface=temp.interface; return *this; }
  bool operator==(const SRoute &temp) { return (node==temp.node && interface==temp.interface); }
};

class SSession {
public:
  SSession(const SSession &temp) {
    if (this==&temp || &temp==NULL)
      return;

//    logsave("SSession copy constructor");
    current_ip_port_index=temp.current_ip_port_index;
    current_ip_port_try=temp.current_ip_port_try;
    row_number=temp.row_number;
    destination=temp.destination;
    source=temp.source;
  	keep_alive_send=temp.keep_alive_send;
    keep_alive_recv=temp.keep_alive_recv;
    connect_timeout=temp.connect_timeout;
    connection_time=temp.connection_time;
    connection_idle_time=temp.connection_idle_time;
    ttl=temp.ttl;
    ttl2=temp.ttl2;
    maxcount=temp.maxcount;
    reconnect_time=temp.reconnect_time;
    std::copy(temp.ip_port_list.begin(), temp.ip_port_list.end(), std::back_inserter(ip_port_list));
  }

  SSession &operator=(const SSession &temp) {
    if (this==&temp || &temp==NULL)
      return *this;

//    logsave("SSession copy constructor");
    current_ip_port_index=temp.current_ip_port_index;
    current_ip_port_try=temp.current_ip_port_try;
    row_number=temp.row_number;
    destination=temp.destination;
    source=temp.source;
  	keep_alive_send=temp.keep_alive_send;
    keep_alive_recv=temp.keep_alive_recv;
    connect_timeout=temp.connect_timeout;
    connection_time=temp.connection_time;
    connection_idle_time=temp.connection_idle_time;
    ttl=temp.ttl;
    ttl2=temp.ttl2;
    maxcount=temp.maxcount;
    reconnect_time=temp.reconnect_time;

    if (!ip_port_list.empty())
      ip_port_list.clear();

    std::copy(temp.ip_port_list.begin(), temp.ip_port_list.end(), std::back_inserter(ip_port_list));

    return *this;
  }

public:
  SSession() {}

  uint32 current_ip_port_index;
  uint32 current_ip_port_try;
  uint32 row_number;
	SRoute destination;
  SRoute source;
  std::deque<std::string> ip_port_list;
	uint32 keep_alive_send;
	uint32 keep_alive_recv;
	uint32 connect_timeout;
	uint32 connection_time;
	uint32 connection_idle_time;
	uint32 ttl;
	uint32 ttl2;
  uint32 maxcount;
  uint32 reconnect_time;
  bool need_sign;

  bool is_it(const char *arIpPort) {
    if (ip_port_list.empty())
      return false;

    std::string finder(arIpPort);
    return (std::find(ip_port_list.begin(), ip_port_list.end(), finder)!=ip_port_list.end());
  }


  bool is_it1(uint32 arNode, uint32 arInterface) {
    return (source.node==arNode && source.interface==arInterface);
  }

  bool operator==(const SSession &arSession) const {
    if (source.node==arSession.source.node &&
        destination.node==arSession.destination.node &&
        source.interface==arSession.source.interface &&
        destination.interface==arSession.destination.interface)
      return true;
    return false;
  }

  bool operator==(const SSession *arSession) const {
    if (source.node==arSession->source.node &&
        destination.node==arSession->destination.node &&
        source.interface==arSession->source.interface &&
        destination.interface==arSession->destination.interface)
      return true;
    return false;
  }

  bool operator==(const char * arIpPort) {
    return is_it(arIpPort);
  }

  bool Finder(const char * arIpPort, uint32 arDestInt) {
    //logsave("sess finder %d==%d %s", source.interface, arDestInt, arIpPort);
    return (arDestInt!=0) ?
      (is_it(arIpPort) && source.interface==arDestInt) :
      is_it(arIpPort);
  }

  std::string getCurrentIpPort() {
    if (ip_port_list.empty())
      return "";
/*
    if (!current_ip_port_try) {
      current_ip_port_try=COUNT_OF_RETRY;
      if (++current_ip_port_index>=ip_port_list.size()) {
        current_ip_port_index=0;
      }
    }
    --current_ip_port_try;
*/
    return ip_port_list[0];
  }
};

typedef std::deque <SSession> TConnectors;
typedef TConnectors TListeners;

typedef struct {
  std::list<uint32> aliases;
  uint32 my_node;
	uint16 log_level;
	std::string log_path;
	uint32 log_lifetime;
	std::string key_path;
	uint32 default_server_id;
  uint8 dump;
	TConnectors vit_connectors;
  TConnectors vip_connectors;
} SConfig;

class CConfig
{
	static CConfig *gConfigObj;
	bool gFlagInit;
	pugi::xml_document doc;
	std::string path;
	std::string binpath;

	bool Encrypt() { return false; };
	bool Decrypt() { return false; };
	bool Parse();
	CConfig(const char *p_xml_path) : gFlagInit(false) { if (!Init(p_xml_path)) throw "Can't Init"; }
	bool Init(const char *p_xml_path);
  bool parseSessions(pugi::xml_node &arTools, const char * arSection);
public:
  struct SFindByItf : public std::binary_function<SSession, uint32, bool> {
    bool operator()(SSession &arSess, uint32 arItf) const {
      return (arSess.source.interface==arItf) ? true : false;
    }
  };

  static CConfig *getInstance(const char *p_xml_path);
	static CConfig *getInstance() { return gConfigObj; };
	static void	free();
	SConfig settings;
	void Save();
	string getPath();
	string getBinPath() { return binpath; };

  bool IsMyAlias(uint32 arAlias) {
    return std::find(settings.aliases.begin(), settings.aliases.end(), arAlias)!=settings.aliases.end();
  }
};

#endif

