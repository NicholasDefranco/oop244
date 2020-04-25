// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: SavingsAccount.h

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {

		// interest rate 
		double rate;

		public:
		// validates rate passed as second argument
		// forwards balance to Account class
		SavingsAccount(double, double);

		// required to suppress a warning
		virtual ~SavingsAccount() = default;

		// add interest gathered to balance
		void monthEnd();

		// displays info about an account
		void display(std::ostream&) const;

	};

}

#endif
