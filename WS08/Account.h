// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Account.h

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {

		// balance
		double bal;
	
		protected:
		// returns current object's balance
		double balance() const;

		public:
		// default/one arg constructor
		// validates double if passed
		Account(double = 0.0);

		// required to suppress a warning
		virtual ~Account() = default;

		// adds double passsed to balance
		bool credit(double);
		// subtracts double passsed to balance
		bool debit(double);
	
	};

}

#endif
