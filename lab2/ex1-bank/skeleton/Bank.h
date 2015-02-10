#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Account.h"

using namespace std;

class Bank {
	private:
		// data member goes here
		// interest rate
    double _interestRate;
		
		// account list
    vector<Account> accounts;
		
	public:
		// constructors, destructors
    Bank(double interestRate);
		
		// setters, getter
    Account * getAccountByName(string name);
    vector<Account> getAccounts();
    double getInterestRate();
		
		// implement these methods
		void create(string name, double balance);
		void deposit(string name, double value);
		void withdraw(string name, double value);
};

#endif
