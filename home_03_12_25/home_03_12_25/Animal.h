#pragma once
#include "Entity.h"

struct IAnimal {
	virtual void move(double x = 0, double y = 0, double z = 0) = 0;
	virtual void eat() const = 0;
};


class Animal : public IAnimal, public Entity
{
	public:
	Animal() : Entity() {}
};