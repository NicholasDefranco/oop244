// Workshop 7 - Derived Classes
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Hero.h

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>

namespace sict {

	// constants
	const int max_rounds = 100;
	const int NAME_SIZE = 40;

	class Hero {

		// data members
		char name[NAME_SIZE + 1];
		int health;	
		int attk;

		protected:
		// returns true if the health of a hero is 
		// greater than zero
		bool isAlive() const;

		// damages the current object with attack
		// passed as right operand
		void operator-=(int);

		public:
		// default constructor
		// sets Hero object to safe empty state
		Hero();
	
		// validation constructor
		// validates all data passed from client
		// if valid, data members will be set to
		// what client suggested
		Hero(const char *, int, int);

		// returns the name of a Hero
		const char *getname() const;

		// returns a Hero's attack if hero is alive
		int attackStrength() const;

		// sets the attack data member
		// if invalid, object is set to
		// safe empty state
		void setattk(int);

		// allows two heros to fight each other
		const Hero& fight(const Hero&) const;

		// prints the hero's name if valid
		friend std::ostream& operator<<(std::ostream&, const Hero&);

	};	

	// calls fight member function
	const Hero& operator*(const Hero&, const Hero&);

}

#endif
