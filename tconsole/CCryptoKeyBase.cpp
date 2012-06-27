/*
 * File:   CCryptoKeyBase.cpp
 * Author: mikhail
 *
 * Created on 13 Февраль 2012 г., 10:04
 */

#include "CCryptoKeyBase.h"
#include "config.h"
#include <fstream>
#include <iterator>
#include <iostream>
#include <wx/wx.h>
#include <wx/msgout.h>

CCryptoKeyBase *CCryptoKeyBase::gCCryptoKeyBaseObj=NULL;

void CCryptoKeyBase::free()
{
	if (gCCryptoKeyBaseObj!=NULL) {
		delete gCCryptoKeyBaseObj;
		gCCryptoKeyBaseObj=NULL;
	}
}

CCryptoKeyBase *CCryptoKeyBase::getInstance(const char * arPath)
{
	if (gCCryptoKeyBaseObj!=NULL) {
		delete gCCryptoKeyBaseObj;
		gCCryptoKeyBaseObj=NULL;
	}
  gCCryptoKeyBaseObj=new CCryptoKeyBase(std::string(arPath));

  return gCCryptoKeyBaseObj;
}

CCryptoKeyBase *CCryptoKeyBase::getInstance()
{
	return gCCryptoKeyBaseObj;
}

//--------------------------------------------------------------------------------------------
void CCryptoKeyBase::loadKeysDBFromFile(const std::string &arPath)
{
  uint8 buffer[BUFFERSIZE/4]={0};
  uint8 key[BUFFERSIZE/4]={0};

  uint32 iNode=0;
	std::ifstream fKeyFile;

	fKeyFile.open(arPath.c_str(), std::fstream::binary);
	if (!fKeyFile.is_open()) {
		//wxMessageOutputDebug().Printf("Error. Key not found");
		throw "Error. Key not found 1";
	}

  do {
    std::fill(&buffer[0], &buffer[BUFFERSIZE/4], 0);
    fKeyFile.get(reinterpret_cast<char *>(buffer), BUFFERSIZE/4, ' ');
    if (fKeyFile.eof())
      break;
    if (!fKeyFile.good()) {
      //wxMessageOutputDebug().Printf("Error. Key not found");
      throw "Error. Key not found 2";
    }

    buffer[fKeyFile.gcount()]=0;
    iNode=atoi(reinterpret_cast<char *>(buffer));

    std::fill(&buffer[0], &buffer[BUFFERSIZE/4], 0);
    fKeyFile.getline(reinterpret_cast<char *>(buffer), BUFFERSIZE/4);
    if (!fKeyFile.good()) {
      //wxMessageOutputDebug().Printf("Error. Key not found, may be need add end of string in key file");
      throw "Error. Key not found, may be need add end of string in key file";
    }

    uint32 klen=strlen((const char *)buffer)-1;
    for (uint32 i=0, j=0; i<klen; i++) {
      sscanf((const char *)&buffer[1+2*i], "%2X", &j);
      key[i]=(char)j;
    }

    cmap.insert(std::make_pair(iNode, TKey(key, key+klen/2)));
  }
  while (!fKeyFile.eof());
  fKeyFile.close();
  //wxMessageOutputDebug().Printf("Load %d keys", (uint32)cmap.size());
}
//--------------------------------------------------------------------------------------------
uint8 CCryptoKeyBase::getKeyByNode(uint32 arNode, TKey &arKey)
{
  CCryptoKeyBase::TCryptoMap::iterator it;
  it=cmap.find(arNode);
  if (it!=cmap.end()) {
    arKey.insert(arKey.begin(), (*it).second.begin(), (*it).second.end());
    return arKey.size();
  }
  return 0;
}
//--------------------------------------------------------------------------------------------
bool CCryptoKeyBase::IsMy(uint32 arNode)
{
  CCryptoKeyBase::TCryptoMap::iterator it;
  it=cmap.find(arNode);
  if (it!=cmap.end())
    return true;

  return false;
}
//--------------------------------------------------------------------------------------------
