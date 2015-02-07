#include <iostream>
#include <string>

using namespace std;

template <typename T1>
class Calculator {
  public:
    static T1 add(T1 a, T1 b) {
      return a + b;
    }

    static T1 sub(T1 a, T1 b) {
      return a - b;
    }

    static T1 mult(T1 a, T1 b) {
      return a * b;
    }

    static T1 div(T1 a, T1 b) {
      return a / b;
    }

    static T1 exp(T1 base, int exponent) {
      if(exponent == 0) {
        return 1;
      } else {
        return base * exp(base, exponent - 1);
      }
    }
};

int main() {
  // Part a
  cout << Calculator<double>::add(2.0, 5.5) << endl;
  cout << Calculator<double>::sub(5.8, 3.0) << endl;
  cout << Calculator<int>::mult(1, 2) << endl;
  cout << Calculator<float>::div(5, 2) << endl;

  // Part b
  cout << Calculator<double>::exp(5.3, 5) << endl;

  // Part c
  // Yes it'll still compile. String is still a valid data type and you can
  // add two strings together.
  cout << Calculator<string>::add("Hello", " World!") <<  endl;

  // Part d
  // No. While string is a valid data type, you can't divide two strings.
  // cout << Calculator<string>::div("Hello", " World!") << endl;
}
