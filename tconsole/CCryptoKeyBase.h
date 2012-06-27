/*
 * File:   CCryptoKeyBase.h
 * Author: mikhail
 *
 * Created on 13 Февраль 2012 г., 10:04
 */

#ifndef CCRYPTOKEYBASE_H
#define	CCRYPTOKEYBASE_H

#include "typenix.h"
#include "alldefine.h"
#include "aes.h"
#include "myfunc.h"
#include <map>
#include <vector>

class CCryptoKeyBase {
  typedef std::vector<uint8> TKey;
  typedef std::map<uint32,  TKey> TCryptoMap;
  TCryptoMap cmap;
  TCryptoMap::iterator curKey;

  static CCryptoKeyBase *gCCryptoKeyBaseObj;
public:
  CCryptoKeyBase(const std::string &arPath) { loadKeysDBFromFile(arPath); }
  ~CCryptoKeyBase() {}
  void loadKeysDBFromFile(const std::string &arPath);
  uint8 getKeyByNode(uint32 arNode, TKey &arKey);
  bool IsMy(uint32 arNode);

  void setBegin() { curKey=cmap.begin(); }
  bool eofKeys() const { return curKey==cmap.end(); }
  uint32 cntKeys() const { return cmap.size(); }
  uint32 getCurKeyAndInc() {
    uint32 val=(*curKey).first;
    ++curKey;
    return val;
  }

  void free();
  static CCryptoKeyBase *getInstance();
  static CCryptoKeyBase *getInstance(const char * arPath);
};

#endif	/* CCRYPTOKEYBASE_H */

