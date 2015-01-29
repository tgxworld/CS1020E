#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
  // read input
  int land_size;
  cin >> land_size;

  bool array[80][80] = { { false } };

  int num_of_trees;
  cin >> num_of_trees;

  for(int i = 0; i < num_of_trees; ++i) {
    int row, column;
    cin >> row >> column;
    array[row - 1][column - 1] = true;
  }

  int largest_square = 1;

  for(int i = 0; i < land_size; ++i) {
    for(int j = 0; j < land_size; ++j) {
      if(array[i][j] != true) {
        int max_width = ((land_size - i) < (land_size - j)) ? (land_size - i) : (land_size - j);

        for(int width = max_width; width > 0; --width) {
          bool valid = true;

          for(int k = i; k < i + width; ++k) {
            for(int z = j; z < j + width; ++z) {

              if(array[k][z] == true) {
                valid = false;
              }
            }
          }

          if(valid && (width > largest_square)) {
            largest_square = width;
          }
        }
      }
    }
  }

  cout << largest_square << endl;

  return 0;
}
