#include <iostream>
#include <sstream>
#include "List.cpp"
#include <vector>
using namespace std;

void List::sort(){
	// Implement your algorithm here:
  for(int i = 1; i <= this->_size; ++i) {
    ListNode *min;
    ListNode *base;

    base = this->traverseTo(i);
    min = this->traverseTo(i);
    int minItem = min->getItem();

    for(int j = i; j <= this->_size; j++) {
      ListNode *current = this->traverseTo(j);
      int currentItem = current->getItem();

      if(currentItem < minItem) {
        min = current;
        minItem = currentItem;
      }
    }

    if(min != base) {
      int baseItem = base->getItem();

      base->setItem(minItem);
      min->setItem(baseItem);
    } 
  }
} // end of sort method.


// merge two sorted linked lists and return the head of the sorted linked list
ListNode* List::merge(ListNode* head2){
	// Implement your algorithm here:
  ListNode *head1 = this->_head;
  int head1Index = 1;
  bool breaker = true;

  while(breaker) {
    if(head2->getNext() == NULL && head1->getNext() == NULL) { breaker = false; }

    if(head1->getItem() <= head2->getItem()) {
      if(head1->getNext() != NULL && head2->getItem() <= head1->getNext()->getItem()) {
        int item = head2->getItem();
        head2 = head2->getNext();
        //cout << head2;
        this->insert(head1Index + 1, item);
        //cout << head2;
      } else if(head1->getNext() == NULL) {
        int item = head2->getItem();
        head2 = head2->getNext();
        this->insert(head1Index + 1, item);
      }
    }
  
    head1 = head1->getNext();
    head1Index++;

    if(!head2) { break; }
  }
} // end of merge method

void List::swap(int u, int v) {
  ListNode *uNext, *vNext, *uPtr, *vPtr, *uPrev, *vPrev;

  uPtr = this->traverseTo(u);
  vPtr = this->traverseTo(v);
  uNext = this->traverseTo(u + 1);
  vNext = this->traverseTo(v + 1);

  if(u == 1) {
    uPrev = this->_head;
  } else {
    uPrev = this->traverseTo(u - 1);
  }

  vPrev = this->traverseTo(v - 1);

  uPtr->setNext(vNext);
  vPtr->setNext(uNext);

  if(u == 1) {
    this->_head = vPtr;
  } else {
    uPrev->setNext(vPtr);
  }

  vPrev->setNext(uPtr);
}

void List::reverse() {
  ListNode *headPtr = this->traverseTo(this->_size);

  for(int i = this->_size; i > 0; --i) {
    if(i == 1) {
      ListNode *ptr = this->traverseTo(i);
      ptr->setNext(NULL);
    } else {
      ListNode *ptr = this->traverseTo(i);
      ptr->setNext(this->traverseTo(i - 1));
    }  
  }

  this->_head = headPtr;
}

void List::makeSawTooth() {
    
} 

int main() {
	//Input:
  List list;
  List list2;
  int input;

  while(cin >> input) {
    list.push_back(input);
  }
 
  int input2 = 20; 
  list2.push_back(input2);
  input2 = 100;
  list2.push_back(input2);

	//Do the jobs:
  list.sort();
  list.merge(list2.getHead());
  list.reverse();
  list.swap(2, 6);
	
	//Output:
  cout << list.toString() << endl;	

	return 0;
}

