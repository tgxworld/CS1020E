#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, input;
  cin >> N;
  vector<int> integers;

  for(int i = 0; i < N; ++i) {
    cin >> input;
    integers.push_back(input);
  }

  int count = 0;

  for(int i = 0; i < N; ++i) {
    int sum = 0;

    for(int j = i; j < N; ++j) {
      sum += integers[j];
      
      if(sum > 0) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
