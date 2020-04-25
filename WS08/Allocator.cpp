// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Allocator.cpp

#include "Allocator.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	// dynamically allocates any account based on string passed
	// returns address of allocated memory
	iAccount *CreateAccount(const char *t, double b) {

		iAccount *tmp = nullptr;

		if(t[0] == 'S') {
			tmp = new SavingsAccount(b, INTEREST_RATE);
		} else if(t[0] == 'C') {
			tmp = new ChequingAccount(b, TRANS_FEE, MON_FEE);
		}

		return tmp;

	}


}
