// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: AmaApp.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AmaApp.h"
#include "Utilities.h"
#include "Sort.h"


using namespace std;
using namespace sict;

namespace ama {

	// recieves a file name and stores name in 
	// object if valid, if invalid, object
	// assumes a safe empty state
	AmaApp::AmaApp(const char *n) {
		if(n == nullptr || n[0] == '\0') {
			fname[0] = '\0';
		} else {
			strncpy(fname, n, MAX_FILE_SIZE);
		}
		
		for(int i = 0; i < MAX_PRODUCTS_SIZE; i++) {
			prod[i] = nullptr;
		}

		no = 0;

		loadrec();

	}

	// deallocates all memory pointed to by array
	AmaApp::~AmaApp() {
		free();
	}

	// deallocates all memory pointed to
	// by the array
	void AmaApp::free() {
		for(int i = 0; i < MAX_PRODUCTS_SIZE; i++) {
			delete prod[i];
			prod[i] = nullptr;
		}
	}

	// clears the input buffer
	void AmaApp::clear() const {
		while(cin.get() != '\n');
	}

	// pause execution
	void AmaApp::pause() const {
		cout << "Press Enter to continue..." << endl;
		clear();
	}

	// display menu and collect user input
	// if input is invalid, -1 is returned
	int AmaApp::menu() const {
		int choice = 0;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> choice;

		clear();

		return (choice >= 0 && choice <= 7) ? choice : -1;
	}

	// reads the file and stores the contents in the iProduct array
	void AmaApp::loadrec() {

		int i = 0;

		free();

		fstream f(fname, ios::in);
		while(f.good()) {

			char tmp; 
			while((tmp = toupper(f.get())) != 'N' && tmp != 'P'
				&& f.good());
			f.ignore();

			if(f.good()) {
				prod[i] = createInstance(tmp);

				if(prod[i] != nullptr) {
					prod[i]->read(f, false);
					i++;
				}

			}
		}

		no = i;

		f.close();
		f.clear();

	}

	// write contents of array to the file
	void AmaApp::saverec() const {
		fstream f(fname, ios::out|ios::trunc);

		for(int i = 0; i < no; i++) {
			prod[i]->write(f, write_condensed);
			f << endl;
		}
		f.close();
	}

	// show contents of array to user
	void AmaApp::listprods() const {
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		double tcost = 0.0;
		for(int i = 0; i < no; i++) {
			cout << "|" << right << setw(4) << (i + 1) << " |";
			cout.unsetf(ios::right);
			prod[i]->write(cout, write_table);	
			cout << endl;
			tcost += *(prod[i]);
		}
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | " << setw(10) << fixed << setprecision(2) << tcost << " |" << endl << setprecision(6) << setfill(' ');

		cout.unsetf(ios::fixed);

		cout << "------------------------------------------------------------------------------------------------" << endl << endl;

		pause();

	}

	// writes array to file but skips element that
	// matches address passed
	void AmaApp::deleterec(iProduct *p) {
		fstream f(fname, ios::out|ios::trunc);
		for(int i = 0; i < no; i++) {
			if(prod[i] != p) {
				prod[i]->write(f, write_condensed);	
				f << endl;
			}
		}		
		cout << "Deleted!" << endl;
		f.close();
		loadrec();
	}

	// sorts by name of product
	void AmaApp::sort() {
		sict::sort(prod, no);
	}

	// searches array of iProducts to find a product
	// with a matching SKU, if found, the address is returned.
	iProduct *AmaApp::find(const char *s) const {
		iProduct *p = nullptr;
		for(int i = 0; i < no && p == nullptr; i++) {
			if(strcmp(s, prod[i]->getsku()) == 0) {
				p = prod[i];
			}
		}

		return p;
	}

	// Adds to quantity availiable
	void AmaApp::addqty(iProduct *p) {
		int num = 0;
		p->write(cout, write_human);
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> num;

		if(!cin.fail()) {
			if(p->qtyNeeded() - p->qtyAvailable() >= num) {
				*p += num;
				saverec();
			} else {
				int need = p->qtyNeeded();
				int avail = p->qtyAvailable();
				*p += need - avail;
				cout << "Too many items; only " 
				<< need - avail << " is needed. Please "
				<< "return the extra " 
				<< (num - (need - avail))
				<< " items." << endl;
			}

			cout << endl << "Updated!" << endl;

		} else {
			cin.clear();
			clear();
			cout << "Invalid quantity value!" << endl;	
		}
		
	}	

	// adds a product to the array
	void AmaApp::addprod(char t) {
		if(no != MAX_PRODUCTS_SIZE) {
			iProduct *p = nullptr;
			p = createInstance(t);
			cin >> *p;
			if(!cin.fail()) {
				prod[no] = p;
				no++;
				saverec();
				cout << endl << "Success!" << endl << endl;
			} else {
				cout << endl << *p << endl << endl;
				delete p;
				cin.clear();
			}
		} else {
			cout << "Cannot add more products!" << endl;
		}
	}	

	// prompts user for a sku and returns
	// a pointer to the iProduct if it exists
	iProduct *AmaApp::get() const {
		char tmps[max_length_sku + 1];
		iProduct *tmp = nullptr;
		cout << "Please enter the product SKU: ";
		cin.getline(tmps, max_length_sku);
		cout << endl;
		if((tmp = find(tmps)) == nullptr) {
			cout << "No such product!";
		}
		return tmp;
	}

	// calls the proper function based on user input
	int AmaApp::run() {
		bool done = false;
		iProduct *tmp = nullptr;
		while(!done) {
			switch(menu()) {
				case LIST_PRODUCTS:
				listprods();
				break;

				case SEARCH_PRODUCT:
				if((tmp = get()) != nullptr) {
					cout << *tmp;
				}
				cout << endl;
				pause();
				break;

				case ADD_NON_PERISH:
				addprod('N');
				clear();
				break;

				case ADD_PERISH:
				addprod('P');
				clear();
				break;

				case ADD_QUANTITY:
				if((tmp = get()) != nullptr) {
					addqty(tmp);
				} else {
					cout << endl;
				}
				cout << endl;
				break;

				case DELETE_PRODUCT:
				if((tmp = get()) != nullptr) {
					deleterec(tmp);
				} else {
					cout << endl;
				}
				break;
				case SORT:
				sort();
				saverec();
				cout << "Sorted!" << endl << endl;
				break;

				case EXIT:
				cout << "Goodbye!" << endl;
				done = true;
				break;
				default:
				cout << "~~~Invalid selection, try again!~~~"
				<< endl;
				pause();
				break;
			}
		}
		return 0;
	}

}
