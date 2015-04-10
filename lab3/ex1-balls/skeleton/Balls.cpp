#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  int numBalls, numOperations;
  cin >> numBalls >> numOperations;
  List list;  

  for(int i = 1; i <= numBalls; ++i) {
    list.pushBack(i);
  }

  while(numOperations != 0) {
    char operation;
    cin >> operation;
    int x, y, xIndex, yIndex;   
 
    switch(operation) {
      case 'A':
        cin >> x >> y;
        xIndex = list.findIndexByValue(x);
        yIndex = list.findIndexByValue(y);

        if(xIndex != yIndex - 1) {
          list.remove(xIndex);
          yIndex = list.findIndexByValue(y);
          list.insert(yIndex, x); 
        }
       
        break;
      case 'B':
        cin >> x >> y;
        xIndex = list.findIndexByValue(x);
        yIndex = list.findIndexByValue(y);

        if(xIndex != yIndex + 1) {
          list.remove(xIndex);
          yIndex = list.findIndexByValue(y);
          list.insert(yIndex + 1, x);
        }
        
        break;
      case 'R':
        cin >> x;
        xIndex = list.findIndexByValue(x);
        list.remove(xIndex);
        break;
    }

    --numOperations;
  }

  list.print();

  return 0;
}
