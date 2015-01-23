#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;

  cin >> a;
  cin >> b;

  int compare;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);
  compare = a.compare(b);

  if (compare == 0) {
    cout << 0 << "\n";
  } else if(compare > 0) {
    cout << 2 << "\n";
  } else if(compare < 0) {
    cout << 1 << "\n";
  }

  return 0;
}
