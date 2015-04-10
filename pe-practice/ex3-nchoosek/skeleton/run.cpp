#include <iostream>
#include <vector>

using namespace std;

void choose(vector<char> inputs, int size, vector<char> outputs) {
  if(size == 0) {
    for(vector<char>::iterator iter = outputs.begin(); iter < outputs.end(); ++iter) {
      cout << *iter;
    }
    
    cout << endl;
  } else if(inputs.size() == size) {
    for(vector<char>::iterator iter = outputs.begin(); iter < outputs.end(); ++iter) {
      cout << *iter;
    }

    for(vector<char>::iterator iter = inputs.begin(); iter < inputs.end(); ++iter) {
      cout << *iter;
    }

    cout << endl;
  } else {
    char temp;
    temp = inputs.front();
    inputs.erase(inputs.begin());

    // Choose first
    outputs.push_back(temp);
    choose(inputs, size - 1, outputs);

    // Don't choose
    outputs.erase(outputs.end() - 1);
    choose(inputs, size, outputs);
  }
}

int main() {
  int K;
  cin >> K;
  vector<char> inputs;
  char input;
  vector<char> outputs;

  while(cin >> input) {
    inputs.push_back(input);
  }

  choose(inputs, K, outputs);
  
	return 0;
}
