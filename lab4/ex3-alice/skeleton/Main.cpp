#include <iostream>
#include <stack>
#include <queue>
#include "Pancake.h"
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  stack<Pancake*> pancakeStack;

  for(int i = 0; i < N; ++i) {
    Pancake* ptr = new Pancake();
    pancakeStack.push(ptr);
  }

  for(int i = 0; i < Q; ++i) {
    string operation;
    cin >> operation;
    queue<Pancake*> pancakeQueue;

    if(operation == "FLIP") {
      int count;
      cin >> count;
      int temp = count;

      while(temp != 0) {
        Pancake* ptr = pancakeStack.top();
        ptr->toggleOrientation();

        if(temp == 1) {
          if(ptr->getOrientation() == "up") {
            ptr->setTopSweet();
          } else {
            ptr->setBtmSweet();
          }
        }

        pancakeQueue.push(ptr);
        pancakeStack.pop();
        --temp;
      }

      temp = count;

      while(temp != 0) {
        if(temp == count) {
          Pancake* ptr = pancakeQueue.front();

          if(!pancakeStack.empty()) {
            Pancake* stackPtr = pancakeStack.top();

            if((stackPtr->getOrientation() == "up" && stackPtr->getTopSweet())
              || (stackPtr->getOrientation() == "down" && stackPtr->getBtmSweet())
              || (ptr->getOrientation() == "up" &&  ptr->getBtmSweet()) 
              || (ptr->getOrientation() == "down" && ptr->getTopSweet())) {             
              ptr->setReverseOrientationSweet();
              stackPtr->setOrientationSweet();
            }
          }
        }

        pancakeStack.push(pancakeQueue.front());
        pancakeQueue.pop();
        --temp;
      }
    } else if(operation == "COUNT") {
      stack<Pancake*> tempPancakeStack;
      int count = 0;
       
      while(!pancakeStack.empty()) {
        Pancake* ptr = pancakeStack.top();

        if(ptr->getTopSweet() || ptr->getBtmSweet()) {
          ++count;
        }
  
        tempPancakeStack.push(ptr);
        pancakeStack.pop();
      }

      while(!tempPancakeStack.empty()) {
        pancakeStack.push(tempPancakeStack.top());
        tempPancakeStack.pop();
      }
    
     cout << count << endl;
    } else if(operation == "ADD") {
      Pancake* ptr = new Pancake();
      Pancake* stackPtr = pancakeStack.top();
   
      if(stackPtr->getOrientation() == "up" && stackPtr->getTopSweet()) {
        ptr->setBtmSweet();
      } else if(stackPtr->getOrientation() == "down" && stackPtr->getBtmSweet()) {
        ptr->setBtmSweet();
      }

      pancakeStack.push(ptr);
    }
  }

	return 0;
}
