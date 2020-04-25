// Workshop 4 - Constructors
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Traveler.cpp

// TODO: add your headers here
#include <iostream>
#include <iomanip>

// required for strncpy function
// and possibly strlen function.
#include <cstring>
#include "Traveler.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	// default constructor, sets object to a safe empty state.
	// first element of character strings are set to '\0' 
	// to indicate an empty string.
	Traveler::Traveler() {
		firstName[0] = '\0';
		lastName[0] = '\0';
		dest[0] = '\0';	

		year = 0;
		mon = 0;
		day = 0;
	}

	// Note: Did not put a three parameter contructor as I thought setting
	// default values to the 6 arg constructor would clean up code.
	// Thus, avoiding bloat.

	// requires three pointers to char arrays.
	// initializes data members if valid.
	Traveler::Traveler(const char *fName, const char *lName, 
				const char *des, int y, int m, int d){

		// ... unfortunately, I could not avoid a multi-line
		// statement here...
		if(isEmpty(fName) || isEmpty(lName) || isEmpty(des)
						|| !valDay(y, m ,d)) {
			*this = Traveler();
		} else {
			strncpy(firstName, fName, max_name_size);
			strncpy(lastName, lName, max_name_size);
			strncpy(dest, des, max_destination_size);

			year = y;
			mon = m;
			day = d;
		}	

	}

	// determines if two Travelers travel on the same date
	// and destination
	bool Traveler::canTravelWith(const Traveler& t) const {
		return strcmp(dest, t.dest) == 0 && sameDay(t);
	}

	// returns a Travelers first name
	const char *Traveler::name() const {
		return firstName;
	}

	// TODO: implement isEmpty query here
	// checks for empty state (if firstname is an empty string)
	bool Traveler::isEmpty() const {
		return isEmpty(name());
	}

	// private member function checking if string is empty
	bool Traveler::isEmpty(const char *str) const {
		//return str == nullptr || str[0] == '\0'; 
		// or 
		return str == nullptr || strlen(str) == 0;
	}

	// TODO: implement display query here
	// query to display data stored in an object if not empty
	void Traveler::display() const {
		if(!isEmpty()) {
			cout << lastName << ", " << firstName << " goes to "
			<< dest << " on " << year << "/"
			<< setw(2) << setfill('0') << mon << "/" 
			<< setw(2) << day << setfill(' ') << endl;
		} else {
			cout << "--> Not a valid traveler! <--" << endl;
		}	
	}
	
	// private member function to determine if the date data members
	// are equal.
	bool Traveler::sameDay(const Traveler& t) const {
		// ...trying to avoid multi-line statements
		// hence why it is separate from canTravelWith() member
		return year == t.year && mon == t.mon && day == t.day;
	}

	// helper funtion to help prevent validation bloat within class
	// simplifies validation logic within class making it more readable.

	// helper funtion to assist in determining if a date passed is valid
	bool valDay(int y, int m, int d) {
		return y >= MIN_YEAR && y <= MAX_YEAR && m >= MIN_MONTH 
			&& m <= MAX_MONTH && d >= MIN_DAY && d <= MAX_DAY;
	}


}
