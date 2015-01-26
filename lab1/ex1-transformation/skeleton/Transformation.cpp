#include <iostream>
#include <string>
#include "Matrix.h"

int main() {
  // read input and create the Matrix object
  int matrix_size;
  cin >> matrix_size;

  int matrix[matrix_size][matrix_size];

  for(int row = 0; row < matrix_size; ++row) {
    for(int column = 0; column < matrix_size; ++column) {
      cin >> matrix[row][column];
      cout << matrix[row][column];
    }
  }


  // for each operation, process the matrix

  // output the final matrix
  return 0;
}
