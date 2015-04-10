#include <iostream>
#include <vector>
using namespace std;

int choose(vector<int> sticks, int desiredLength, int count) {
  if(desiredLength == 0) {
    return count;
  } else if(desiredLength < 0) {
    return -1;
  } else if(desiredLength > 0 && sticks.empty()) {
    return -1;
  } else {
    int temp, returnCount1, returnCount2;
    temp = sticks.back();
    sticks.pop_back();

    // Choose last item
    returnCount1 = choose(sticks, desiredLength - temp, count + 1);
  
    // Don't Choose
    returnCount2 = choose(sticks, desiredLength, count);
    
    if(returnCount1 < returnCount2 && returnCount1 != -1) {
      return returnCount1;
    } else if(returnCount2 < returnCount1 && returnCount2 != -1) {
      return returnCount2;
    } else if(returnCount1 == -1 && returnCount2 != -1) {
      return returnCount2;
    } else if(returnCount2 == -1 && returnCount1 != -2) {
      return returnCount1;
    }
  }
}

int main() {
  int numberOfSticks, desiredLength;
  cin >> numberOfSticks >> desiredLength;
  vector<int> sticks;
  int input;

  for(int i = 0; i < numberOfSticks; ++i) {
    cin >> input;
    sticks.push_back(input); 
  }

  cout << choose(sticks, desiredLength, 0) << endl; 

	return 0;
}
