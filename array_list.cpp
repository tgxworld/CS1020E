#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_LIST = 50;

class List {
private:
  int _size;
  int _items[MAX_LIST];  

public:
  List() {
    this->_size = 0;
  }

  bool isEmpty() {
   return this->_size == 0; 
  }

  int getLength() {
    return this->_size;
  }

  bool insert(int userIndex, const int& newItem) {
    int index = userIndex - 1;

    if(this->_size >= MAX_LIST) {
      return false;
    }

    if(index < 0 || index > this->_size + 1) {
      return false;
    }

    for(int pos = this->_size - 1; pos >= index; --pos) {
      this->_items[pos + 1] = this->_items[pos];
    } 

    this->_items[index] = newItem;
    this->_size++;

    return true;
  }

  bool remove(int userIndex) {
    int index = userIndex - 1;

    if(index < 0 || index >= this->_size) {
      return false;
    }
 
    for(int pos = index; pos < this->_size - 1; ++pos) {
      this->_items[pos] = this->_items[pos + 1];
    }

    this->_size--;
    return true; 
  }

  bool retrieve(int userIndex, int& dataItem) {
    int index = userIndex - 1;

    if(index < 0 || index > this->_size + 1) {
      return false;
    }

    dataItem = this->_items[index];
    return true; 
  }

  string toString() {
    ostringstream os;
  
    os << "[";

    for(int i = 0; i < this->_size; ++i) {
      os << this->_items[i] << " ";
    }

    os << "]";

    return os.str();
  }
};

int main() {
  List list;
  list.insert(1, 1);
  list.insert(2, 2);
  list.insert(3, 3);
  list.insert(4, 4);
  
  cout << list.toString() << endl;

  int a;
  list.retrieve(2, a);

  cout << a << endl;

  list.remove(2);

  cout << list.toString() << endl;

  return 0;
}

