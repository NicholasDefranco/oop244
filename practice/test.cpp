
#include <iostream>
#include "midterm.h"

int main() {

	int count = 3;

	IceCream *arr = new IceCream[count];
	IceCream *tmp;

	for(int i = 0; i < count; i++) {

		arr[i].set(1, "v");	

	}	

	tmp = new IceCream[count + 1];

	for(int i = 0; i < count; i++) {
		tmp[i] = arr[i];
	}

	delete [] arr;

	arr = tmp;
	tmp = nullptr;
	
	arr[count].set(3, "Chocolate Mint Crackle");

	count++;

	for(int i = 0; i < count; i++) {
		arr[i].display(std::cout);
	}

	delete [] arr;

	arr = nullptr;

	return 0;
}
