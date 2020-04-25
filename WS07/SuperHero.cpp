// Workshop 7 - Derived Classes
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: SuperHero.cpp

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;

namespace sict {

	// default constructor
	SuperHero::SuperHero() : Hero() {
		bonus = -1;
		defend = -1;
	}

	// overloaded constructor
	SuperHero::SuperHero(const char *n, int h, int a, int b, int d) : Hero(n, h, a) {

		if(b <= 0 || d <= 0) {
			*this = SuperHero();
		} else {
			bonus = b;
			defend = d;
		}

	}

	// returns attack if SuperHero is alive
	int SuperHero::attackStrength() const {
		return isAlive() ? Hero::attackStrength() + bonus : 0;
	}

	// returns defense
	int SuperHero::getdefend() const {
		return defend;
	}

	// Allows two SuperHeros to fight each other
	const SuperHero& operator*(const SuperHero& sp1, const SuperHero& sp2){

		cout << "Super Fight! ";

		SuperHero s1 = sp1;
		SuperHero s2 = sp2;

		s1.setattk(s1.attackStrength() - s2.getdefend());
		s2.setattk(s2.attackStrength() - s1.getdefend());

		Hero tmp = s1.fight(s2);				

		return strcmp(tmp.getname(), sp1.getname()) == 0 ? sp1 : sp2;

	}

}
