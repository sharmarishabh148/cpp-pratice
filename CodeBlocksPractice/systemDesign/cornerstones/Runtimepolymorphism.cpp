#include <iostream>
using namespace std;

class Animal {
public:
	virtual void printAnimal() { // virtual method
		cout<< "I am from the Animal class" <<endl;
	}

	void printAnimalTwo() {
		cout<< "I am from the Animal class" <<endl;
	}
};

class Lion: public Animal {
public:
	void printAnimal() { // method overriding
		cout<< "I am from the Lion class" <<endl;
	}
};

int main() {
	Animal *animal;
	Lion lion;
	animal = &lion;

	animal->printAnimal();
	animal->printAnimalTwo();

	return 0;
}
