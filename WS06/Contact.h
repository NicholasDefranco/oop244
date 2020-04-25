// Workshop 6 - Class With a Resource
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Contact.h

#ifndef CONTACT_SICT_H
#define CONTACT_SICT_H

namespace sict {

	const int max_name_size = 16;

	// used to extract/remove area code + phone number
	const long long AREA_EXT = 10000000000LL;

	// used to extract/remove phone number
	const long long PHONE_EXT = 10000000LL;

	// used in display function to extract last four digits
	const int LAST_DIG_EXT = 10000;

	class Contact {

		// statically allocated char array to hold the
		// name of the Contact.
		char name[max_name_size + 1];
	
		// dynamic array of phone numbers
		long long *pnums;

		// size of the dynamic long long array
		int size;

		// private helper functions
		// validates a single number
		bool valnum(long long) const;

		// increases the size of the long long array by one
		void realloc(long long);

		public:

		// default constructor, sets object to safe empty state
		Contact();

		// validation constructor, sets all data to values passed
		// by the client
		Contact(const char *, long long *, int);

		// copy constructor
		// initializes a newly created object with existing object
		Contact(const Contact&);

		// copy assignment operator
		// copies the contents of the right operand 
		// to the left operand
		// performs a deep copy on array of phone numbers.
		Contact& operator=(const Contact&);

		// destructor
		~Contact();

		// returns true if empty
		bool empty() const;

		// displays the object if valid
		void display() const;

		// reallocates dynamic array to accommadate a new grade
		Contact& operator+=(long long);

	};


};

#endif

