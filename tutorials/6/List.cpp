#include <iostream>
#include <sstream>
#include "List.h"

using namespace std;

List::List(int skipInt) {
  this->_size = 0;
  this->_head = NULL;
  this->_skipInt = skipInt;
}

KListNode* List::traverseTo(int index) {
  if(index < 0 || index > this->_size) {
    return NULL;
  } else {
    KListNode* ptr;
    ptr = this->_head;

    for(int i = 1; i < index; ++i) {
      if(index - i >= this->_skipInt) {
        ptr = ptr->getKNext();
        i += this->_skipInt - 1;
      } else {
        ptr = ptr->getNext();
      }
    }

    return ptr;  
  }
}

bool List::insertKListNode(int index, const int& newItem) {
  int newLength = this->_size + 1;

  if(index < 1 || index > newLength) {
    return false;
  } else {
    KListNode* ptr = new KListNode(newItem, this->_skipInt);
    KListNode* cur;
    this->_size = newLength;

    if(index == 1) {
      ptr->setNext(this->_head);

      cur = ptr;
      for(int i = 0; i < this->_skipInt; ++i) {
        cur = cur->getNext();          
      }
      ptr->setKNext(cur);

      this->_head = ptr;
    } else {
      KListNode* prev = this->traverseTo(index - 1);
      ptr->setNext(prev->getNext());
      prev->setNext(ptr);

      int range = this->_size - this->_skipInt;

      if(range > 0) {
        ptr = this->_head;
        while(ptr->getNext() != NULL && range != 0) {
          cur = ptr;
          for(int i = 0; i < this->_skipInt; ++i) {
            cur = cur->getNext();
          }
          ptr->setKNext(cur);
          ptr = ptr->getNext();
          range--;
        }
      }
    }
  }

  return true;
}

bool List::removeKListNode(int index) {
  if(index < 1 || index > this->_size) {
    return false;
  } else {
    KListNode* ptr;
    if(index == 1) {
      ptr = this->_head;
      _head = (this->_head)->getNext();
    } else {
      KListNode *prev = traverseTo(index - 1);
      ptr = prev->getNext();
      prev->setNext(ptr->getNext());
      
      int range = this->_size - this->_skipInt;  
      
      KListNode* newPtr;
      if(range > 0) {
        newPtr = this->_head;
        int i = 1;
        
        while(newPtr != NULL && i <= range) {
          int rangeIndex = i + this->_skipInt;

          if(rangeIndex >= index) {
            if(rangeIndex >= this->_size) {
              newPtr->setKNext(NULL);
            } else {
              KListNode* cur;
              cur = newPtr;
              for(int i = 0; i < this->_skipInt; ++i) {
                cur = cur->getNext();
              }
              newPtr->setKNext(cur);
            }
          }       

          newPtr = newPtr->getNext();
          i++;
        }
      }
    }

    delete ptr;
    ptr = NULL;
    --this->_size;
  }

  return true;
} 

void List::pushBack(int &item) {
  KListNode *ptr;
  KListNode *newPtr = new KListNode(item, this->_skipInt);
  ptr = this->_head;

  if(ptr == NULL) {
    newPtr->setNext(this->_head);
    this->_head = newPtr;
    this->_size++;
  } else {
    ptr = this->traverseTo(this->_size);
    ptr->setNext(newPtr);
    this->_size++;

    int prevKIndex = this->_size - this->_skipInt;

    if(prevKIndex > 0) {
      KListNode* prevPtr = this->traverseTo(prevKIndex);
      prevPtr->setKNext(newPtr);
    }    
  }
}

void List::printList() {
  ostringstream os;
  os << "[ ";
  KListNode* curr;

  for(curr = this->_head; curr !=  NULL; curr = curr->getNext()) {
    os << curr->getItem();
    
    if(curr->getKNext() != NULL) { os << "/" << curr->getKNext()->getItem(); }

    os << " ";
  }
  os << "]";

  cout << os.str() << endl;
}
