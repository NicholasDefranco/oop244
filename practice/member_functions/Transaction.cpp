#include <iostream>
#include "Transaction.h"

using namespace std;

// member functions have direct access to data memebers as well as other 
// member funtions encapsulated in a class as the class scope encompasses
// the function's scope. 

void Transaction::enter() {

	cout << "Enter the account number: ";
	cin >> acct;
	cout << "Enter the account type (d for debit, c for credit) : ";
	cin >> type;
	cout << "Enter the account amount : ";
	cin >> amount;

}

void Transaction::display() const{

	cout << "Account " << acct;
	cout << ((type == 'd') ? " Debit $" : " Credit $") << amount;
	cout << endl;

}
