#pragma once
#include "Carnivore.h"
#include <iostream>
using namespace std;

class Lion : public Carnivore {
public:
	Lion() : Carnivore(20.0) {}
	Lion(double str) : Carnivore(str) {}
	void Die() override {
		cout << "Lion has died." << endl;
		isAlive = false;
	}
};