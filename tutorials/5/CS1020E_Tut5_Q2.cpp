#include <iostream>
#include <sstream>
#include "List.cpp"
using namespace std;

// reverse linked list
void List::reverse() {
	// Implement your algorithm here:
    
	
} // end of reverse method 

int main() {
	//Input:
  List list;
  int input;
  while(cin >> input) {
    list.push_back(input);
  }
	
	//Do the job:
  list.reverse();
	
	//Output:
  cout << list.toString() << endl;
	
	return 0;
}

