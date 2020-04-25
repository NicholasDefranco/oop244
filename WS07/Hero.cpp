// Workshop 7 - Derived Classes
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Hero.cpp

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {

	// default constructor
	// sets Hero object to safe empty state
	Hero::Hero() {
		name[0] = '\0';
		health = -1;
		attk = -1;
	}

	// validation constructor
	// validates all data passed from client
	// if valid, data members will be set to
	// what client suggested
	Hero::Hero(const char *n, int h, int a) {
		if(n == nullptr || n[0] == '\0' || h <= 0 || a <= 0) {
			*this = Hero();
		} else {
			strncpy(name, n, NAME_SIZE);
			health = h;
			attk = a;
		}
	}

	// damages the current object with attack
	// passed as right operand
	void Hero::operator-=(int a) {
		if(a > 0) {
			health -= a;
			if(attk < 0) {
				attk = 0;
			}
		}	

	}

	// returns true if the health of a hero is 
	// greater than zero
	bool Hero::isAlive() const {
		return health > 0;
	}

	// returns a Hero's attack if hero is alive
	int Hero::attackStrength() const {
		return isAlive() ? attk : 0;
	}

	// sets the attack data member
	// if invalid, object is set to
	// safe empty state
	void Hero::setattk(int a) {
		*this = Hero(name, health, a);
	}

	// returns the name of a Hero
	const char *Hero::getname() const {
		return name;
	}

	// prints the hero's name if valid
	ostream& operator<<(ostream& os, const Hero& h) {
		if(!h.isAlive()) {
			cout << "No hero";	
		} else {
			cout << h.name;
		}
		return os;
	}

	// allows two heros to fight each other
	const Hero& Hero::fight(const Hero& hr) const {

		int i = 0;
		bool finish = false;
		Hero h1 = *this;
		Hero h2 = hr;

		cout << *this << " vs " << hr << " : ";

		for(i = 0; i < max_rounds && !finish; i++) {
			h1 -= h2.attackStrength();
			h2 -= h1.attackStrength();
			if(!h1.isAlive() || !h2.isAlive()) {
				finish = true;
			}
		}

		cout << "Winner is ";

		if(h2.isAlive()) {
			cout << hr;
		} else {
			cout << *this;
		}

		cout << " in " << i << " rounds." << endl;

		return h2.isAlive() ?hr : *this;


	}

	// calls fight member function
	const Hero& operator*(const Hero& hr1, const Hero& hr2) {
		cout << "Ancient Battle! ";
		return hr1.fight(hr2);
	}

}
