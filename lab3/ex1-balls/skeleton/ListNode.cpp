#include "ListNode.h"
#include <iostream>

ListNode::ListNode(int value) {
  this->_value = value;
  this->_next = NULL;
  this->_prev = NULL;
}

ListNode* ListNode::getNext() {
  return this->_next;
}

ListNode* ListNode::getPrev() {
  return this->_prev;
}

void ListNode::setNext(ListNode* ptr) {
  this->_next = ptr;
}

void ListNode::setPrev(ListNode* ptr) {
  this->_prev = ptr;
}

void ListNode::setValue(int value) {
  this->_value = value;
}

int ListNode::getValue() {
  return this->_value;
}
