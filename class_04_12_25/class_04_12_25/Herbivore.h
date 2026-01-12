#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Herbivore : public Animal {
protected:
	double weight;
public:
	Herbivore() : weight(10.0) {}
	Herbivore(double w) : weight(w) {}
	double getWeight() const { return weight; }
	void setWeight(double w) { weight = w; }
	void Eat() {
		cout << "Herbivore is eating grass." << endl;
		weight += 10;
	}
};