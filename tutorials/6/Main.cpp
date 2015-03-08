#include <iostream>
#include "List.h"

using namespace std;

int main() {
  int k, item;
  cin >> k;
  List list(k);
 
  while(cin >> item) {
    list.pushBack(item);
  }

  list.printList();

  int a = 100;
  list.insertKListNode(5, a);
  list.printList();

  int b = 200;
  list.insertKListNode(1, b);
  list.printList();

  int c = 300;
  list.insertKListNode(8, c);
  list.printList();

  list.removeKListNode(1);
  list.printList();

  list.removeKListNode(8);
  list.printList();

  return 0;
}
