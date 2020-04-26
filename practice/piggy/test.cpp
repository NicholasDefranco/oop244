#include <iostream>
#include "piggy.h"

using namespace std;

int main() {

	float amount = 0.0f;
	int choice = -1;

	Piggy pig(50);

	cout.setf(ios::fixed);
	cout.precision(2);

	while(choice != 0) {

		cout << "1. deposit " << endl;
		cout << "2. withdraw " << endl;
		cout << "3. get balance " << endl;
		cout << "4. get capacity " << endl;
		cout << "0. quit " << endl;
		
		cout << "Enter an option: ";
		cin >> choice;

		switch (choice) {
			
		case 1:
			cout << "Enter a deposit amount: " ;
			cin >> amount;
			pig.deposit(amount);
			break;
		case 2:
			cout << "Enter a withdraw amount: ";
			cin >> amount;
			pig.withdraw(amount);
			break;
		case 3:
			cout << "Balance: " << pig.getBalance() << endl;
			break;
		case 4:
			cout << "Capacity: " << pig.getCapacity() << endl;
			break;
		case 0:
			cout << "Bye!!!" << endl;
			break;
		default:
			cout << "Invalid choice!!!" << endl;
			break;
		}

	}

	return 0;
}
