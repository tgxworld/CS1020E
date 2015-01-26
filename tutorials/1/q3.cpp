#include <iostream>
using namespace std;

struct Message {
  string s;
  Message *next;
};

int main() {
  Message mess[6] = {
    { "FUN", &mess[1] },
    { "CS", &mess[3] },
    { "is ", &mess[0] },
    { "10", &mess[4] },
    { "20", &mess[5] },
    { "E ", &mess[2] }
  };

  Message *m = &mess[1];

  for(int i = 0; i < 6; ++i) {
    cout << (*m).s;
    if(i == 5) cout << endl;
    m = (*m).next;
  }

  return 0;
}
