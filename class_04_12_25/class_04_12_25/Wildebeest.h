#pragma once
#include "Herbivore.h"
#include <iostream>
using namespace std;

class Wildebeest : public Herbivore {
public:
	Wildebeest() : Herbivore(12.0) {}
	Wildebeest(double w) : Herbivore(w) {}
	void Die() override {
		cout << "Wildebeest has died." << endl;
		isAlive = false;
	}
};