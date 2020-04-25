// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: AmaApp.h

#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

#include "iProduct.h"

namespace ama {

	// Array sizes
	const int MAX_FILE_SIZE = 256;
	const int MAX_PRODUCTS_SIZE = 100;

	// menu options
	const int LIST_PRODUCTS = 1;
	const int SEARCH_PRODUCT = 2;
	const int ADD_NON_PERISH = 3;
	const int ADD_PERISH = 4;
	const int ADD_QUANTITY = 5;
	const int DELETE_PRODUCT = 6;
	const int SORT = 7;
	const int EXIT = 0;

	class AmaApp {
		// contains the file name
		char fname[MAX_FILE_SIZE];

		// iProduct pointer array
		iProduct *prod[MAX_PRODUCTS_SIZE];

		// number of valid products in array
		int no;

		// copying forbidden
		AmaApp(const AmaApp&) = delete;
		AmaApp& operator=(const AmaApp&) = delete;

		// clears the input buffer
		void clear() const;

		// deallocates all memory pointed to
		// by the array
		void free();

		// pause execution
		void pause() const;
	
		// display menu and collect user input
		// if input is invalid, -1 is returned
		int menu() const;

		// reads the file and stores the contents in the iProduct array
		void loadrec();

		// write contents of array to the file
		void saverec() const;

		// show contents of array to user
		void listprods() const;

		// writes array to file but skips element that
		// matches address passed
		void deleterec(iProduct *);

		// sorts by name of product
		void sort();

		// searches array of iProducts to find a product
		// with a matching SKU, if found, the address is returned.
		iProduct *find(const char *) const;

		// Adds to quantity availiable
		void addqty(iProduct *);

		// adds a product to the array
		void addprod(char);
	
		// prompts user for a sku and returns
		// a pointer to the iProduct if it exists
		iProduct *get() const;

		public:
		// recieves a file name and stores name in 
		// object if valid, if invalid, object
		// assumes a safe empty state
		AmaApp(const char *);

		// deallocates all memory pointed to by array
		virtual ~AmaApp();

		// calls the proper function based on user input
		int run();

	};

}

#endif
