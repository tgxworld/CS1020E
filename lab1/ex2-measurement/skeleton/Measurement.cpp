#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <math.h>
#include "Person.h"

using namespace std;

int main() {
  // read input, create a Person object for each person in the input, store in a
  // data structure (can use vector, refer to http://www.cplusplus.com/reference/vector/vector/)
  int group_size;
  cin >> group_size;

  vector<Person*> list;

  for(int i = 0; i < group_size; ++i) {
    string name;
    double height, weight;
    cin >> name;
    cin >> height;
    cin >> weight;
    Person *person;
    person = new Person(name, height, weight);
    list.push_back(person);
  }

  Person *shortest, *tallest;
  tallest = Person::tallest(list);
  shortest = Person::shortest(list);

  cout << fixed << setprecision(2) << shortest->name() << " is the shortest with BMI equals to " << shortest->getBMI() << "." << endl;
  cout << fixed << setprecision(2) << tallest->name() << " is the tallest with BMI equals to " << tallest->getBMI() << "." << endl;

  return 0;
}
