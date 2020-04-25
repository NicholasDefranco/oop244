// Workshop 5 - Member Operator Overloads
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Fraction.cpp

// TODO: insert header files
#include <iostream>
#include "Fraction.h"

using namespace std;

// TODO: continue the namespace
namespace sict {

	// TODO: implement the default constructor
	// puts object in a safe empty state
	Fraction::Fraction() {
		num = -1;
		den = -1;
	}

	// TODO: implement the two-argument constructor
	// validates input, if valid data members will be reassigned
	Fraction::Fraction(int n, int d) {
		if(n >= 0 && d > 0)	{
			num = n;
			den = d;
			reduce();
		} else {
			*this = Fraction();
		}
	}

	// TODO: implement the max query
	// returns the greater value out of the numerator and deninator
	int Fraction::max() const {
		return num > den ? num : den;
	}

	// TODO: implement the min query
	// returns the smaller value out of the numerator and deninator
	int Fraction::min() const {
		return max() == den ? num : den;
	}

	// gcd returns the greatest common divisor of num and den
	int Fraction::gcd() const {
		int mn = min();
		int mx = max();
		int g_c_d = 1;

		while(mn != 0) {
			g_c_d = mn;
			mn = mx % mn;
		}

		return g_c_d;
	}

	// TODO: implement the reduce modifier
	// divides both the numerator and the deninator by the gcd
	void Fraction::reduce() {
		int g_c_d = gcd();

		num /= g_c_d;
		den /= g_c_d;
	}

	// TODO: implement the display query
	// displays a fraction if it is valid
	void Fraction::display() const {
		if(!isEmpty()) {
			cout << num;
			if(den != 1 && num != 0) {
				cout << '/' << den;
			}
			cout << flush;
		} else {
			cout << "no fraction stored" << flush;
		}
	}

	// TODO: implement the isEmpty query
	// returns true if deninator is zero or less
	bool Fraction::isEmpty() const {
		return den <= 0;
	}

	// checks if both the current object and argument are empty
	bool Fraction::isEmpty(const Fraction& f) const {
		return isEmpty() || f.isEmpty();
	}

	// assists in fraction computation as calculation logic for addition
	// and subtraction are similar.
	Fraction Fraction::compute(const Fraction& r, int num) const {
		Fraction f = Fraction(); 

		if(!(isEmpty(r))) {
			f = Fraction(num, den * r.den);
		}

		return f;
	}

	// TODO: implement the + operator
	// computes the sum of two fractions if both operands are valid.
	Fraction Fraction::operator+(const Fraction& r) const {
		return compute(r, num * r.den + r.num * den);
	}

	// computes the product of two fractions if both operands are valid.
	Fraction Fraction::operator*(const Fraction& r) const {
		return compute(r, num * r.num);
	}
	
	// checks if the fractions are equal to each other. 
	bool Fraction::operator==(const Fraction& r) const {
		bool valid = !(isEmpty(r));

		if(valid) {
			valid = num == r.num && den == r.den;
		}

		return valid;
	}

	// checks if the fractions are not equal to each other
	bool Fraction::operator!=(const Fraction& r) const {
		return isEmpty(r) ? false : !(*this == r);
	}

	// computes the sum, but result is stored in the current object.
	Fraction& Fraction::operator+=(const Fraction& r) {
		return *this = *this + r;
	}
 
}
