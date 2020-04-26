#include <iostream>
#include "piggy.h"

Piggy::Piggy(float start, float capacity) {

	if(start < 0.0f && capacity < start) {
		balance = 0.0f;
		this->capacity = DEFAULT_CAPACITY;
	} else {
		balance = start;
		this->capacity = capacity;
	}

}

void Piggy::set(float start, float capacity) {
	
	*this = Piggy(start, capacity);	

}

bool Piggy::isEmpty() const {

	return balance == 0.0f;

}

std::ostream& operator<<(std::ostream& os, const Piggy& pig) {

	os << "The current balance is $" << pig.balance << endl;
	os << "The Capacity is $" << pig.capacity << endl;

}

Piggy Piggy::operator=(Piggy pig) {

	this->balance = pig.balance;
	this->capacity = pig.capacity;

	return *this;

}

Piggy& Piggy::operator+=(float amount) {
	
	Piggy pig(balance + amount, capacity);

	if(!pig.isEmpty()) 
		*this = pig;

	return *this;

}

Piggy& Piggy::operator-=(float amount) {

	Piggy pig(balance - amount, capacity);

	if(!pig.isEmpty())
		*this = pig;		

	return *this;

}

Piggy& Piggy::operator--() {

	*this += 1.0f;
	return *this;

}

Piggy& Piggy::operator++() { // pre-fix

	*this -= 1.0f;
	return *this;

}

Piggy Piggy::operator--(int) { // post-fix

	Piggy p = *this;
	--(*this);
	return p;

}

Piggy Piggy::operator++(int) {

	Piggy p = *this;
	++(*this);
	return p;

}

float Piggy::getBalance() const {

	return balance;

}

float Piggy::getCapacity() const {

	return capacity;

}

const Piggy& Piggy::getCurrentPiggy() const {

	return *this;

}
