#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include <iostream>
using namespace std;

class Carnivore : public Animal {
protected:
	double strength;
public:
	Carnivore() : strength(15.0) {}
	Carnivore(double str) : strength(str) {}
	void Eat(Herbivore& prey) {
		if (prey.getIsAlive()) {
			if (prey.getWeight() > strength)
			{
				cout << "Carnivore failed to catch the prey." << endl;
				strength -= 10;
			}
			else {
				cout << "Carnivore has eaten the prey." << endl;
				prey.Die();
				strength += 10;
			}
		}
	}
};