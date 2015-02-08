#include <iostream>
#include <string>

using namespace std;

class Website {
  private:
    string _domain, _content;
  public:
    Website() {}

    Website(string domain, string content) {
      this->_domain = domain;
      this->_content = content;
    }

    string get_domain() {
      return this->_domain;
    }

    bool valid(string virus) {
      return (this->_content.find(virus) == string::npos);
    }
};

int main() {
  int n,m;

  cin >> n;
  Website *websites = new Website[n];

  for(int i = 0; i < n; ++i) {
    string domain, content;
    cin >> domain >> content;

    Website website(domain, content);
    websites[i] = website;
  }

  cin >> m;
  string *viruses = new string[m];

  for(int i = 0; i < m; ++i) {
    string virus;
    cin >> virus;
    viruses[i] = virus;
  }

  for(int i = 0; i < n; ++i) {
    bool valid = true;

    for(int j = 0; j < m; ++j) {
      if(!websites[i].valid(viruses[j])) {
        valid = false;
      }
    }

    if(!valid) {
      cout << websites[i].get_domain() << endl;
    }
  }

  return 0;
}
