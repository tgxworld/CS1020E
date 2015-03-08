#include "Person.h"

Person::Person(string name) {
  this->_name = name;
}

string Person::getName() {
  return this->_name;
}

int Person::getNumOfGroups() {
  return this->_groups.size();
}

