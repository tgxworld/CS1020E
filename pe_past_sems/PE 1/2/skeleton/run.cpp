#include <iostream>
#include <string>

using namespace std;

int N;

void printMatrix(bool matrix[10][10]) {
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cout << matrix[i][j] << " ";
    }

    cout << endl;
  }
}

int findPath(int sum, int universe[10][10], bool touched[10][10], int x, int y, int decades) {
  if(decades == 0) {
    return sum;
  } else {
    int sumDown = -9999999, sumUp = -999999, sumLeft = -999999, sumRight = -999999;

    if((y + 1) < N && !touched[x][y+1]) { 
      bool newTouched[10][10] = {false};

      for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
          newTouched[i][j] = touched[i][j];
        }
      }

      newTouched[x][y+1] = true;

      sumRight = findPath(sum + universe[x][y+1], universe, newTouched, x, y + 1, decades - 1);
    } else {
      sumRight = -999999;
    }

    if((y - 1) >= 0 && !touched[x][y-1]) {
      bool newTouched[10][10] = {false};

      for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
          newTouched[i][j] = touched[i][j];
        }
      }

      newTouched[x][y-1] = true;
      sumLeft = findPath(sum + universe[x][y-1], universe, newTouched, x, y - 1, decades - 1);
    } else {
      sumLeft = -999999;
    }

    if((x + 1) < N && !touched[x+1][y]) {
      bool newTouched[10][10] = {false};

      for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
          newTouched[i][j] = touched[i][j];
        }
      }

      newTouched[x+1][y] = true;
      sumDown = findPath(sum + universe[x+1][y], universe, newTouched, x + 1, y, decades - 1);
    } else {
      sumDown = -999999;
    }

    if((x - 1) >= 0 && !touched[x-1][y]) {
      bool newTouched[10][10] = {false};

      for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
          newTouched[i][j] = touched[i][j];
        }
      }
      newTouched[x-1][y] = true;
      sumUp = findPath(sum + universe[x-1][y], universe, newTouched, x -1, y, decades - 1);
    } else {
      sumUp = -999999;
    }
    
    int sums[4] = {sumDown, sumUp, sumLeft, sumRight};
    int max = sums[0];

    for(int i = 1; i < 4; ++i) {
      if(sums[i] > max) {
        max = sums[i];
      }
    }

    return max;  
  }
}

int main() {
  cin >> N;

  int universe[10][10];
  bool touched[10][10] = {false};
  int x, y;

  string input;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cin >> input;

      if(input == "*") {
        x = i;
        y = j;
        touched[i][j] = true;
        universe[i][j] = 0;
      } else {
        universe[i][j] = stoi(input);
      }      
    }
  }

  cout << findPath(0, universe, touched, x, y, 10) << endl;

  return 0;
}
