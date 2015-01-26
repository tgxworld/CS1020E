#include <iostream>
using namespace std;

void sum1(int *a, int *b) {
  *a += *b + 1;
};

void sum2(int a, int b) {
  a += b + 1;
};

// Error here.
void sum3(int * & a, int * & b) {
  *a += *b + 1;
};

void sum4(int *x, int *y) {
  *x += *y + 1;
};

int main() {
  int *a = new int, *b = new int;
  *a = 0;
  *b = 1;

  // Error here a and b are pointers already.
  sum1(a, b);
  sum2(*a, *b);

  // Error here have to pass value in for pass by reference.
  sum3(b, a);

  // Error here a and b are pointers already
  sum4(a, b);
  sum3(*a, *b);

  cout << *a << " " << *b << endl;
  cout << &a << " " << &b << endl;
  cout << a << " " << b << endl;

  return 0;
}
