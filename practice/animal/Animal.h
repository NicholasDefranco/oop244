#include "iAnimal.h"

class Cat : public iAnimal {
	public:
	void display() const;
	void noise() const;

};

class Cow : public iAnimal {
	public:
	void display() const;
	void noise() const;

};

class Horse : public iAnimal {
	public:
	void display() const;
	void noise() const;
};
