// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Sort.h

#ifndef SICT_SORT_H
#define SICT_SORT_H

#include <cstring>
#include "iProduct.h"

namespace sict {

	// generic bubble sort implementation
	template<typename T>
	void sort(T **arr, int len) {
		int i = len;
		T *tmp;
		bool done = false;

		while(!done) {
			i--;
			done = true;
			for(int j = 0; j < i; j++) {
				if(strcmp(arr[j]->getname(), 
						arr[j + 1]->getname()) > 0) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
					done = false;
				}
			}	
		}
	}
}

#endif
