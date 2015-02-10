#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account {
	private:
    string _name;
    double _initialBalance, _currentBalance;
	public:
	// constructors, destructors
    Account(string name, double initialBalance);
	// setters, getters
    string getName();
    double getCurrentBalance(double interestRate, int months);
    void add(double value);
    void remove(double value);
};

#endif
