// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Account.cpp

#include "Account.h"

using namespace std;

namespace sict {

	// returns current object's balance
	double Account::balance() const {
		return bal;
	}

	// default/one arg constructor
	// validates double if passed
	Account::Account(double b) {
		if(b < 0.0) {
			b = 0.0;
		}	

		bal = b;

	}

	// adds double passsed to balance
	bool Account::credit(double a) {
		bool success = true;
		if(a >= 0.0)  {
			bal += a;
		} else {
			success = false;
		}

		return success;
	}

	// subtracts double passsed to balance
	bool Account::debit(double a) {
		bool success = true;
		if(a >= 0.0) {
			bal -= a;
		} else {
			success = false;
		}

		return success;
	}

}
