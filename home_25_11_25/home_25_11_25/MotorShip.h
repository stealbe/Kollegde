#pragma once
#include "WaterVeh.h"

class MotorShip : public WaterVeh
{
	protected:
	double enginePower;
	double cruisingSpeed;
	int deckCount;
	string navigationSystem;
	bool hasHelipad;
	string shipClass;
public:
	MotorShip() : enginePower(0.0), cruisingSpeed(0.0), deckCount(0), navigationSystem(""), hasHelipad(false), shipClass("") {}
	MotorShip(const string& t, int y, int ms, double w, int c, double d, double disp, const string& hm, int ec, const string& pt, 
		double ep, double cs, int dc, const string& ns, bool hh, const string& sc)
		: WaterVeh(t, y, ms, w, c,
			d, disp, hm, ec, pt),
		enginePower(ep), cruisingSpeed(cs), deckCount(dc), navigationSystem(ns), hasHelipad(hh), shipClass(sc) {
	}
	void setEnginePower(double ep) { enginePower = ep; }
	void setCruisingSpeed(double cs) { cruisingSpeed = cs; }
	void setDeckCount(int dc) { deckCount = dc; }
	void setNavigationSystem(const string& ns) { navigationSystem = ns; }
	void setHasHelipad(bool hh) { hasHelipad = hh; }
	void setShipClass(const string& sc) { shipClass = sc; }
	void Print() override
	{
		WaterVeh::Print();
		cout << "Engine Power: " << enginePower << " kW" << endl;
		cout << "Cruising Speed: " << cruisingSpeed << " knots" << endl;
		cout << "Deck Count: " << deckCount << endl;
		cout << "Navigation System: " << navigationSystem << endl;
		cout << "Has Helipad: " << (hasHelipad ? "Yes" : "No") << endl;
		cout << "Ship Class: " << shipClass << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double d, double disp, string hm, int ec, string pt,
		double ep, double cs, int dc, string ns, bool hh, string sc)
	{
		WaterVeh::Init(t, y, ms, w, c,
			d, disp, hm, ec, pt);
		enginePower = ep;
		cruisingSpeed = cs;
		deckCount = dc;
		navigationSystem = ns;
		hasHelipad = hh;
		shipClass = sc;
	}
};