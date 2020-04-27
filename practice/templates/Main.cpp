#include <iostream>
#include "swap.h"
#include "array.h"

// Calling templated functions
void templatedFunctions() {
	double a = 2.3;
	double b = 4.5;
	long   d = 78;
	long   e = 567;

	swap(a, b); // compiler generates
				// swap(double, double)

	std::cout << "Swapped values are " <<
		a << " and " << b << std::endl;

	swap(d, e); // compiler generates
				// swap(long, long)

	std::cout << "Swapped values are " <<
		d << " and " << e << std::endl;
}

// Using class templates
void classTemplates() {
	Array<int, 5> ages;

	for (int i = 0; i < 5; i++)
		ages[i] = i * i;

	//b = a;

	for (int i = 0; i < 5; i++)
		std::cout << ages[i] << ' ';

	std::cout << std::endl;
}

int main() {
	//templatedFunctions();
	classTemplates();

	char dummy;
	std::cin >> dummy;
}