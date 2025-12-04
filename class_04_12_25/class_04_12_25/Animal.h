#pragma once

class Animal {
protected:
	bool isAlive;
public:
	Animal() : isAlive(true) {}
	bool getIsAlive() const { return isAlive; }
	virtual void Die() { isAlive = false; }
};