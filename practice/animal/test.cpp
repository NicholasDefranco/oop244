#include <iostream>
 #include "Animal.h"

 int main() {
     iAnimal* a = nullptr;

     a = new Cat();
     a->display();
     a->noise();
     delete a;

     a = new Cow();
     a->display();
     a->noise();
     delete a;
 }
