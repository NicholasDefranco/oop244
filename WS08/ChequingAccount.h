// Workshop 8 - Virtual Funtions
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: CheckingAccount.h

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
	
		// Transaction fee
		double tfee;
	
		// Monthly fee
		double mfee;

		public:
		// validates tansaction fee and monthly fee
		// forwards balance to Account class constructor
		ChequingAccount(double, double, double);

		// required to suppress a warning
		virtual ~ChequingAccount() = default;

		// credits balance and debits transaction fee from balance
		bool credit(double);

		// debits balance and debits tranaction fee from balance
		bool debit(double);

		// debits monthly fee from balance
		void monthEnd();

		// display account information
		void display(std::ostream&) const;

	};

}

#endif
