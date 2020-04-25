// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Perishable.cpp

#include <iostream>
#include <iomanip>
#include "Perishable.h"

using namespace std;

namespace ama {

	// Default constructor
	Perishable::Perishable() : Product('P') {}

	// reads from specified input stream
	istream& Perishable::read(istream& in, bool inter) {
		Product::read(in, inter);

		if(!in.fail()) {
			if(inter) {
				cout << right << setw(max_length_label) 
				<< "Expiry date (YYYY/MM/DD): ";
				cout.unsetf(ios::right);
				in >> edate;
				switch(edate.status()) {
					case error_year:
					message("Invalid Year in Date Entry");
					in.setstate(ios::failbit);
					break;
					case error_mon:
					message("Invalid Month in Date Entry");
					in.setstate(ios::failbit);
					break;
					case error_day:
					message("Invalid Day in Date Entry");
					in.setstate(ios::failbit);
					break;
					case error_input:
					message("Invalid Date Entry");
					in.setstate(ios::failbit);
					break;
				}
			} else {
//				in.ignore();
				in >> edate;
				in.ignore();
			}
		}

		return in;

	}

	// outputs to specified output stream
	ostream& Perishable::write(ostream& out, int mode) const {
		Product::write(out, mode);
		if(isClear() && !isEmpty()) {
			switch(mode) {
				case write_human:
				cout << right << setw(max_length_label) 
				<< "Expiry Date: " << edate << endl;
				cout.unsetf(ios::right);
				break;
				case write_table:
				out << " " << edate << " |";
				break;
				case write_condensed:
				out << "," << edate;
				break;
			}
		}

		return out;

	}

}
