#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include "Matrix.h"

void Matrix::swap_columns(int matrix[100][100]) {
  for (int i = 0; i < this->_matrix_size; ++i) {
    for (int j = 0; j < this->_matrix_size / 2; ++j) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[i][this->_matrix_size - 1 -j];
      matrix[i][this->_matrix_size - 1 -j] = tmp;
    }
  }

  return;
}

void Matrix::transpose(int matrix[100][100]) {
  for (int i = 0; i < this->_matrix_size; ++i) {
    for (int j = i + 1; j < this->_matrix_size; ++j) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = tmp;
    }
  }

  return;
}

void Matrix::rotate(int degree, int matrix[100][100]) {
  while (degree > 0) {
    this->transpose(matrix);
    this->swap_columns(matrix);
    degree -= 90;
  }

  return;
}

void Matrix::reflectX(int matrix[100][100]) {
  // transform the matrix by reflecting it across x-axis
  this->rotate(180, matrix);
  this->swap_columns(matrix);
  return;
}

void Matrix::reflectY(int matrix[100][100]) {
  // transform the matrix by reflecting it across y-axis
  this->swap_columns(matrix);
  return;
}

void Matrix::operate(string operation, string type, int matrix[100][100]) {
  if (operation == "Rotate") {
    this->rotate(atoi(type.c_str()), matrix);
  } else if (operation == "Reflect") {
    if (type == "y") {
      this->reflectY(matrix);
    } else {
      this->reflectX(matrix);
    }
  }

  return;
}

Matrix::Matrix(int matrix_size)
: _matrix_size(matrix_size) {

}
