// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Product.cpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include "Product.h"

using namespace std;

namespace ama {
	
	// accepts a message and stores the message into error 
	// state object
	void Product::message(const char *m) {
		err = m;
	}

	// returns true if err contains an error message
	bool Product::isClear() const {
		return !err;
	}

	// one/default constructor, sets object to empty state
	// and initializes the constant
	Product::Product(char t) : type(t) {
		name = nullptr;
		sku[0] = '\0';
		unit[0] = '\0';
		name = nullptr;
		demand = -1;
		hand = -1;
		price = -1.0;
		taxable = false;
	}	

	// validation constructor, validates all incoming data,
	// if valid current object will store the data
	Product::Product(const char *s, const char *n, const char *u,
			double p, int d, int h, bool t) : type('N') {

		if(s == nullptr || s[0] == '\0' || n == nullptr || n[0] =='\0'
			|| u == nullptr || u[0] == '\0' || p < 0.0 || d < 0 
			|| h < 0) {

			*this = Product();
		} else {

			strncpy(sku, s, max_length_sku);
			
			if(strlen(n) > max_length_name) {
				name = new char[max_length_name + 1];
				strncpy(name, n, max_length_name);
			} else {
				name = new char[strlen(n) + 1];
				strncpy(name, n, strlen(n));
			}

			strncpy(unit, u, max_length_unit);

			demand = d;
			hand = h;
			price = p;
			taxable = t;
		}
		

	}

	// copy constructor
	Product::Product(const Product& p) : Product(p.type){
		*this = p;
	}

	// destructor, de-allocates name data member
	Product::~Product() {
		delete [] name;
	}

	// copy assignment operator
	Product& Product::operator=(const Product& p) {
		
		if(this != &p) {
			
			strncpy(sku, p.sku, max_length_sku);
			
			delete [] name;

			if(p.name != nullptr) {
				if(strlen(p.name) > max_length_name) {
					name = new char[max_length_name + 1];
					strncpy(name,p.name, max_length_name);
					name[max_length_name] = '\0';
				} else {
					name = new char[strlen(p.name) + 1];
					strncpy(name, p.name, strlen(p.name));
					name[strlen(p.name)] = '\0';
				}
			} else {
				name = nullptr;
			}


			strncpy(unit, p.unit, max_length_unit);

			demand = p.demand;
			hand = p.hand;
			price = p.price;
			taxable = p.taxable;
		}

		return *this;

	}

	// adds to the amount on hand
	int Product::operator+=(int c) {
		return c > 0 ? hand += c : hand;
	}
	
	// relational operators
	bool Product::operator==(const char *s) const {
		return strcmp(sku, s) == 0;
	}

	bool Product::operator>(const char *s) const {
		return strcmp(sku, s) > 0;
	}

	bool Product::operator>(const iProduct& p) const {
		return strcmp(name, p.getname()) > 0;
	}

	// returns hand
	int Product::qtyAvailable() const {
		return hand;
	}

	// returns demand
	int Product::qtyNeeded() const {
		return demand;
	}	

	// returns the address of the name data member
	const char *Product::getname() const {
		return name;
	}

	const char *Product::getsku() const {
		return sku;
	}

	// calculates the cost of the total amount of the
	// specific product
	double Product::total_cost() const {
		return round(taxable ? (price * hand) * (1 + tax_rate) * 100 
						: price * hand * 100) / 100;
	}

	// returns true if empty
	bool Product::isEmpty() const {
		return hand < 0;
	}

	// reads a string from input stream and stores it
	// into a dynamic character array which is returned
	const char *Product::alloc(istream& in, const char *msg, int len, 
								char delim) {
		
		if(msg != nullptr) {
			cout << setw(max_length_label) << msg;
		}
		char tmp = '\0';
		char *str = nullptr;
		char *old = nullptr;
		int i = 0;

		while((tmp = in.get()) != delim && i < len) {
			old = new char[i + 2];
			for(int j = 0; j < i; j++) {
				old[j] = str[j];
			}
			old[i] = tmp;
			old[i + 1] = '\0';
			delete [] str;
			str = old;
			i++;
		}

		return str;

	}

