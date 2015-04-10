#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> intStack) {
  while(!intStack.empty()) {
    cout << intStack.top() << " ";
    intStack.pop();
  } 

  cout << endl;
}

void insertOrder(stack<int>& intStack, int value) {
  int temp;

  if(value < intStack.top()) {
    temp = intStack.top();
    intStack.pop();

    if(intStack.empty()) {
      intStack.push(value);
    } else {
      insertOrder(intStack, value);
    }

    intStack.push(temp);
  } else if(value >= intStack.top()) {
    intStack.push(value);
  }
}

void sortStack(stack<int>& intStack) {
  if(!intStack.empty()) {
    int temp = intStack.top();
    intStack.pop();
    sortStack(intStack);

    if(intStack.empty()) {
      intStack.push(temp);
    } else {
      insertOrder(intStack, temp);
    }
  }
}

void deleteNumber(stack<int>& intStack, int value) {
  if(intStack.top() == value) {
    intStack.pop();
    return;
  } else {
    int temp = intStack.top();
    intStack.pop();

    if(intStack.empty()) {
      return;
    } else {
      deleteNumber(intStack, value);
    }

    intStack.push(temp);
  }
}

int main() {
  stack<int> intStack;
  
  for(int i = 0; i < 5; ++i) {
    intStack.push(i);
  }

  insertOrder(intStack, -1);
  insertOrder(intStack, 5);
  insertOrder(intStack, -100);
  insertOrder(intStack, 100); 
  
  deleteNumber(intStack, 100);
  deleteNumber(intStack, -100);
  deleteNumber(intStack, 5);
  deleteNumber(intStack, -1);
    intStack.push(24);
    intStack.push(1231231);
    intStack.push(-1231);
    intStack.push(12453);
    intStack.push(1231532);

  printStack(intStack);
  sortStack(intStack);

  printStack(intStack);

  return 0;
}
