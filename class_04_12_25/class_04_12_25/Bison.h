#pragma once
#include "Herbivore.h"
#include <iostream>
using namespace std;

class Bison : public Herbivore {
public:
	Bison() : Herbivore(14.0) {}
	Bison(double w) : Herbivore(w) {}
	void Die() override {
		cout << "Bison has died." << endl;
		isAlive = false;
	}
};