#include "List.h"
#include <iostream>
using namespace std;

List::List() {
  this->_size = 0;
  this->_head = NULL;
}

ListNode* List::getHead() {
  return this->_head;
}

int List::getSize() {
  return this->_size;
}

ListNode* List::traverseTo(int index) {
  if(index < 0 || index > this->_size) {
    cout << "Cannot traverse to " << index << endl;
    throw;
  } else {
    ListNode *ptr;
    ptr = this->_head;
  
    for(int i = 1; i < index; ++i) {
      ptr = ptr->getNext();
    }

    return ptr;
  }
}

void List::insert(int index, const int& newItem) {
  int newLength = this->_size + 1;

  if(index < 0 || index > newLength) {
    cout << "Cannot insert at " << index << endl;
    throw;
  } else {
    ListNode *ptr = new ListNode(newItem);
    this->_size = newLength;

    if(index == 1) {
      ptr->setNext(this->_head);
      this->_head = ptr;
    } else {
      ListNode* prev = traverseTo(index - 1);
      ptr->setNext(prev->getNext());
      ptr->setPrev(prev);
      prev->setNext(ptr);
      
      if(ptr->getNext() != NULL) {
        ptr->getNext()->setPrev(ptr);
      }
    }
  }
}

void List::remove(int index) {
  if(index < 0 || index > this->_size) {
    cout << "Cannot remove at " << index << endl;
    throw;
  } else {
    ListNode* ptr;
    this->_size--;

    if(index == 1) {
      ptr = this->_head;
      this->_head = (this->_head)->getNext();
    } else {
      ListNode *prev = traverseTo(index - 1);
      ptr = prev->getNext();
      prev->setNext(ptr->getNext());

      if(prev->getNext() != NULL) {
        prev->getNext()->setPrev(prev);
      }
    }

    delete ptr;
    ptr = NULL;
  }
}

void List::pushBack(const int& newItem) {
  ListNode* newPtr = new ListNode(newItem);
  ListNode* ptr;

  if(this->_size == 0) {
    this->_head = newPtr;
    newPtr->setPrev(this->_head);
  } else {
    ptr = traverseTo(this->_size);
    ptr->setNext(newPtr);
    newPtr->setPrev(ptr);
  }

  this->_size++;
}

void List::print() {
  ListNode* ptr;
  ptr = this->_head;

  while(ptr != NULL) {
    cout << ptr->getValue() << " ";

    ptr = ptr->getNext();
  }
  cout << endl;
}

int List::findIndexByValue(int value) {
  ListNode* ptr = this->_head;
  int index = 1;
  
  while(ptr != NULL) {
    if(ptr->getValue() == value) {
      return index;
    }

    ++index;
    ptr = ptr->getNext();
  }

  cout << "Cannot find " << value << endl;
  throw;
}
