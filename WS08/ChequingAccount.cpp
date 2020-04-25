// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: CheckingAccount.cpp

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	// validates tansaction fee and monthly fee
	// forwards balance to Account class constructor
	ChequingAccount::ChequingAccount(double b, double t, double m) 
								: Account(b) {
		if(t < 0.0) {
			t = 0.0;
		}

		if(m < 0.0) {
			m = 0.0;
		}

		tfee = t;
		mfee = m;

	}	

	// credits balance and debits transaction fee from balance
	bool ChequingAccount::credit(double a) {
		return Account::credit(a) ? Account::debit(tfee) : false;

	}

	// debits balance and debits tranaction fee from balance
	bool ChequingAccount::debit(double a) {
		return Account::debit(a) ? Account::debit(tfee) : false;
	}

	// debits monthly fee from balance
	void ChequingAccount::monthEnd() {
		Account::debit(mfee);
	}

	// display account information
	void ChequingAccount::display(ostream& out) const {
		out.setf(ios::fixed);
		out.precision(MONEY_PRE);

		out << "Account type: Chequing" << endl;
		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << tfee << endl;
		out << "Monthly Fee: " << mfee << endl;

		out.unsetf(ios::fixed);
		out.precision(DEFAULT_PRE);

	}


}
