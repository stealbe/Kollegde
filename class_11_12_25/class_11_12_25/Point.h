#pragma once
#include <iostream>
using namespace std;

class Point {
protected:
	double x;
	double y;
	friend ostream& operator<<(ostream& os, const Point& point) {
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
	friend iostream& operator>>(iostream& is, Point& point) {
		is >> point.x >> point.y;
		return is;
	}
public:
	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
};