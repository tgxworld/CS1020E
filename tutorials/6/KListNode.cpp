#include <iostream>
#include "KListNode.h"

KListNode::KListNode(int item, int k) {
  this->_item = item;
  this->_k = k;
  this->_kNext = NULL;
  this->_next = NULL;
}

int KListNode::getItem() {
  return this->_item;
}

KListNode* KListNode::getKNext() {
  return this->_kNext;
}

KListNode* KListNode::getNext() {
  return this->_next;
}

void KListNode::setNext(KListNode* listNode) {
  this->_next = listNode;
}

void KListNode::setKNext(KListNode* listNode) {
  this->_kNext = listNode;
}
