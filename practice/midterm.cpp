#include <iostream>
#include <cstring>
#include "midterm.h"

IceCream::IceCream() {

	numOfScoops = 0;
	flavour[0] = '\0';

}

IceCream::IceCream(int scoops, const char *type) {

	set(scoops, type);

}

void IceCream::set(int scoops, const char *type) {

	if(scoops >= 1 && scoops <= 5 && type != nullptr && strlen(type) > 0) {
		numOfScoops = scoops;
		strncpy(flavour, type, MAX_FLAVOUR_SIZE);
	} else {
		*this = IceCream();
	}

}

bool IceCream::isEmpty() const {

	return numOfScoops == 0;

}

void IceCream::display(std::ostream& os) const{

	if(!isEmpty()) {
		std::cout.width(3);
		std::cout.setf(std::ios::fixed);	
		std::cout.setf(std::ios::right);
		std::cout.fill('0');
		std::cout << numOfScoops;
		std::cout.unsetf(std::ios::fixed);
		std::cout.unsetf(std::ios::right);
		std::cout.fill(' ');
		std::cout <<  " " << flavour << std::endl;
	} else {
		std::cout << "argh" << std::endl;
	}

}
