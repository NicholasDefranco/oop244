
#include <iostream>
#include "piggy.h"

using namespace std;

int main() {
	
	Piggy pig;

	pig += 20.40f;

	Piggy copy;

	copy = pig;

	cout << pig;
	cout << copy;

	return 0;
}
