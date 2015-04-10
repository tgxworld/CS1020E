#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void knapSack(vector<int> items, int& count, int sum, int capacity) {
  if(sum != capacity && items.size() != 0) {
    int front;
    front = items.front();
    vector<int>::iterator iter = items.begin();
    items.erase(iter);

    // Take the first item.
    if((sum + front) <= capacity) {
      ++count;
      knapSack(items, count, sum + front, capacity);
    }


    int next;
    next = items.front();

    if(sum + next <= capacity) {
      // Don't take the first item.
      knapSack(items, count, sum, capacity);
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
  int count = 1, sum = 0;

  // Start the recursion
  knapSack(items, count, sum, capacity);

  cout << count << endl;
	return 0;
}
