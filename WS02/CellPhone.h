// Workshop 2 - Dynamic Memory
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: CellPhone.h

// TODO: header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H

// TODO: sict namespace
namespace sict {

	// represents the max number of characters
	// for the m_model char array
	const int MAX_CHARS = 31;

	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone {

		char m_model[MAX_CHARS + 1];
		double m_price;	

	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	// const qualifier denotes helper function as a query
	void display(const CellPhone&);

	// Second display definition
	// displays an array of CellPhone and finds the cheapest cellphone
	// const qualifier on parameters denotes a query helper function.
	void display(const CellPhone *, const int);

}

#endif
