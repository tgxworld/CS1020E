#include <iostream>
#include <string>

using namespace std;

int main() {
  int rows, columns;
  cin >> rows;
  cin >> columns;
  int matrix[columns][rows];

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      cin >> matrix[j][i];
    }
  }

  string type;
  int num;
  cin >> type;
  cin >> num;

  int sum = 0;

  if(type == "COLUMN") {
    for(int i = 0; i < rows; i++) {
      sum = sum + matrix[num - 1][i];
    }
  } else if(type == "ROW") {
    for(int i = 0; i < columns; i++) {
      sum = sum + matrix[i][num - 1];
    }
  }

  cout << sum << "\n";

  return 0;
}
