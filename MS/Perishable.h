// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Perishable.h

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>
#include "Date.h"
#include "Product.h"

namespace ama {

	class Perishable : public Product {

		// expiry date
		Date edate;
		
		public:
		// default constructor
		Perishable();

		// always declare a virtual destructor
		virtual ~Perishable() = default;

		// reads from specified input stream
		std::istream& read(std::istream&, bool);

		// outputs to specified output stream
		std::ostream& write(std::ostream&, int) const;

	};

}


#endif
