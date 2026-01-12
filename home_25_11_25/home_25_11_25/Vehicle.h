#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	string type;
	int year;
	int maxSpeed;
	double weight;
	int capacity;
public:
	Vehicle() : type(""), year(0), maxSpeed(0), weight(0.0), capacity(0) {}
	Vehicle(const string& t, int y, int ms, double w, int c)
		: type(t), year(y), maxSpeed(ms), weight(w), capacity(c) {
	}
	void setType(const string& t) { type = t; }
	void setYear(int y) { year = y; }
	void setMaxSpeed(int ms) { maxSpeed = ms; }
	void setWeight(double w) { weight = w; }
	void setCapacity(int c) { capacity = c; }
	virtual void Print()
	{
		cout << "Type: " << type << endl;
		cout << "Year: " << year << endl;
		cout << "Max Speed: " << maxSpeed << " km/h" << endl;
		cout << "Weight: " << weight << " tons" << endl;
		cout << "Capacity: " << capacity << " persons" << endl;
	}
	virtual void Init(string t, int y, int ms, double w, int c)
	{
		type = t;
		year = y;
		maxSpeed = ms;
		weight = w;
		capacity = c;
	}
	virtual ~Vehicle() {}
};