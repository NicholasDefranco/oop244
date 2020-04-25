// Workshop 5 - Member Operator Overloads
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Fraction.h

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		// numerator
		int num;

		// denominator
		int den;

		// TODO: declare private member functions
		// returns the greater value out of the numerator and deninator
		int max() const;

		// returns the smaller value out of the numerator and deninator
		int min() const;

		// gcd returns the greatest common divisor of num and den
		int gcd() const;

		// divides both the numerator and the deninator by the gcd
		void reduce();

		// checks if both the current object and argument are empty
		bool isEmpty(const Fraction&) const;

		// assists in fraction computation as calculation logic for 
		// addition and subtraction are similar.
		Fraction compute(const Fraction& r, int num) const;

		public:
		// TODO: declare public member functions

		// puts object in a safe empty state
		Fraction();

		// validates input, if valid data members will be reassigned
		Fraction(int n, int d);
		
		// returns true if deninator is zero or less
		bool isEmpty() const;

		// displays a fraction if it is valid
		void display() const;

		// TODO: declare the + operator overload
		//computes the sum of two fractions if both operands are valid
		Fraction operator+(const Fraction& r) const;

		// computes the product of two fractions if both operands are 
		// valid.
		Fraction operator*(const Fraction& r) const;

		// checks if the fractions are equal to each other. 
		bool operator==(const Fraction& r) const;

		// checks if the fractions are not equal to each other
		bool operator!=(const Fraction& r) const;

		// computes the sum, but result is stored in the current 
		// object.
		Fraction& operator+=(const Fraction& r);

	};

}

#endif
