#include "Bank.h"
#include <vector>

Bank::Bank(double interestRate) : _interestRate(interestRate) {};

void Bank::create(string name, double balance) {
  Account newAccount(name, balance);
  this->accounts.push_back(newAccount);
};

void Bank::deposit(string name, double value) {
  Account *account;
  account = this->getAccountByName(name);
  account->add(value); 
};

void Bank::withdraw(string name, double value) {
  Account *account;
  account = this->getAccountByName(name);
  account->remove(value);
};

Account * Bank::getAccountByName(string name) {
  vector<Account>::iterator iter;

  iter = this->accounts.begin();

  while(iter < this->accounts.end()) {
    if(iter->getName() == name) {
      return &(*iter);
    }

    iter++;
  }
  
  throw "Account not found";
};

vector<Account> Bank::getAccounts() {
  return this->accounts;
};

double Bank::getInterestRate() {
  return this->_interestRate;
};
