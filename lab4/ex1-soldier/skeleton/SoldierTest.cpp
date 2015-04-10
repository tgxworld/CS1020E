#include <iostream>
#include "Soldier.h"
#include <queue>
#include <stack>

using namespace std;

void printQueue(queue<int> x) {
  int temp;
  while(!x.empty()) {
    temp = x.front();
    cout << temp << " ";
    x.pop();
  }
  cout << endl;
}

void printStack(stack<int> x) {
  int temp;
  while(!x.empty()) {
    temp = x.top();
    cout << temp << " ";
    x.pop();
  }
  cout << endl;
}

int main () {
  int n;
  cin >> n;
  int count = n;
  int input;

  while(cin >> input) {
    stack<int> soldierStack;
    stack<int> soldierHoldingStack;
    queue<int> soldierStartingQueue;
    count = n;
    int top;
    int holdingTop;

    soldierStack.push(input);

    for(int i = 1; i < n; ++i) {
      cin >> input;
      soldierStack.push(input);
    }

    while(!soldierStack.empty()) {
      if(!soldierStack.empty()) {
        top = soldierStack.top();
      } else {
        top = 0;
      }

      if(!soldierHoldingStack.empty()) {
        holdingTop = soldierHoldingStack.top();
      } else {
        holdingTop = 0;
      }

      if(top == count) {
        soldierStartingQueue.push(top);
        soldierStack.pop();
        count--;
      } else if(holdingTop == count) {
        soldierStartingQueue.push(holdingTop);
        soldierHoldingStack.pop();
        count--;
      } else {
        soldierHoldingStack.push(top);
        soldierStack.pop();
      }
    }

    count = n;

    // Just push all remaining into queue
    while(!soldierHoldingStack.empty()) {
      holdingTop = soldierHoldingStack.top();
      soldierStartingQueue.push(holdingTop);
      soldierHoldingStack.pop();
    }

    bool valid = true;

    while(count > 0) {
      holdingTop = soldierStartingQueue.front();

      if(count != holdingTop) {
        valid = false;
      }

      soldierStartingQueue.pop();
      count--;
    }

    if(valid) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
