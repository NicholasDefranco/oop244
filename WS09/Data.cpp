// Workshop 9 - Templates
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: Data.cpp

#include <iostream>
#include <iomanip>
#include "Data.h"

using namespace std;

namespace sict {

	// answers outputs statistics for visual validation of data
	void answers(const int* year, const int* population, 
		const int* violentCrime, const double* violentCrimeRate, 
		const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 
		// 1000000 would yield "6"

		cout << "Population change from 2000 to 2004 is "
//		<< (population[n - 1] - population[0]) / 1000000 
//		<< "." 
//		<< ((((population[n - 1] - population[0]) % 1000000)) 
//		/ 1000 + 5) / 10 << " million" << endl;
		// 5 is for rounding

		// or ...
		
		<< setprecision(2) << fixed
		<< static_cast<double>((population[n - 1] - population[0]) 
		/ 1000) / 1000 << " million" << endl;
		
		// Q2. print whether violent crime rate has gone up or down 
		// between 2000 and 2005

		cout << "Violent Crime trend is ";
		if(violentCrimeRate[n - 1] < violentCrimeRate[0]) {
			cout << "down";
		} else {
			cout << "up";
		}

		cout << endl;

		// Q3 print the GTA number accurate to 0 decimal places

		int av = avg(grandTheftAuto, n);
		cout << "There are "
//		<< (av / 1000000) << "." << 
//			((av % 1000000) / 1000 + 5) / 10;
		// 5 is for rounding

		// or ...

		<< static_cast<double>(av / 1000) / 1000 << setprecision(6);

		cout.unsetf(ios::fixed);

		cout << " million Grand Theft Auto incidents on average a"
		<< " year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was "
			<< static_cast<int>(min(violentCrimeRate, n)) << endl;

		cout << "The Maximum Violent Crime rate was " 
			<< static_cast<int>(max(violentCrimeRate, n)) << endl;

	}


}

