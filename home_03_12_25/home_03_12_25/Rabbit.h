#pragma once
#include "Herbivore.h"
#include <iostream>
using namespace std;

class Rabbit : public Herbivore {	
	public:
		Rabbit() : Herbivore() {}
	virtual void eat() const {
		cout << "Rabbit is eating vegetables and herbs." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Rabbit is hopping in place." << endl;
			return;
		}
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Rabbit is hopping to new position (" << this->x << ", " << this->y << ")." << endl;
	}
};