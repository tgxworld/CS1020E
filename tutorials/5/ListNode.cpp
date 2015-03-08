#include <iostream>
#include <sstream>
using namespace std;

class ListNode{
private: 
		int item;
		ListNode *next;
public:
    ListNode();
		ListNode(int v, ListNode* n) { item = v; next = n; }
		void setNext(ListNode* n) { next = n; }
		ListNode* getNext() { return next; }
		int getItem() { return item; }
		void setItem(int value) { item = value; }
};
