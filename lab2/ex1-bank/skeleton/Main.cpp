#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Bank.h"
#include "Account.h"

using namespace std;

int main() {
  int interestRate, months;
  cin >> interestRate >> months; 

  Bank bank(interestRate); 

  while(true) {
    string action;
    cin >> action;
    if(action == "0") { break; };

    string accountName;
    double amount;
    cin >> accountName >> amount;

    if(action ==  "Create") { 
      bank.create(accountName, amount);
    } else if(action ==  "Withdraw") {
      bank.withdraw(accountName, amount);
    } else if(action == "Deposit") {
      bank.deposit(accountName, amount);
    }
  }

  vector<Account> accounts;
  accounts = bank.getAccounts();
  cout << accounts.size() << endl;
  vector<Account>::iterator iter;
  iter = accounts.begin();

  while(iter != accounts.end()) {
    cout << fixed << setprecision(2) << iter->getName() << " " << iter->getCurrentBalance(bank.getInterestRate(), months) << endl;
    iter++;
  }  

	return 0;
}
