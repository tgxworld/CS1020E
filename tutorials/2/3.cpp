#include <iostream>

// int add(int a, int b) {
//   return a + b;
// }

double add(double a, double b) {
  return a + b;
 }

double add(int a, int b) {
  return a + b;
}

void swap(int a, int b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int main() {
  add(1, 2); // Need to modify function to return double or change parameters to double
  add(3.0, 4); // Both have to be either int or double
  add(5, 6.0); // Both have to be either int or double
  add(7.0, 8.0);

  return 0;
}
