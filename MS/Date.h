// Milestone 5 - The Date Class
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Date.h

#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace ama {

	// constants
	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date {

		// date information
		int year;
		int mon;
		int day;

		// holds the error number
		// if there is no error, it will store 0
		int stat;

		// validates a change to the stat variable
		// if invalid, no change occurs
		void setstat(int s);

		// determines how many days are in a given 
		// month within a given year.
		int mdays(int y, int m) const;

		public:
		// default constructor
		Date();
		// validation constructor, validates
		// the year, month, and day values passed
		Date(int y, int m, int d);

		// query that retruns the current value
		// of stat
		int status() const;

		// sets stat to no_error
		void clearError();

		// determines if the Date object is 
		// in a valid state
		bool isGood() const;

		// compound assignment
		Date& operator+=(int d);

		// unary operator
		// prefix
		Date& operator++();
		// postfix
		Date operator++(int);

		// binary operator
		// addition operator overload
		Date operator+(int d) const;

		// relational operator overload
		// < means before
		// > means after
		bool operator==(const Date& r) const;
		bool operator!=(const Date& r) const;
		bool operator<(const Date& r) const;
		bool operator>(const Date& r) const;
		bool operator<=(const Date& r) const;
		bool operator>=(const Date& r) const;

		// collects data from input stream and stores
		// it into the data members
		std::istream& read(std::istream& is);

		// prints data stored in Date object to the screen
		std::ostream& write(std::ostream& os) const;

	};
	
	// extraction operator overload
	std::istream& operator>>(std::istream& is, Date& d);

	// insertion operator overload
	std::ostream& operator<<(std::ostream& os, const Date& d);

}

#endif
