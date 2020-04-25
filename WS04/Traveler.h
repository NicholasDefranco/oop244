// Workshop 4 - Constructors
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Traveler.h

// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

// TODO: declare your namespace here
namespace sict {

	// TODO: define the constants here
	// constant for max size of destination name
	const int max_destination_size = 32;

	// constant for max size of name
	const int max_name_size = 16;

	// Default date if client does not provide a date
	const int DEF_YEAR = 2019;
	const int DEF_MONTH = 7;
	const int DEF_DAY = 1;

	// constants to specify a range of valid dates
	const int MIN_YEAR = 2019;
	const int MAX_YEAR = 2022;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;
	const int MIN_DAY = 1;
	const int MAX_DAY = 31;

	// TODO: define the Traveler class here
	class Traveler {
		
		// statically allocated arrays
		char firstName[max_name_size + 1];
		char lastName[max_name_size + 1];
		char dest[max_destination_size + 1];

		int year;
		int mon;
		int day;

		// private member function checking if string passed is empty
		bool isEmpty(const char *) const;

		// private member function to determine if the date data members
		// are equal.
		bool sameDay(const Traveler&) const;

		public:
		// default constructor, sets object to a safe empty state.
		Traveler();

		// Did not put a three parameter contructor as I thought 
		// setting default values to the 6 arg constructor would 
		// clean up code.

		// requires three pointers to char arrays.
		// initializes data members if valid.
		Traveler(const char *, const char *, const char *, 
			int = DEF_YEAR, int = DEF_MONTH, int = DEF_DAY);

		// returns a Travelers first name.
		const char *name() const;

		// determines if two Travelers travel on the same date
		// and destination
		bool canTravelWith(const Traveler&) const;

		// checks for empty state (if firstname is an empty string)
		bool isEmpty() const;

		// query to display data stored in an object if not empty
		void display() const;
	
	};

	// helper funtion to assist in determining if a date passed is valid
	bool valDay(int, int, int);
		
}

#endif
