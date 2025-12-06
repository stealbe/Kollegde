#pragma once

class Entity {
protected:
	bool isActive;
public:
	Entity() : isActive(true) {}
	Entity(bool isActive) : isActive(isActive) {}
	virtual void arrive() = 0;
	virtual bool leave() = 0;
	bool getIsActive() const {
		return isActive;
	}
};