// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Utilities.cpp

#include <iostream>
#include "Utilities.h"

using namespace std;

namespace ama {

	// Calculate total cost of a product and add to total
	double& operator+=(double& total, const iProduct& p) {
		return total += p.total_cost();
	}

	// calls write with iProduct (Dynamic dispatch)
	ostream& operator<<(ostream& out, const iProduct& p) {
		return p.write(out, write_human);
	}

	// calls read with iProduct (Dynamic dispatch)
	istream& operator>>(istream& in, iProduct& p) {
		return p.read(in, true);
	}

	// dynamically allocate memory to iProduct pointer
	// which can hold an address of a product or perishable
	// and returns the address
	iProduct *createInstance(char t) {
		iProduct *tmp = nullptr;

		if(t == 'N' || t == 'n') {
			tmp = new Product;
		} else if(t == 'P' || t == 'p') {
			tmp = new Perishable;
		}

		return tmp;

	}

}
