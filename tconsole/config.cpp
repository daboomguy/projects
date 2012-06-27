#include "config.h"
#include "CProtocol.h"
#include <map>

CConfig *CConfig::gConfigObj=NULL;

void CConfig::free()
{
	if (gConfigObj!=NULL) {
		delete gConfigObj;
		gConfigObj=NULL;
	}
}

CConfig* CConfig::getInstance(const char *p_xml_path)
{
	if (gConfigObj==NULL) {
		gConfigObj=new(std::nothrow) CConfig(p_xml_path);
#ifndef WIN32
		if (gConfigObj == NULL) printf("Error: unable to create CONFIG object\n");
#endif
	}
	return gConfigObj;
}

bool CConfig::Init(const char *p_xml_path)
{
	path=string(p_xml_path);//getPath();//std::string(p_xml_path);
	if (!gFlagInit) {
		if (doc.load_file(path.c_str()))
			gFlagInit=Parse();
	}
	return gFlagInit;
}

bool CConfig::Parse()
{
	pugi::xml_node tool, tools;

	tools=doc.child("configuration");
	if (!tools)
		return false;


  tool=tools.find_child_by_attribute("name", "ALIASES");
  tool=tool.first_child();
  while (true) {
    if (tool.empty())
      break;

    settings.aliases.push_back(tool.attribute("value").as_int());
    tool=tool.next_sibling();
  }

	tool=tools.find_child_by_attribute("name", "NODE");
	settings.my_node=tool.attribute("value").as_int();

	tool=tools.find_child_by_attribute("name", "KEY");
	settings.key_path=getBinPath()+tool.attribute("value").value();

  if (!parseSessions(tools, "VIT"))
    return false;

  if (!parseSessions(tools, "VIP"))
    return false;

  return true;
}

bool CConfig::parseSessions(pugi::xml_node &arTools, const char * arSection)
{
	pugi::xml_node sessions=arTools.find_child_by_attribute("name", arSection);
	for (pugi::xml_node_iterator param=sessions.begin(); param!=sessions.end(); ++param) {
		SSession session;

		session.row_number=(*param).attribute("tag").as_int();
		pugi::xml_node xts=(*param).find_child_by_attribute("name", "DEST_NODE");
		session.destination.node=xts.attribute("value").as_int();

		xts=(*param).find_child_by_attribute("name", "SRC_NODE");
		session.source.node=xts.attribute("value").as_int();
    if (session.source.node==0)
      session.source.node=settings.my_node;

    xts=(*param).find_child_by_attribute("name", "SRC_INT");
    session.source.interface=xts.attribute("value").as_int();
    if (session.source.interface==0) {
      session.source.interface=CProto::CONSOLE_INTERFACE_NUMBER;
    }

    xts=(*param).find_child_by_attribute("name", "DEST_INT");
		session.destination.interface=xts.attribute("value").as_int();
    if (session.destination.interface==0) {
      session.destination.interface=CProto::CONSOLE_INTERFACE_NUMBER;
    }

    xts=(*param).find_child_by_attribute("name", "IP_PORT");
    xts=xts.first_child();

    std::multimap<uint32, std::string> m;

    while (true) {
      //std::cout << xts.attribute("value").value() << std::endl;
      if (xts.empty())
        break;

      m.insert(std::make_pair(xts.attribute("priority").as_uint(),
                              std::string(xts.attribute("value").value())));

      xts=xts.next_sibling();
    }

    for (std::multimap<uint32, std::string>::iterator it=m.begin(); it!=m.end(); ++it) {
      session.ip_port_list.push_back((*it).second);
    }

		xts=(*param).find_child_by_attribute("name", "KA_RECV");
		session.keep_alive_recv=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "KA_SEND");
		session.keep_alive_send=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "CONNECTION_TIME");
		session.connection_time=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "RECONNECT_TIME");
		session.reconnect_time=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "CONNECT_TIMEOUT");
		session.connect_timeout=xts.attribute("value").as_int()*1000;
    if (!session.connect_timeout)
      session.connect_timeout=30000;

		xts=(*param).find_child_by_attribute("name", "CONNECTION_IDLE_TIME");
		session.connection_idle_time=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "TTL");
		session.ttl=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "TTL2");
		session.ttl2=xts.attribute("value").as_int()*1000;

		xts=(*param).find_child_by_attribute("name", "MAX_COUNT");
		session.maxcount=xts.attribute("value").as_int();

    xts=(*param).find_child_by_attribute("name", "TYPE");

    if (strcmp(arSection, "VIT")==0) {
      if (strcmp(xts.attribute("value").value(), "CONNECTOR")==0) {
        (settings.default_server_id==session.row_number)
        ?	settings.vit_connectors.push_front(session)
        : settings.vit_connectors.push_back(session);
      }
      else if (strcmp(xts.attribute("value").value(), "LISTENER")==0) {
        //settings.vit_listeners.push_back(session);
        perror("Cant parse LISTENER set CONNECTOR");
      }
      else {
        std::cout << "Unknown type of VIT " << xts.attribute("value").value() << std::endl;
        return false;
      }
    }
    else if (strcmp(arSection, "VIP")==0) {
      if (strcmp(xts.attribute("value").value(), "CONNECTOR")==0) {
        settings.vip_connectors.push_front(session);
      }
      else if (strcmp(xts.attribute("value").value(), "LISTENER")==0) {
        perror("Cant parse LISTENER set CONNECTOR");
        //settings.vip_listeners.push_back(session);
      }
      else {
        std::cout << "Unknown type of VIP " << xts.attribute("value").value() << std::endl;
        return false;
      }
    }
    else {
      std::cout << "Unknown config section " << arSection << std::endl;
      return false;
    }
	}
  return true;
}

string CConfig::getPath()
{
#ifdef WIN32
	char	pathBuff[MAX_PATH];
	int		iCount;

	if (path.empty()) {
		HMODULE  h_module = GetModuleHandle(NULL);
		if (GetModuleFileNameA(h_module, pathBuff, MAX_PATH)) {
			for (iCount = strlen(pathBuff); iCount > 0; iCount--) {
				if (pathBuff[iCount] == '\\') {
					pathBuff[iCount + 1] = 0;
					path.assign(pathBuff);
					binpath=path;
					break;
				}
			}
		} else path.clear();
//		path.append();
	}
#else
//	path.assign(CONFFILENAME);
#endif

	return path;
}