	// generic function to assist reading the input stream
	// and storing into the reference passed
	template<typename T>
	void Product::get(istream& in, const char *emsg, const char *msg, 
								T& value) {
		if(!is_same<T, char>::value) {
			if(!in.fail()) {
				cout << setw(max_length_label) << msg;
				in >> value;
				if(in.fail() || value < (T)0) {
					in.setstate(ios::failbit);
					message(emsg);
				}
			}
		} else {
			if(!in.fail()) {
				cout << setw(max_length_label) << msg;
				in >> value;
				if(value != 'y' && value != 'Y' 
					&& value != 'n'	&& value != 'N') {
					in.setstate(ios::failbit);
					message(emsg);
				}
			}
		}
	}

	// reads from specified input stream
	istream& Product::read(istream& in, bool inter) {
		if(!inter) {
			in.getline(sku, max_length_sku, ',');

			sku[max_length_sku] = '\0';
			
			delete [] name;

			const char *tmp = alloc(in, nullptr, max_length_name, 
									',');


			name = new char[strlen(tmp) + 1];

			strncpy(name, tmp, strlen(tmp));

			name[strlen(tmp)] = '\0';

//			cout << name << endl;

			in.getline(unit, max_length_unit, ',');

			unit[max_length_unit] = '\0';

//			cout << unit << endl;

			in >> price;

//			cout << price << endl;

			in.ignore();
			in >> taxable;

//			cout << taxable << endl;

			in.ignore();
			in >> hand;

//			cout << hand << endl;

			in.ignore();
			in >> demand;

//			cout << demand << endl;

//			char tmp2;
//			while((tmp2 = in.get()) != ',' && tmp2 != '\n' && tmp2 != EOF);
			in.ignore();

//			cout << in.get() << endl;

			delete [] tmp;

		} else {
			cout << right;

			const char *s = alloc(in, "Sku: ", max_length_sku);

			const char *n = alloc(in, "Name (no spaces): ", 
							max_length_name);
			
			

			const char *u = alloc(in, "Unit: ", max_length_unit);

			char t;
			double p;
			int h;
			int d;

			get(in, "Only (Y)es or (N)o are acceptable!", 
						"Taxed? (y/n): ", t);
			get(in, "Invalid Price Entry!", "Price: ", p);
			get(in, "Invalid Quantity Available Entry!", 
						"Quantity on hand: ", h);
			get(in, "Invalid Quantity Needed Entry!", 
						"Quantity needed: ", d);

			if(!in.fail()) {
				*this = Product(s, n, u, p, d, h, (t == 'y' 
								|| t == 'Y'));
			}

			cout.unsetf(ios::right);

			delete [] s;
			delete [] n;
			delete [] u;

		}

//		in.ignore();

		return in;
	}

	// outputs to specified output stream
	ostream& Product::write(ostream& out, int mode) const {
		if(!isClear() || isEmpty()) {
			cout << err;
		} else {
			switch(mode) {
				case write_condensed:
				
				out << type << "," << sku << "," << name
				<< "," << unit << "," << fixed 
				<< setprecision(2) << price << setprecision(6)
				<< "," << (taxable ? '1' : '0') << "," 
				<< hand << "," << demand;

				out.unsetf(ios::fixed);

				break;
				case write_table:
				
				out << " " << setw(max_length_sku) << right
				<< sku << " | " << left;

				if(strlen(name) > 16) {
					for(int i = 0; i < 13; i++) 
						out << name[i];
					out << "...";
				} else {
					out << setw(16) << name;
				}
				
				out << " | " << setw(max_length_unit) << unit << " | " 
				<< right << fixed << setw(7) 
				<< setprecision(2) << price 
				<< setprecision(6);

				out.unsetf(ios::fixed);

				out << " | " << setw(3)
				<< (taxable ? "yes" : "no") << " | " 
				<< setw(6) << hand << " | " << setw(6) 
				<< demand << " |";

				if(out.fail()) {
					cout << "error" << endl;
				}
				
				break;
				case write_human:

				out << right << setw(max_length_label) 
				<< "Sku: " << sku << endl 
				<< setw(max_length_label) << "Name: " << name
				<< endl << setw(max_length_label) 
				<< "Price: " << fixed << setprecision(2) 
				<< price << endl << setw(max_length_label)
				<< "Price after Tax: " << (taxable ? 
				(price * (1 + tax_rate)) : (price)) << endl
				<< setprecision(6);

				out.unsetf(ios::fixed);
				
				out << setw(max_length_label) 
				<< "Quantity Available: " << hand << " "
				<< unit << endl << setw(max_length_label) 
				<< "Quantity Needed: " << demand << " "
				<< unit << endl;

				break;
			}
		}

		return out;
	}

}
