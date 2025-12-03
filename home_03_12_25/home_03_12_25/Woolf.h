#pragma once
#include "Carnivore.h"
#include <iostream>
using namespace std;

class Woolf : public Carnivore {	
	public:
		Woolf() : Carnivore() {}
	virtual void eat() const {
		cout << "Woolf is eating meat." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Woolf is standing still." << endl;
			return;
		}
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Woolf is running to new position (" << this->x << ", " << this->y << ")." << endl;
	}
};