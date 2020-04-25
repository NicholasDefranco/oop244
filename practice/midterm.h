#include<iostream>

const int MAX_FLAVOUR_SIZE = 18;

class IceCream {

	int numOfScoops;
	char flavour[MAX_FLAVOUR_SIZE + 1];

	public:
	IceCream();
	IceCream(int, const char *);

	void set(int, const char *);
	bool isEmpty() const;
	void display(std::ostream&) const;
	IceCream& operator++(int);
	IceCream operator-(int) const;

};
