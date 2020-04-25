// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: SavingsAccount.cpp

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	// validates rate passed as second argument
	// forwards balance to Account class
	SavingsAccount::SavingsAccount(double b, double i) : Account(b) {
		if(i < 0.0) {
			i = 0.0;
		}

		rate = i;
		
	}

	// add interest gathered to balance
	void SavingsAccount::monthEnd() {
//		*this = SavingsAccount(balance() * (1 + rate), rate);
		credit(balance() * rate);
	}

	// displays info about an account
	void SavingsAccount::display(ostream& out) const {
		cout << "Account type: Savings" << endl;

		out.setf(ios::fixed);
		out.precision(MONEY_PRE);

		cout << "Balance: $" << balance() << endl;
		
		cout << "Interest Rate (%): " << rate * 100 << endl;

		out.precision(DEFAULT_PRE);
		out.unsetf(ios::fixed);
	}

}
