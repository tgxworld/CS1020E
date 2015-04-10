#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void knapSack(vector<int> items, int& count, int capacity) {
  if(capacity > 0 && items.size() != 0) {
    int front;
    front = items.front();
    vector<int>::iterator iter = items.begin();
    items.erase(iter);

    // Take the first item.
    if(capacity - front >= 0) {
      ++count;
      knapSack(items, count, capacity - front);
    }

    int next;
    next = items.front();

    if(capacity - next >= 0) {
      // Don't take the first item.
      knapSack(items, count, capacity);
    }
  }
}

int main() {
  int numberOfItems, capacity, input;
  cin >> numberOfItems >> capacity;
  vector<int> items;

  for(int i = 0; i < numberOfItems; ++i) {
    cin >> input;
    items.push_back(input);
  }

  // Sort the array first
  sort(items.begin(), items.end());

  // We can always choose not to pick
  int count = 1;

  // Start the recursion
  knapSack(items, count, capacity);

  cout << count << endl;
  return 0;
}
