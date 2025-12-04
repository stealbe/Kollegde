#pragma once
#include "Carnivore.h"
#include <iostream>
using namespace std;

class Wolf : public Carnivore {
public:
	Wolf() : Carnivore(18.0) {}
	Wolf(double str) : Carnivore(str) {}
	void Die() override {
		cout << "Wolf has died." << endl;
		isAlive = false;
	}
};