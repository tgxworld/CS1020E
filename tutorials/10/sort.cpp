#include <iostream>

using namespace std;

void printArray(int array[], int size) {
  for(int i = 0; i < size; ++i) {
    cout << array[i] << " "; 
  } 

  cout << endl;
}

void selectionSort(int array[], int size) {
  for(int i = 0; i < size; ++i) {
    int maxIndex = i;

    for(int j = i + 1; j < size; ++j) {
      if(array[j] <= array[maxIndex]) 
        maxIndex = j;
    }

    int temp = array[maxIndex];
    array[maxIndex] = array[i];
    array[i] = temp;
  }

  cout << "Selection Sort: ";
  printArray(array, size);
}

void bubbleSort(int array[], int size) {
  int temp;

  for(int i = size - 1; i > 0; --i) {
    for(int j = 0; j < i; ++j) {
      if(array[j] >= array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    } 
  } 

  cout << "Bubbble Sort: " ;
  printArray(array, size);
}

void insertionSort(int array[], int size) {
  for(int i = 1; i < size; ++i) {
    int next = array[i];
    int j;

    for(j = i -1; j >= 0 && array[j] > next; --j) {
      array[j + 1] = array[j];
    }

    array[j + 1] = next;
  }  

  cout << "Insertion Sort: ";
  printArray(array, size);
 }

void merge(int array[], int low, int mid, int high) {
  int n = high - low + 1;
  int* b = new int[n];
  int left = low, right = mid + 1; 
  int bIndex = 0;

  while(left <= mid && right <= high) {
    if(array[left] <= array[right]) {
      b[bIndex] = array[left];
      bIndex++;
      left++;
    } else {
      b[bIndex] = array[right];
      bIndex++;
      right++;
    }
  }

  while(left <= mid) { b[bIndex] = array[left]; bIndex++; left++; }
  while(right <= high) { b[bIndex] = array[right]; bIndex++; right++; }

  for(int i = 0; i < n; ++i) {
    array[low + i] = b[i];
  }

  delete [] b;
}

void mergeSort(int array[], int low, int high) {
  if(low < high) { 
    int mid = (low + high) / 2;

    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    merge(array, low, mid, high);
  }  
}

int partition(int array[], int low, int high) {
  int pivotValue = array[low];
  int m = low;
  int temp;

  for(int i = m + 1; i <= high; ++i) {
    if(array[i] < pivotValue) {
      ++m;
      temp = array[m];
      array[m] = array[i];
      array[i] = temp;
    }
  }

  temp = array[m];
  array[low] = temp;
  array[m] = pivotValue;

  return m;
}

void quickSort(int array[], int low, int high) {
  int pivotIndex;
  
  if(low < high) {
    pivotIndex = partition(array, low, high);
    
    quickSort(array, low, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, high);
  }
}

#include <queue>
#include <vector>

void distribute(vector<int>& v, queue<int> digitQ[], int power) {
  int digit;
  
  for(int i = 0; i < v.size(); ++i) {
    digit = (v[i] / power) % 10;
    digitQ[digit] .push(v[i]);
  }  
}

void collect(queue<int> digitQ[], vector<int>& v) {
  int i = 0, digit;
  
  for(digit = 0; digit < 10; digit++) {
    while(!digitQ[digit].empty()) {
      v[i] = digitQ[digit].front();
      digitQ[digit].pop();
      ++i;
    }
  }
}

void radixSort(vector<int>& v, int size) {
  int power = 1;
  queue<int> digitQueue[10];

  for(int i = 0; i < size; ++i) {
    distribute(v, digitQueue, power);
    collect(digitQueue, v);
    power *= 10;
  }
}

int main() {
  int arr[10] = { 1, 5, 10, 3, 4, 9, 8, 6, 7, 2 };
  selectionSort(arr, 10);

  int arr2[10] = { 1, 5, 10, 3, 4, 9, 8, 6, 7, 2 };
  bubbleSort(arr2, 10);

  int arr3[10] = { 1, 5, 10, 3, 4, 9, 8, 6, 7, 2 };
  insertionSort(arr3, 10);

  int arr4[10] = { 1, 5, 10, 3, 4, 9, 8, 6, 7, 2 };
  mergeSort(arr4, 0, 9);
  cout << "Merge Sort: ";
  printArray(arr4, 10);

  int arr5[13] = { 1, 5, 10, 2051, 12, 0, 3, 4, 9, 8, 6, 7, 2 };
  quickSort(arr5, 0, 12);
  cout << "Quick Sort: ";
  printArray(arr5, 13);

  vector<int> arr6;
  arr6.push_back(13);
  arr6.push_back(5);
  arr6.push_back(50);
  radixSort(arr6, 3);

  cout << "Radix Sort: ";
  for(int i = 0; i < 3; ++i) {
    cout << arr6[i] << " ";
  }
  cout << endl;
  return 0;
}
