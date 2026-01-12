#pragma once
#include "Herbivore.h"
#include <iostream>
using namespace std;

class Giraffe : public Herbivore {	
	public:
		Giraffe() : Herbivore() {}
	virtual void eat() const {
		cout << "Giraffe is eating leaves from tall trees." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Giraffe is standing still." << endl;
			return;
		}
		if (z < 0) throw invalid_argument("Giraffe cannot move below ground level.");
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Giraffe is walking to new position (" << this->x << ", " << this->y << ")." << endl;
	}
};