#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class HelloWorld {
public:
  // Pre-condition: `type` must be a integer between 1..3.
  // Post-condition: Initialize object attribute `_type`.
  HelloWorld(int type) {
    _type = type;
  }

  // Pre-condition: None.
  // Post-condition: Call methods depending on value of  `_type`.
  void process() {
    switch(_type) {
      case 1:
        process_type_1();
        break;
      case 2:
        process_type_2();
        break;
      case 3:
        process_type_3();
        break;
    }
  }

private:
  int _type;

  // Pre-Condition: None.
  // Post-Condition: Prints out output.
  void process_type_1() {
    int num_of_lines;
    cin >> num_of_lines;

    for(int i = 1; i <= num_of_lines; i++) {
      string binary_operator, first_operand, second_operand;
      read_input(binary_operator);
      read_input(first_operand);
      read_input(second_operand);
      process_operands(binary_operator, first_operand, second_operand);
    }
  }

  void process_type_2() {
    string binary_operator, first_operand, second_operand;

    while (read_input(binary_operator) != "0") {
      read_input(first_operand);
      read_input(second_operand);
      process_operands(binary_operator, first_operand, second_operand);
    }
  }

  void process_type_3() {
    string binary_operator, first_operand, second_operand;

    while (cin >> binary_operator) {
      read_input(first_operand);
      read_input(second_operand);
      process_operands(binary_operator, first_operand, second_operand);
    }
  }

  string read_input(string &variable) {
    cin >> variable;
    return variable;
  }

  void process_operands(string binary_operator, string first_operand, string second_operand) {
    bool output;

    if (binary_operator == "AND") {
      output = (atoi(first_operand.c_str()) && atoi(second_operand.c_str()));
    } else if (binary_operator == "OR") {
      output = (atoi(first_operand.c_str()) || atoi(second_operand.c_str()));
    }

    cout << output << "\n";
  }
};

int main() {
  // read input
  int type;
  cin >> type;

  HelloWorld hello_world(type);
  hello_world.process();

  return 0;
}
