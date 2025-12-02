#pragma once
#include "Carnivore.h"
#include <iostream>
using namespace std;

class Shark : public Carnivore {	
	public:
		Shark() : Carnivore() {}
	virtual void eat() const {
		cout << "Shark is eating fish and marine animals." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Shark is swimming in place." << endl;
			return;
		}
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Shark is swimming to new position (" << this->x << ", " << this->y << ", " << this->z << ")." << endl;
	}
};