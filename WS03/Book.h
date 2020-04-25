// Workshop 3 - Classes And Privacy
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Book.h

// header safeguards
#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict {

	// Max size for title
	const int max_title_size = 32;
	
	// Max size of name
	const int max_name_size = 16;

	// Min ISBN value
	const long long min_isbn_value = 1000000000000LL;

	// Max ISBN value
	const long long max_isbn_value = 9999999999999LL;

	// Amount of digits a ISBN number must have
	const int ISBN_SIZE = 13;

	// Default precision for cout
	const int DEFAULT_PRECISION = 6;

	// Year has a constant width of four
	const int YEAR_WIDTH = 4;

	// Width of the price of a book will
	// be 6 characters when printed
	const int BOOK_PRICE_WIDTH = 6;

	// Precision setting for price printing
	const int PRICE_PRECISION = 2;

	// If obhject is empty, message
	// will have a width of 92 characters
	const int EMPTY_MSG_WIDTH = 92;

	class Book {

		// Statically allocated arrays
		char familyName[max_name_size + 1];
		char authorName[max_name_size + 1];
		char bookTitle[max_title_size + 1];

		// stores a book's ISBN number
		long long isbn;

		// sotres the year when book was published
		int yearPublished;

		// stores the price of the book	
		double bookPrice;
	
		// ISBN validation algorithm
		// Requires an isbn number to validate
		bool isValidISBN(long long) const;

		// Checks if isbn value is within proper range
		bool inRange(long long) const;
		
		public:
		// sets all the data members of the book object.
		// if parameters passed are invalid, object will be put
		// in an empty state.
		void set(const char *, const char *, const char *, long long);

		// sets the yearPublished and bookPrice data members
		// to the values passed as arguments from client code
		// only if Book object if the object is not empty
		void set(const int year, const double price);
	
		// checks for empty state.
		// returns true if in empty state.
		bool isEmpty() const;

		// displays the data members within the object.
		void display(bool = false) const;

	};


}

#endif
