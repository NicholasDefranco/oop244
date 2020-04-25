// Workshop 7 - Derived Classes
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: SuperHero.h

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		// data members
		int bonus;
		int defend;

		public:
		// default constructor
		SuperHero();
		// overloaded constructor
		SuperHero(const char *, int, int, int, int);	
	
		// returns attack if SuperHero is alive
		int attackStrength() const;

		// returns defense
		int getdefend() const;
	
	};

	// Allows two SuperHeros to fight each other
	const SuperHero& operator*(const SuperHero& h1, const SuperHero& h2);

}

#endif
