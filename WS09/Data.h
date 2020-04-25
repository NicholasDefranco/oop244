// Workshop 9 - Templates
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Data.h

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <iomanip>
#include <cstring>

namespace sict {
	// These number defines the output column width for a single data 
	// field
	const int COLUMN_WIDTH = 15;
	const int TITLE_WIDTH = 20;

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T *data, int n) {
		T large = data[0];
		for(int i = 1; i < n; i++) {
			if(data[i] > large) {
				large = data[i];
			}
		}

		return large;

	}

	// min returns the smallest item in data
	//
	template<typename T>
	T min(const T *data, int n) {
		T small = data[0];
		for(int i = 1; i < n; i++) {
			if(data[i] < small) {
				small = data[i];
			}
		}
		return small;
	}

        
	// sum returns the sum of n items in data
	//    
	template<typename T>
	T sum(const T *data, int n) {
		T s = (T)0;
		for(int i = 0; i < n; i++) {
			s += data[i];
		}
		return s;
	}
   
	// average returns the average of n items in data
	//
	template<typename T>
	double avg(const T *data, int n) {
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field 
	// to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(std::istream& in, T *data, int n) {
		for(int i = 0; i < n && !in.fail(); i++) {
			in >> data[i];
			in.ignore();
		}	
		return !in.fail();
	}

	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char *name, const T *data, int n) {
		std::cout << std::right << std::setw(TITLE_WIDTH) << name;
		for(int i = 0; i < n; i++) {
			std::cout << std::setw(COLUMN_WIDTH) << data[i];
		}
		std::cout << std::endl;
		std::cout.unsetf(std::ios::right);
	}
	


	template<typename T>
	bool readRow(std::istream& input, const char* name, T *data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,...

		if (ok) {
			// read the name  first

			input.getline(rowname, 2000, ',');

			// check that the caller is reading the correct row 
			// (name)
			// - if the user is reading the wrong row, return an 
			// error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " 
					<< name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, 
							const int*, const int);

}

#endif
