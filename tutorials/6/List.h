#ifndef list_h
#define list_h

#include "KListNode.h"

class List {
  private: 
    KListNode* _head;
    int _size;
    int _skipInt;
  public:
    List(int skipInt);
    bool insertKListNode(int index, const int& newItem);
    bool removeKListNode(int index);
    void pushBack(int &item);
    void printList();
    KListNode* traverseTo(int index);
};

#endif
