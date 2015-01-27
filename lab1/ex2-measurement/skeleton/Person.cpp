#include "Person.h"
#include <iostream>

using namespace std;

Person* Person::tallest(vector<Person*> list) {
  // get the tallest person from a list of people
  Person *tallest = list[0];

  for(vector<Person*>::iterator person = list.begin() + 1; person != list.end(); ++person) {
    if ((*person)->_height > tallest->_height) {
      tallest = *person;
    }
  }

  return tallest;
}

Person* Person::shortest(vector<Person*> list) {
  // get the shortest person from a list of people
  Person *shortest = list[0];

  for(vector<Person*>::iterator person = list.begin() + 1; person != list.end(); ++person) {
    if ((*person)->_height < shortest->_height) {
      shortest = *person;
    }
  }

  return shortest;
}

double Person::getBMI() {
  // compute the BMI by using the formula given
  double height = (this->_height / 100.000);
  double bmi = (this->_weight / (height * height));
  return bmi;
}

// Attribute reader.
string Person::name() {
  return this->_name;
}

Person::Person(string name, double height, double weight) {
  this->_name = name;
  this->_height = height;
  this->_weight = weight;
}
