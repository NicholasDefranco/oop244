// Milestone 4
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Product.h

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include "iProduct.h"
#include "ErrorState.h"

namespace ama {

	class Product : public iProduct {

		// data members
		// hold the type of the product
		const char type;		

		char sku[max_length_sku + 1];
		char unit[max_length_unit + 1];
		char *name;

		// quantity needed
		int demand;

		// quantity on hand
		int hand;

		double price;

		// hold whether or not tax is applied to the item
		bool taxable;

		// Will hold an error message if an error occurred
		// within class member function
		ErrorState err;

		// reads a string from input stream passed and stores it
		// into a dynamic character array which is returned
		// accepts a prompt string, max length, and delimeter
		const char *alloc(std::istream& in, const char *msg, int len, 
						char delim = '\n');

		// generic function to assist reading the input stream
		// passed and stores data into the reference passed
		// accepts prompt message and error message
		template<typename T>
		void get(std::istream& in, const char *msg,const char *emsg, 
								T& value);

		protected:
		// accepts a message and stores the message into error 
		// state object
		void message(const char *m);

		// returns true if err contains an error message
		bool isClear() const;

		public:
		// one/default constructor, sets object to empty state
		// and initializes the constant
		Product(char = 'N');

		// validation constructor, validates all incoming data,
		// if valid current object will store the data
		Product(const char *, const char *, const char *, 
			double = 0.0, int = 0, int = 0, bool = true);

		// copy constructor
		Product(const Product&);

		// destructor, de-allocates name data member
		virtual ~Product();

		// copy assignment operator
		Product& operator=(const Product&);

		// adds to the amount on hand
		int operator+=(int);
		
		// relational operators
		bool operator==(const char *) const;
		bool operator>(const char *) const;
		bool operator>(const iProduct&) const;

		// returns hand
		int qtyAvailable() const;

		// returns demand
		int qtyNeeded() const;

		const char *getname() const;

		const char *getsku() const;

		// calculates the cost of the total amount of the
		// specific product
		double total_cost() const;

		// returns true if empty
		bool isEmpty() const;

		// reads from specified input stream
		std::istream& read(std::istream&, bool);

		// outputs to specified output stream
		std::ostream& write(std::ostream&, int) const;
	
	};

}

#endif
