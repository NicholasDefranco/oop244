#include <iostream>

// Classes to show casting of inherite types
class Base {
public:
	virtual void display() const { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
	void display() const { std::cout << "Derived\n"; }
};

// A function, foo, to show const_cast
void foo(int* p) {
	std::cout << *p << std::endl;
}

int main() {
	// *** Static Casts ***
	double hours;
	int minutes;

	std::cout << "Enter minutes : ";
	std::cin >> minutes;
	hours = static_cast<double>(minutes) / 60;  // int and float are related 
	std::cout << "In hours, this is " << hours << std::endl;

	// Static cast with a pointer will fail
	//int* fails = static_cast<int*>(minutes); 

	// *** Reinterpret Casts
	int x = 2;
	int* p = reinterpret_cast<int*>(x);  // int and int* are unrelated 
	std::cout << p << std::endl;

	// Reinterpret casts with related types will fail.
	//int x = 2;
	//double y = reinterpret_cast<double>(x);  // types are related

	// *** Constant Casts ***
	const int cc = 3;
	const int* cc_p = &cc;

	int* b = const_cast<int*>(cc_p);   // remove const status
	foo(b);                            // foo expects int* and not const int*

	// Const casts reject conversions between different types
	//const int x = 2;
	//double y = const_cast<double>(x); // FAILS

	// *** Dynamic Casts (Hierarchal Casts)

	// Downcast
	Base* b1 = new Base;
	Base* b2 = new Derived;
	Derived* d1 = dynamic_cast<Derived*>(b1);
	Derived* d2 = dynamic_cast<Derived*>(b2);

	if (d1 != nullptr)
		d1->display();
	else
		std::cerr << "d1 is not derived" << std::endl;

	if (d2 != nullptr)
		d2->display();
	else
		std::cerr << "d2 is not derived" << std::endl;

	delete b1;
	delete d2;

	// Upcast
	Base* bs;
	Derived* dr = new Derived;

	bs = dynamic_cast<Base*>(dr);  // in the same hierarchy 

	if (bs != nullptr)
		bs->display();
	else
		std::cerr << "Mismatch" << std::endl;
	
	dr->display();
	delete dr;

	char dummy;
	std::cin >> dummy;
}
