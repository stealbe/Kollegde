#pragma once
#include "Entity.h"


class Animal : public Entity {
	public:
		Animal() : Entity() {}
	virtual void move(double x = 0, double y = 0, double z = 0) = 0;
	virtual void eat() const = 0;
};