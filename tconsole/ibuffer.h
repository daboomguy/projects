/*
 * File:   ibuffer.h
 * Author: mikhail
 *
 * Created on 12 Декабрь 2011 г., 13:11
 */

#ifndef IBUFFER_H
#define	IBUFFER_H

#include <vector>
#include <deque>

#include "typenix.h"
#include "alldefine.h"
#include <iostream>
#include <algorithm>

#define DEFAULT_BUFFER_SIZE 1024*4;

template <typename T, uint32 Size>
class MyB {
  static const uint32 _size=Size+1;//1024*4+1;
  T _b[_size];
  uint32 uDataLength;
  std::string sName;

  void DeepCopy(const MyB &temp) {
    clear();
    Copy(temp);
    sName.assign(temp.getName());
  }
public:
  bool empty() { return uDataLength==0; }
  uint32 capacity() const { return _size-1; }
  void clear() {
    //std::fill(&_b[0], &_b[_size], 0);
    memset(&_b[0], 0, _size);
    uDataLength=0;
  }

  void setName(const char * arName) { sName.assign(arName); }
  const char * getName() const { return sName.c_str(); }

  T * begin() {
    return &_b[0];
  }

  const T * begin() const {
    return /*const_cast<const uint8 *>(*/&_b[0]/*)*/;
  }

  T * end() {
    return &_b[uDataLength];
  }

  uint32 size() const {
    return uDataLength;
  }

  void SetSize(uint32 arSize) {
    if ((capacity()>=arSize))
      uDataLength=arSize;
  }

  void MoveLeft(uint32 arSize) {
    if (uDataLength>arSize) {
      T temp[_size];
      std::fill(&temp[0], &temp[_size], 0);
      std::copy(&_b[0], &_b[uDataLength], &temp[0]);
      std::fill(&_b[0], &_b[_size], 0);
      std::copy(&temp[arSize], &temp[uDataLength], &_b[0]);
      uDataLength-=arSize;
      //logsave("%s BUFFER MOVE LEFT %d bytes NEW SIZE %d", getName(), arSize, uDataLength);
    }
    else if (uDataLength<=arSize) {
      clear();
      //logsave("%s BUFFER MOVE LEFT %d bytes", getName(), arSize);
    }
  }

  template<typename TT>
  uint32 Copy(const TT &arBuffer) {
    uint32 uCopyLength=arBuffer.size();
    if ((capacity()-size())<uCopyLength)
      uCopyLength=capacity()-size();

    std::copy(arBuffer.begin(), arBuffer.begin()+uCopyLength, begin()+size());
    //logsave("%s BUFFER OLD %d COPY %d NEW %d", getName(), size(), uCopyLength, size()+uCopyLength);
    SetSize(size()+uCopyLength);
    return uCopyLength;
  }

  void push_back(const T &arValue) {
    if (capacity()>size()+1) {
      _b[size()]=arValue;
      SetSize(size()+1);
    }
  }

  MyB() : uDataLength(0) {
    //std::fill(&_b[0], &_b[_size], 0);
    memset(&_b[0], 0, _size);
//    logsave("MyB() create 1");
  }
  MyB(uint32 arLength, T arData) : uDataLength(arLength) {
    std::fill(&_b[0], &_b[arLength], arData);
//    logsave("MyB() create 2");
  }

  MyB(T *arBuffer, uint32 arLength) : uDataLength(0) {
    std::fill(&_b[0], &_b[_size], 0);
    if (capacity()>arLength) {
      std::copy(arBuffer, arBuffer+arLength, begin());
      SetSize(arLength);
    }
//    logsave("MyB() create 3");
  }

  MyB(const MyB &temp) {
//    logsave("%s MyB copy constructor", getName());
    DeepCopy(temp);
//    logsave("MyB() create 4");
  }

  ~MyB() {
//    logsave("~MyB() delete");
  }

  MyB &operator=(const MyB &temp) {
//    logsave("MyB() create 5");
    DeepCopy(temp);
    return *this;
  }
};

/* Интерфейс работы с буферами*/
template <typename IBufferType, typename OBufferType>
class IBuffer {
public:
  IBufferType InputBuffer;
  OBufferType OutputBuffer;
  IBuffer() : InputBuffer(), OutputBuffer() {
    /*logsave("IBuffer()"); */
  }

  void ClearBuffers() {
    InputBuffer.clear();
    OutputBuffer.clear();
  }

  virtual ~IBuffer() {
    ClearBuffers();
    //logsave("~IBuffer()");
  }
};

//typedef IBuffer< std::vector<uint8>, std::vector<uint8> > BufferInterface;
//typedef MyB<uint8, 1024*4> MyDefaultBuffer;
//typedef IBuffer<MyDefaultBuffer, MyDefaultBuffer> BufferInterface;

typedef std::vector<uint8> MyDefaultBuffer;
typedef IBuffer<MyDefaultBuffer, MyDefaultBuffer> BufferInterface;

#endif	/* IBUFFER_H */

