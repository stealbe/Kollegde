#pragma once

class Entity {
	protected:
		int id;
		double x, y, z;
public:
	Entity() : id(0), x(0), y(0), z(0) {}
	Entity(int id, double x, double y, double z)
		: id(id), x(x), y(y), z(z) {}
	int getId() const { return id; }
	void getPosition(double& outX, double& outY, double& outZ) const {
		outX = x;
		outY = y;
		outZ = z;
	}
	void setPosition(double newX, double newY, double newZ) {
		x = newX;
		y = newY;
		z = newZ;
	}
	double GetX() const { return x; }
	double GetY() const { return y; }
	double GetZ() const { return z; }
};