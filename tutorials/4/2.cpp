#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int num;
  cin >> num;

  vector<int> numbers;

  for(int i =0; i < num; i++) {
    int input;
    cin >> input;
    
    bool duplicate = false;
    for(vector<int>::iterator iter = numbers.begin(); iter < numbers.end(); ++iter) {
      if(*iter == input) { duplicate = true; }
    }

    if(!duplicate) { numbers.push_back(input); }
  }

  sort(numbers.begin(), numbers.end());

  for(vector<int>::iterator iter = numbers.begin(); iter < numbers.end(); ++iter) {
    cout << *iter;
    if(iter + 1 == numbers.end()) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  
  return 0;
}
