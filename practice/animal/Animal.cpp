#include <iostream>
#include "Animal.h"

using namespace std;

void Horse::display() const {
	cout << "Horse" << endl;
}

void Horse::noise() const {
	cout << "yee-haw" << endl;
}

void Cat::display() const {
	cout << "Cat" << endl;
}

void Cat::noise() const {
	cout << "Meow" << endl;
}

void Cow::display() const {
	cout << "Cow" << endl;
}

void Cow::noise() const {
	cout << "MOOOO!" << endl;
}
