#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Figure {
	protected:
		Point* points;
		int numPoints;
		friend ostream& operator<<(ostream& os, const Figure& figure) {
			os << "Figure with " << figure.numPoints << " points: ";
			for (int i = 0; i < figure.numPoints; ++i) {
				os << figure.points[i];
				if (i < figure.numPoints - 1) {
					os << ", ";
				}
			}
			return os;
		}
		friend iostream& operator>>(iostream& is, Figure& figure) {
			for (int i = 0; i < figure.numPoints; ++i) {
				is >> figure.points[i];
			}
			return is;
		}
public:
	Figure(Point* points, int numPoints) : numPoints(numPoints) {
		this->points = new Point[numPoints];
		for (int i = 0; i < numPoints; ++i) {
			this->points[i] = points[i];
		}
	}
	Figure(const Figure& other) : numPoints(other.numPoints) {
		points = new Point[numPoints];
		for (int i = 0; i < numPoints; ++i) {
			points[i] = other.points[i];
		}
	}
	Figure& operator= (const Figure& other) {
		if (this != &other) {
			delete[] points;
			numPoints = other.numPoints;
			points = new Point[numPoints];
			for (int i = 0; i < numPoints; ++i) {
				points[i] = other.points[i];
			}
		}
		return *this;
	}
	virtual ~Figure() {
		delete[] points;
	}
	virtual double area() const = 0;
	int getNumPoints() const {
		return numPoints;
	}
	Point getPoint(int index) const {
		if (index < 0 || index >= numPoints) {
			throw out_of_range("Index out of range");
		}
		return points[index];
	}
	void setPoint(int index, const Point& point) {
		if (index < 0 || index >= numPoints) {
			throw out_of_range("Index out of range");
		}
		points[index] = point;
	}
};