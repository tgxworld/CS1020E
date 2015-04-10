#include <iostream>
using namespace std;

void printMatrix(unsigned long long matrix[2][2]) {
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      cout << matrix[i][j];

      if(j < 1) {
        cout << " ";
      }
    }

    cout << endl;
  }
}

void sumMatrix(unsigned long long matrix[2][2], unsigned long long matrix2[2][2]) {
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      matrix[i][j] = matrix[i][j] + matrix2[i][j];
    }
  }
}

void powerMatrix(unsigned long long base[2][2], unsigned long long matrix[2][2], int N, int M) {
  N--;
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      matrix[i][j] = base[i][j];
    }
  }

  unsigned long long hmatrix[2][2];

  while(N != 0) {
    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
        hmatrix[i][j] = matrix[i][j] % M;
      }
    }

    matrix[0][0] = hmatrix[0][0] * base[0][0] + hmatrix[0][1] * base[1][0];
    matrix[1][0] = hmatrix[1][0] * base[0][0] + hmatrix[1][1] * base[1][0];
    matrix[0][1] = hmatrix[0][0] * base[0][1] + hmatrix[0][1] * base[1][1];
    matrix[1][1] = hmatrix[1][0] * base[0][1] + hmatrix[1][1] * base[1][1];

    N--;
  }
}

void computeMatrix(unsigned long long base[2][2], unsigned long long matrix[2][2], int N, int M) {
  if(N == 0) {
    return;
  } else {
    unsigned long long tempMatrix[2][2] = {{0,0},{0,0}};
    powerMatrix(base, tempMatrix, N, M);
    computeMatrix(base, matrix, N-1, M);
    sumMatrix(matrix, tempMatrix);
  }
}

void minifyMatrix(unsigned long long matrix[2][2], int M) {
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      matrix[i][j] = matrix[i][j] % M;
    }
  }
}

int main() {
  unsigned long long matrix[2][2] = {{0, 0},{0, 0}};
  unsigned long long base[2][2];
  unsigned long long identity[2][2] = {{1, 0}, {0, 1}};
  int input;

  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      cin >> input;
      base[i][j] = input;
    }
  }

  int N, M;
  cin >> N >> M;

  computeMatrix(base, matrix, N, M);
  sumMatrix(matrix, identity);
  minifyMatrix(matrix, M);
  printMatrix(matrix);
  cout << endl;

	return 0;
 }
