// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: iAccount.h

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>
#include "Allocator.h"

namespace sict {

	// precision constants
	const int DEFAULT_PRE = 6;
	const int MONEY_PRE = 2;

	class iAccount {

		public:

		// required to suppress a warning
		virtual ~iAccount() = default;

		// adds double passsed to balance
		virtual bool credit(double) = 0;
	
		// subtracts double passsed to balance
		virtual bool debit(double) = 0;

		// add interest gathered and add to balance
		virtual void monthEnd() = 0;

		// displays info about an account
		virtual void display(std::ostream&) const = 0;

	};

}

#endif

