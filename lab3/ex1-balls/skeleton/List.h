#include "ListNode.h"

class List {
private:
  ListNode* _head;
  int _size;
public:
  List();
  ListNode* getHead();
  int getSize();
  void insert(int index, const int& newItem);
  void remove(int index);
  void pushBack(const int& newItem);
  ListNode* traverseTo(int index);
  int findIndexByValue(int value);
  void print();
};
