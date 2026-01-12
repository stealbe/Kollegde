#pragma once

#include "Carnivore.h"
#include <iostream>
using namespace std;

struct ICrawl {
	virtual void crawl(double x = 0, double y = 0, double z = 0) = 0;
};

class Snake : public Carnivore
{
public:
	Snake() : Carnivore() {}
	virtual void eat() const {
		cout << "Snake is eating rodents and birds." << endl;
	}
	virtual void move(double x = 0, double y = 0, double z = 0)
	{
		if (x == 0 && y == 0 && z == 0) {
			cout << "Snake is slithering in place." << endl;
			return;
		}
		this->x += x;
		this->y += y;
		this->z += z;
		cout << "Snake is slithering to new position (" << this->x << ", " << this->y << ", " << this->z << ")." << endl;
	}
	virtual void crawl(double x = 0, double y = 0, double z = 0) {
		move(x, y, z);
	}
};