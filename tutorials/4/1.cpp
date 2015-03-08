#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> intVector;

  for(int i = 0; i != 5; ++i) {
    intVector.push_back(i);
  }

  vector<int>::iterator myIter = intVector.begin();
  
  for(int j = 0; j != 3; ++j) {
    myIter++;
  }

  intVector.erase(myIter);
  cout << *myIter << endl;

  vector<int> intVector2;
  
  for(int i = 0; i != 5; ++i) {
    intVector2.push_back(i);
  }

  int *myIter2 = intVector2.begin();
  intVector2.insert(myIter2, -1); // Invalid, insert requires an iterator not just a int pointer
}
