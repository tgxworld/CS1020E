#include <iostream>
#include <sstream>
#include <set>

using namespace std;

void printArray(int array[], int arraySize) {
  stringstream ss;
  ss << "[";
  for(int i = 0; i < arraySize; ++i) {
    if(i != 0) { ss << ", "; }
    ss << array[i];
  }
  ss << "]";
  cout << ss.str() << endl;
}

void naive(int array[], int arraySize, int numOfRotation) {
  for(int i = 0; i < numOfRotation; ++i) {
    int temp = array[0];
    for(int j = arraySize - 1; j >= 0; --j) {
       array[(j + 1) % arraySize] = array[j]; 
    }
    array[1] = temp;
  }
}

void optimize(int array[], int arraySize, int numOfRotation) {
  int loop = 0;
  int currentIndex = numOfRotation % arraySize;
  int temp = array[loop];
  int next, tempIndexesSize;
  set<int> indexes;
  indexes.insert(currentIndex);

  while(loop != arraySize) {
    next = array[currentIndex];
    array[currentIndex] = temp;
    temp = next;    
 
    tempIndexesSize = indexes.size();
    currentIndex = (currentIndex + numOfRotation) % arraySize;
    indexes.insert(currentIndex);

    if(indexes.size() == tempIndexesSize) {
      currentIndex++;
      temp = array[currentIndex % arraySize];
      currentIndex = (currentIndex + numOfRotation) % arraySize;
    }

    loop++;
  }
}

int main() {
  int arraySize, numOfRotation;
  cin >> arraySize >> numOfRotation;

  int array[arraySize];

  for(int i = 0; i < arraySize; ++i) {
    array[i] = i + 1;
  }

  printArray(array, arraySize);
  //naive(array, arraySize, numOfRotation);
  //printArray(array, arraySize);
  optimize(array, arraySize, numOfRotation);
  printArray(array, arraySize);
 
  return 0;
}
