#include <iostream>
#include <string>
#include "myStack.cpp"
using namespace std;

int getPrecedence(char op) {
  int weight = -1;

  if(op == '+' || op == '-') { weight = 1; }
  if(op == '*' || op == '/') { weight = 2; }
  
  return weight;
}

int main() {	
	//Input:
  string infix = "";
  string input;
  while(cin >> input) {
    infix += input;
  }

	//Do the job:
  Stack<char> stack;
  string postfix = "";

  for(string::iterator iter = infix.begin(); iter < infix.end(); ++iter) {
    if(isdigit(*iter)) {
      postfix += *iter;
    } else if(*iter == '(') {
      stack.push(*iter);
    } else if(*iter == ')') {
      while(!stack.isEmpty() && stack.peek() != '(') {
        postfix += stack.pop();
        stack.pop();
      }
    } else {
      while(!stack.isEmpty() && stack.peek() != '(' && getPrecedence(*iter) <= getPrecedence(stack.peek())) {
        postfix += stack.pop();
      }
       stack.push(*iter);
    }
  }
	//Output:
  while(!stack.isEmpty()) {
    postfix += stack.pop();
  }

  cout << postfix << endl;
	
	return 0;
}
