#include <iostream>
#include <sstream>
#include "ListNode.cpp"
using namespace std;

class List { 
	
	private: 
		ListNode* _head;
    int _size;

	public: 
		ListNode* traverseTo( int index ) {
      if( index < 0 || index > this->_size) {
        return NULL;
      } else {
        ListNode *ptr;
        ptr = this->_head;

         for(int i = 1; i < index; ++i) {
           ptr = ptr->getNext();
         }
  
         return ptr;
      }
    }

		List(){ _head = NULL; this->_size = 0; }

		bool insert( int index, const int& newItem) {
      int newLength = this->_size + 1;

      if(index < 1 || index > newLength) {
        return false;
      } else {
        ListNode *ptr = new ListNode(newItem, NULL);
        this->_size = newLength;

        if(index == 1) {
          ptr->setNext(_head);
          _head = ptr;
        } else {
          ListNode *prev = traverseTo(index - 1);
          ptr->setNext(prev->getNext());
          prev->setNext(ptr);
        }
      }
        
      return true;
    }
		
		bool remove( int index ) {
      if(index < 1 || index > this->_size) {
        return false;
      } else {
        ListNode *ptr;
        --this->_size;

        if(index == 1) {
          ptr = this->_head;
          _head = (this->_head)->getNext();
        } else {
          ListNode *prev = traverseTo(index - 1);
          ptr = prev->getNext();
          prev->setNext(ptr->getNext());
        }

        delete ptr;
        ptr = NULL;
      }
    }
 
		bool retrieve( int index, int& dataItem ) {
      if(index < 1 || index > this->_size) { return false; }

      ListNode *ptr;

      ptr = this->traverseTo(index);
      dataItem = ptr->getItem();

      return true;
    } 

		// add node to the end of linked list
		bool push_back(int& newItem)
		{
			ListNode *ptr;
			ListNode *newPtr = new ListNode(newItem, NULL);
			ptr = _head;
			if(ptr == NULL){
				newPtr->setNext(_head);
				_head = newPtr;
			}
			else {
				while (ptr->getNext() != NULL){
					ptr = ptr->getNext();
				}
				ptr->setNext(newPtr);
			}

      this->_size++;
		}

		ListNode* getHead() {return _head;}
		void setHead(ListNode* head) {_head = head;	}

		string toString(){
			ostringstream os; 
			ListNode *cur; 
			os << "[ "; 
			for( cur = _head; cur != NULL; cur = cur->getNext() ) 
			{ os << cur->getItem() << " "; }os << "]";
			return os.str();
		}
		
		// method to be implemented q1
		void sort();			
		ListNode* merge(ListNode* head2);
		
		// method to be implemented q2
		void reverse();
				
		// method to be implemented q3
		void swap(int u, int v);		
		void makeSawTooth();
		
};
