#ifndef PIGGY_H
#define PIGGY_H

#include<iostream>

#define DEFAULT_CAPACITY 200

class Piggy {

	float balance;
	float capacity;

	public:
	Piggy(float = 0.0f, float = DEFAULT_CAPACITY);
	void set(float = 0.0f, float = DEFAULT_CAPACITY);
	bool isEmpty() const;
	friend std::ostream& operator<<(std::ostream&, const Piggy&);
	float getBalance() const;
	float getCapacity() const;
	const Piggy& getCurrentPiggy() const; 
	Piggy operator=(Piggy);
	Piggy& operator+=(float);
	Piggy& operator-=(float);
	Piggy& operator++();
	Piggy& operator--();
	Piggy operator++(int);
	Piggy operator--(int);

};

#endif 
