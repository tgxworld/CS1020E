#include <iostream>
#include <list>
using namespace std;

void printList(list<int> &altlist) {
  cout << "[ ";
  for(list<int>::iterator iter = altlist.begin(); iter != altlist.end(); ++iter) {
    cout << *iter << " ";
  }
  cout << "]" << endl;
}

void moveBlock(list<int> &altlist, int index, int size) {
  list<int>::iterator iter = altlist.begin();
  advance(iter, index - 1);
  int temp;
  
  do {
    temp = *iter;
    iter = altlist.erase(iter);
    altlist.push_back(temp);
    --size;
  } while(size > 0);
};

void removeBlock(list<int> &altlist, int index, int size) {
  list<int>::iterator iter = altlist.begin();
  advance(iter, index - 1);
  
  do {
    iter = altlist.erase(iter);
    --size;
  } while(size > 0);
};

void addBlock(list<int> &altlist, int index, int size, int value) {
  list<int>::iterator iter = altlist.begin();
  advance(iter, index - 1);
  int temp;

  do {
    temp = *iter + value;
    iter = altlist.erase(iter);
    altlist.insert(iter, temp);
    --size;
  } while(size > 0);
};

void checkAlternating(list<int> &altlist) {
  if(altlist.size() > 1) {
    bool positive;
    
    list<int>::iterator iter = altlist.begin();

    if(*iter >= 0) {
      positive = true;
    } else {
      positive = false;
    }

    for(++iter; iter != altlist.end(); ++iter) {
      if(*iter >= 0) {
        if(positive == false) {
          positive = true;
        } else if(positive == true) {
          cout << "NO" << endl;
          return;
        }
      } else {
        if(positive == true) {
          positive = false;
        } else if(positive == false) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  
  cout << "YES" << endl;
}

int main()
{
  int N, Q;
  cin >> N >> Q;
  list<int> altlist;

  while(N != 0) {
    int input;
    cin >> input;

    altlist.push_back(input);    

    N--;
  }
  
  while(Q != 0) {
    char methodType;
    int index, size;
    cin >> methodType;

    switch(methodType) {
      case 'M':
        cin >> index >> size;
        moveBlock(altlist, index, size);
        checkAlternating(altlist); 
        break;
      case 'R':
        cin >> index >> size;
        removeBlock(altlist, index, size);
        checkAlternating(altlist); 
        break;
      case 'A':
        int value;
        cin >> index >> size >> value;
        addBlock(altlist, index, size, value);
        checkAlternating(altlist); 
        break;
    }

    Q--;
  }
	
  return 0;
}
