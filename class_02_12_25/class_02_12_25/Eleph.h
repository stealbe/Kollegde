#pragma once
#include "Herbivore.h"
#include <iostream>
using namespace std;

class Eleph : public Herbivore {	
	public:
		Eleph() : Herbivore() {}
	virtual void eat() const {
		cout << "Elephant is eating grass and fruits." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Elephant is standing still." << endl;
			return;
		}
		if (z < 0) throw invalid_argument("Elephant cannot move below ground level.");
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Elephant is walking to new position (" << this->x << ", " << this->y << ")." << endl;
	}
};