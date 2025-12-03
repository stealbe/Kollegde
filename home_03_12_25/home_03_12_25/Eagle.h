#pragma once
#include "Carnivore.h"
#include <iostream>
using namespace std;

struct IFly {
	virtual void fly(double x = 0, double y = 0, double z = 0) = 0;
};

class Eagle : public Carnivore, public IFly
{	
	public:
		Eagle() : Carnivore() {}
	virtual void eat() const {
		cout << "Eagle is eating fish and small animals." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Eagle is soaring in place." << endl;
			return;
		}
		if (z < 0) throw invalid_argument("Eagle cannot fly below ground level.");
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Eagle is flying to new position (" << this->x << ", " << this->y << ", " << this->z << ")." << endl;
	}
	virtual void fly(double x = 0, double y = 0, double z = 0) {
		move(x, y, z);
	}
};