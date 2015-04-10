#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int M, T, U, F, D;
  cin >> M >> T >> U >> F >> D;
  vector<int> timings;
  string path;
  int timing;

  for(int i = 0; i < T; ++i) {
    cin >> path;

    if(path == "u" || path == "d") {
      timing = U + D;
      timings.push_back(timing);
    } else if(path == "f") {
      timing = F * 2;
      timings.push_back(timing);
    }
  }

  int units = 0;

  for(int i = 0; i < T; ++i) {
    timing = timings[i];
    M -= timing;

    if(M < 0) {
      break;
    } else if(M == 0) {
      ++units;
      break;
    } else {
      ++units;
    }
  }
  
  cout << units << endl;  

  return 0;
}
