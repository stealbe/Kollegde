#pragma once
#include "Vehicle.h"

class WaterVeh : public Vehicle
{
protected:
	double draft;
	double displacement;
	string hullMaterial;
	int engineCount;
	string propulsionType;
public:
	WaterVeh() : draft(0.0), displacement(0.0), hullMaterial(""), engineCount(0), propulsionType("") {}
	WaterVeh(const string& t, int y, int ms, double w, int c, double d, double disp, const string& hm, int ec, const string& pt)
		: Vehicle(t, y, ms, w, c), draft(d), displacement(disp), hullMaterial(hm), engineCount(ec), propulsionType(pt) {
	}
	void setDraft(double d) { draft = d; }
	void setDisplacement(double disp) { displacement = disp; }
	void setHullMaterial(const string& hm) { hullMaterial = hm; }
	void setEngineCount(int ec) { engineCount = ec; }
	void setPropulsionType(const string& pt) { propulsionType = pt; }
	void Print()
	{
		Vehicle::Print();
		cout << "Draft: " << draft << " meters" << endl;
		cout << "Displacement: " << displacement << " tons" << endl;
		cout << "Hull Material: " << hullMaterial << endl;
		cout << "Engine Count: " << engineCount << endl;
		cout << "Propulsion Type: " << propulsionType << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double d, double disp, string hm, int ec, string pt)
	{
		Vehicle::Init(t, y, ms, w, c);
		draft = d;
		displacement = disp;
		hullMaterial = hm;
		engineCount = ec;
		propulsionType = pt;
	}
};