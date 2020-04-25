// Workshop 2 - Dynamic Memory
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: CellPhone.cpp

// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"

using namespace std;

// TODO: the sict namespace
namespace sict {

	// TODO: definition for display(...) 
	// const qualifier on parameter denotes a query helper function.
	void display(const CellPhone& cellphone) {
		cout << "Phone " << cellphone.m_model
			<< " costs $" << cellphone.m_price << "!" << endl;
	}

	// Second display definition
	// displays an array of CellPhone and finds the cheapest cellphone
	// const qualifier on parameters denotes a query helper function.
	void display(const CellPhone *phones, const int size) {

		// set smallest price variable to the first
		// element of the array by default
		double smallPrice = phones[0].m_price;

		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;

		for(int i = 0; i < size; i++) {
			cout << i + 1 << ". ";
			display(phones[i]);

			if(phones[i].m_price < smallPrice) {
				smallPrice = phones[i].m_price;
			}

		}

		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << smallPrice 
			<< "." << endl;
		cout << "------------------------------" << endl;

	}

}
