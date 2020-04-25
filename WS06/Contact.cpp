// Workshop 6 - Class With a Resource
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Contact.cpp

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	// default constructor, sets object to safe empty state
	Contact::Contact() {
		name[0] = '\0';
		size = -1;
		pnums = nullptr;
	}

	// validation constructor, sets all data to values passed
	// by the client
	Contact::Contact(const char *n, long long *nums, int s) {
		
		// safeguard
		pnums = nullptr;

		if(n == nullptr || n[0] == '\0' || s < 0) {
			*this = Contact();	
		} else {
			strncpy(name, n, max_name_size);
			size = 0;
			for(int i = 0; i < s; i++) {
				if(valnum(nums[i])) {
					realloc(nums[i]);
				}
			}
		}

	}

	// copy constructor
	// initializes a newly created object with existing object
	Contact::Contact(const Contact& c) {
		pnums = nullptr;
		*this = c;
	}

	// copy assignment operator
	// copies the contents of the right operand 
	// to the left operand
	// performs a deep copy on array of phone numbers.
	Contact& Contact::operator=(const Contact& c) {

		if(this != &c) {
			strncpy(name, c.name, max_name_size);
			size = c.size;
			delete [] pnums;
			if(c.size > 0) {
				pnums = new long long[c.size];
				for(int i = 0; i < c.size; i++) {
					pnums[i] = c.pnums[i];
				}
			} else {
				pnums = nullptr;
			}
		}

		return *this;

	}

	// increases the size of the long long array by one
	void Contact::realloc(long long num) {

		long long *tmp = new long long[size + 1];

		for(int j = 0; j < size; j++) {
			tmp[j] = pnums[j];
		}

		delete [] pnums;

		pnums = tmp;
		pnums[size] = num;
		size++;
	}

	// validates a single number
	bool Contact::valnum(long long num) const {

		bool val = true;
		
		if(num / AREA_EXT <= 0 || num / AREA_EXT >= 100){
			val = false;
		} else 	if(val && (num / (AREA_EXT / 10)) % 10 == 0){
			val = false;
		} else if(val && num / (PHONE_EXT / 10) % 10 == 0){
			val = false;
		}

		return val;

	}

	// deallocates resources
	Contact::~Contact() {
		delete [] pnums;
	}

	// returns true if empty
	bool Contact::empty() const {
		return size < 0;
	}

	// displays the object if valid
	void Contact::display() const {

		if(empty()) {
			cout << "Empty contact!" << endl;
		} else {
			cout << name << endl;

			for(int i = 0; i < size; i++) {
				cout << "(+";
				cout << pnums[i] / AREA_EXT;
				cout << ") ";
				cout << pnums[i] % AREA_EXT / PHONE_EXT;
				cout << " ";
				cout << pnums[i] % PHONE_EXT / LAST_DIG_EXT;
				cout << "-";
				cout.width(4);
				cout.fill('0');
				cout << pnums[i] % LAST_DIG_EXT;
				cout.fill(' ');
				cout << endl;
			}

		}

	}

	// reallocates dynamic array to accommadate a new grade
	Contact& Contact::operator+=(long long num) {
		if(!empty() && valnum(num)) {
			realloc(num);
		} 
		
		return *this;
	}	

}
