// Milestone 5 - The Date Class
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Date.cpp

#include <iostream>
#include "Date.h"

using namespace std;

namespace ama {

	// validates a change to the stat variable
	// if invalid, no change occurs
	void Date::setstat(int s) {
		if(s == no_error || s == error_year || s == error_mon
			|| s == error_day || s == error_invalid_operation
					|| s == error_input) {
			stat = s;
		}
	}

	// determines how many days are in a given 
	// month within a given year.
	int Date::mdays(int y, int m) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 
				30, 31, -1 };
		int month = m >= 1 && m <= 12 ? m : 13;
		month--;
		return days[month] + int((month == 1)*((y % 4 == 0) 
			&& (y % 100 != 0)) || (y % 400 == 0));
		
	}

	// default constructor
	Date::Date() {
		year = 0;
		mon = 0;
		day = 0;
		clearError();
	}

	// validation constructor, validates
	// the year, month, and day values passed
	Date::Date(int y, int m, int d) {

		*this = Date();

		if(y < min_year || y > max_year) {
			setstat(error_year);
		} else if((m < 1 || m > 12)) {
			setstat(error_mon);
		} else if(d < 1 || d > mdays(y, m)) {
			setstat(error_day);
		} else {
			year = y;
			mon = m;
			day = d;
		}

	}

	// query that retruns the current value
	// of stat
	int Date::status() const {
		return stat;
	}

	// sets stat to no_error
	void Date::clearError() {
		setstat(no_error);
	}

	// determines if the Date object is 
	// in a valid state
	//
	// requires checking stat and year because omiting the year check
	// would allow empty objects to return true as they are initilized
	// with no error.
	bool Date::isGood() const {
		return stat == no_error && year >= min_year && year <= max_year;
	}

	// compound assignment
	Date& Date::operator+=(int d) {
		if(!isGood()) {
			setstat(error_invalid_operation);
		} else if(day + d <= mdays(year, mon) && day + d >= 1) {
			day += d;
		} else {
			setstat(error_invalid_operation);
		}

		return *this;

	}

	// prefix increment
	Date& Date::operator++() {
		return *this += 1;
	}

	// postfix increment
	Date Date::operator++(int) {
		Date tmp = *this;
		++(*this);
		return tmp;
	}

	// binary operator
	// addition operator overload
	Date Date::operator+(int d) const {
		Date tmp = *this;
		return tmp += d;	
	}

	// relational operators
	// < means before
	// > means after
	bool Date::operator==(const Date& r) const {
		return year == r.year && mon == r.mon && day == r.day;
	}
	
	bool Date::operator!=(const Date& r) const {
		return !(*this == r);
	}
	
	bool Date::operator<(const Date& r) const {

		bool less;

		if(year < r.year) {
			less = true;
		} else if(year == r.year && mon < r.mon) {
			less = true;
		} else if(mon == r.mon && day < r.day) {
			less = true;
		} else {
			less = false;
		}

		return less;
		
	}

	bool Date::operator>(const Date& r) const {
		return !(*this < r) && *this != r;
	}

	bool Date::operator<=(const Date& r) const {
		return *this < r || *this == r;
	}

	bool Date::operator>=(const Date& r) const {
		return *this > r || *this == r;
	}

	// collects data from input stream and stores
	// it into the data members if incoming data is valid
	istream& Date::read(istream& is) {

		int y = 0;
		int m = 0;
		int d = 0;

		if((is >> y).fail() || (is.ignore() >> m).fail() 
					|| (is.ignore() >> d).fail()) {
			*this = Date();
			setstat(error_input);
		} else {
			*this = Date(y, m, d);
		}

		return is;
	}

	// prints data stored in Date object to the screen
	ostream& Date::write(ostream& os) const {

		os.fill('0');
		os.setf(ios::right);

		os.width(4);
		os << year << "/";

		os.width(2);
		os << mon << "/";

		os.width(2);
		os << day;

		os.unsetf(ios::right);
		os.fill(' ');

		return os;

	}

	// extraction operator overload
	istream& operator>>(istream& is, Date& d) {
		d.read(is);
		return is;
	}

	// insertion operator overload
	ostream& operator<<(ostream& os, const Date& d) {
		d.write(os);
		return os;
	}

}
