// Workshop 3 - Classes And Privacy
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Book.cpp

#include <iostream>
// I used the iomanip library as it makes 
// printing data to stdout much easier.
//
// I hope that's okay
#include <iomanip>
// required for the strncpy function
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict {

	// ISBN validation algorithm
	// Requires an isbn number to validate
	bool Book::isValidISBN(const long long isbn) const{

		int total = 0;
		int checkDigit = isbn % 10;
		long long tmp = isbn / 10;

		for(int i = 0; i < ISBN_SIZE - 1; i++) {
			// if even...
			if(i % 2 == 0) {
				// retrieve odd digit and multiply by 3
				// add to total
				total += (tmp % 10) * 3;
			// if odd..
			}else {
				// add retrieved digit to total
				total += tmp % 10;
			}
			// truncate a digit after every 
			// iteration
			tmp /= 10; 
		}

		// checks if difference between the total and the 
		// next highest integer multiple of ten is equal
		// to the check digit
		return (10 - (total % 10)) == checkDigit;

	}

	// Checks if isbn value is within proper range
	bool Book::inRange(long long value) const{

		return value >= min_isbn_value && value <= max_isbn_value;

	}

	// sets all the data members of the book object.
	// if parameters are invalid, object will be put
	// in an empty state.
	void Book::set(const char *aName, const char *fName, 
			const char *title, long long _isbn){

		// if isbn is not 13 digits, validation algorthim will 
		// not be needed.
		if(inRange(_isbn) && isValidISBN(_isbn)) {
			strncpy(authorName, aName, max_name_size);
			strncpy(familyName, fName, max_name_size);
			strncpy(bookTitle, title, max_title_size);
			isbn = _isbn;
		}else {
			isbn = 0;
		}

	}

	// If object is not currently in an empty state, 
	// the year published and price of book data members
	// will be reassigned to what the client passed as arguments
	void Book::set(const int year, const double price) {

		if(!isEmpty()){
			yearPublished = year;
			bookPrice = price;
		}

	}

	// checks for empty state.
	// returns true if in empty state.
	bool Book::isEmpty() const {

		return isbn == 0;

	}

	// displays the data members within the object.
	void Book::display(bool singleline) const {

		if(!singleline) {
			if(!isEmpty()) {
				cout << "Author: " << familyName << ", " 
					<< authorName << endl;
				cout << "Title: " << bookTitle << endl;
				cout << "ISBN-13: " << isbn << endl;
				cout << "Publication Year: " 
					<< yearPublished << endl;
				cout << "Price: " << bookPrice << endl;
			}else {
				cout << "The book object is empty!" << endl;
			}
		}else {
			if(!isEmpty()) {
				cout << "|"
				<< setw(max_name_size) << familyName << "|"
				<< setw(max_name_size) << authorName << "|" 
				<< setw(max_title_size) << left 
				<< bookTitle << "|" 
				<< setw(ISBN_SIZE) << right << isbn << "|"
				<< setw(YEAR_WIDTH) << yearPublished << "|"
				<< setw(BOOK_PRICE_WIDTH) << fixed 
				<< setprecision(PRICE_PRECISION)
				<< bookPrice << "|" 
				<< setprecision(DEFAULT_PRECISION) 
				<< resetiosflags(ios::fixed) << endl;
			}else {
				cout << "|"
				<< setw(EMPTY_MSG_WIDTH) << left 
				<< "The book object is empty!"
				<< right << "|" << endl;
			}
		}

	}

}
