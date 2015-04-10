#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
  for(vector<int>::iterator iter = v.begin(); iter < v.end(); ++iter) {
    cout << *iter << " ";
  }

  cout << endl;
}

void merge(vector<int>& array, int low, int mid, int high) {
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

void mergeSort(vector<int>& array, int low, int high) {
  if(low < high) { 
    int mid = (low + high) / 2;

    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    merge(array, low, mid, high);
  }  
}

int main() {
  int N, input;
  cin >> N;
  vector<int> numbers;

  for(int i = 0; i < N; ++i) {
    cin >> input;
    numbers.push_back(input);
  }

  mergeSort(numbers, 0, N - 1);  
  int smallest, largest;

  if(numbers[N-1] < 0) {
    largest = numbers[N-1] * numbers[N-2] * numbers[N-3];
    smallest = numbers[0] * numbers[1] * numbers[2];
  } else if(numbers[N-1] == 0 && numbers[0] < 0) {
    largest = 0;
    smallest = numbers[0] * numbers[1] * numbers[2];
  } else if(numbers[N-1] > 0 && numbers[0] >= 0) {
    smallest = numbers[0] * numbers[1] * numbers[2];
    largest = numbers[N-1] * numbers[N-2] * numbers[N-3];
  } else if(numbers[N-1] > 0 && numbers[0] < 0) {
    if((numbers[0] * numbers[1]) > (numbers[N-1] * numbers[N-2])) {
      largest = numbers[0] * numbers[1] * numbers[N-1];
      smallest = numbers[0] * numbers[1] * numbers[2];
    } else {
      largest = numbers[N-1] * numbers[N-2] * numbers[N-3];
      smallest = numbers[0] * numbers[N-1] * numbers[N-2];
    } 
  }

  cout << smallest << " " << largest << endl;

	return 0;
}
