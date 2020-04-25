// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Allocator.h

#ifndef SICT_ALLOCATOR_H
#define SICT_ALLOCATOR_H

namespace sict {
	
	// interest constant
	const double INTEREST_RATE = 0.05;

	// transaction fee
	const double TRANS_FEE = 0.5;

	// Monthly fee 2.00
	const double MON_FEE = 2.0;

	// forward declaration
	class iAccount;

	// dynamically allocates an iAccount
	// returns address of allocated memory
	iAccount *CreateAccount(const char *, double);

}

#endif
