#include <iostream>
using namespace std;

int main() {
  int a = -1, b = 1, c = 1, d = 0, e = 2, f = 2;
  int i = f-- && e++ && d++ && c-- || b++ || a++;

  cout << a << b << c << d << e << f << i << endl;
  return 0;
}
