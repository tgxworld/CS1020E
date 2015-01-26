#include <iostream>
#include <string>
using namespace std;
#include "Matrix.h"

int main() {
  // read input and create the Matrix object
  int matrix_size;
  cin >> matrix_size;

  int matrix[100][100];

  for(int row = 0; row < matrix_size; ++row) {
    for(int column = 0; column < matrix_size; ++column) {
      cin >> matrix[row][column];
    }
  }

  Matrix matrix_magigican(matrix_size);

  int operations;
  cin >> operations;

  for(int num = 0; num < operations; ++num) {
    string operation, type;
    cin >> operation;
    cin >> type;
    matrix_magigican.operate(operation, type, matrix);
  }

  for(int row = 0; row < matrix_size; ++row) {
    for(int column = 0; column < matrix_size; ++column) {
      cout << matrix[row][column];
      if (column != (matrix_size - 1)) {
        cout << " ";
      }
    }

    cout << endl;
  }

  return 0;
}
