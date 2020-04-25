// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: iProduct.h

#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H

#include <iostream>

namespace ama {

	// constants
	// max lengths
	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;

	// settings for output
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;

	const double tax_rate = 0.13;

	class iProduct {
	
		public:

		virtual ~iProduct() = default;

		virtual std::ostream& write(std::ostream&, int) const = 0;

		virtual std::istream& read(std::istream&, bool) = 0;
		
		virtual bool operator==(const char *) const = 0;

		virtual double total_cost() const = 0;

		virtual int qtyNeeded() const = 0;

		virtual int qtyAvailable() const = 0;

		virtual const char *getname() const = 0;

		virtual const char *getsku() const = 0;

		virtual int operator+=(int) = 0;

		virtual bool operator>(const iProduct&) const = 0;

	};


}

#endif
