#include "h1.h"
#include "Transaction.h"

int main() {

	Transaction tr;

	for(int i = 0; i < NO_TRANSACTIONS; i++) {
		// call member functions on transaction object
		// no need to pass args as the member function 
		// has direct access to data memebers. 
		tr.enter();
		tr.display();
	}

}
