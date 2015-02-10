#include "Account.h"
#include <iostream>
#include <math.h>

Account::Account(string name, double initialBalance) : _name(name), _initialBalance(initialBalance), _currentBalance(initialBalance) {};

string Account::getName() {
  return this->_name;
};

double Account::getCurrentBalance(double interestRate, int months) {
  double percentage = (interestRate / 12 / 100) * months;
  double interest = this->_initialBalance * percentage;
  return interest + this->_currentBalance + 0.0001;
};

void Account::add(double value) {
  this->_currentBalance += value; 
};

void Account::remove(double value) {
  this->_currentBalance -= value;
}
