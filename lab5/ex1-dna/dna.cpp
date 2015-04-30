#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, int> DNAMap;
  int N, K;
  string DNA;

  cin >> N >> K >> DNA;

  for(int i = 0; i < DNA.length(); ++i) {
    string key = "";

    for(int j = 0; j < K; ++j) {
      key += DNA[i+j];
    }

    DNAMap[key]++;
  }

  int Q;
  cin >> Q;

  for(int i = 0; i < Q; ++i) {
    string input;
    cin >> input;

    cout << DNAMap[input] << endl;
  }

  return 0;
}
