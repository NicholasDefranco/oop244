// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Utilities.h

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include <iostream>
#include "Perishable.h"

namespace ama {

	// Calculate total cost of a product and add to total
	double& operator+=(double&, const iProduct&);

	// calls write with iProduct (Dynamic dispatch)
	std::ostream& operator<<(std::ostream&, const iProduct&);

	// calls read with iProduct (Dynamic dispatch)
	std::istream& operator>>(std::istream&, iProduct&);

	// dynamically allocate memory to iProduct pointer
	// which can hold an address of a product or perishable
	// and returns the address
	iProduct *createInstance(char);

}

#endif
