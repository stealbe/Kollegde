#pragma once
#include "FlyVeh.h"
#include <iostream>
using namespace std;

class Plain : public FlyVeh
{
	protected:
	string airline;
	int flightRange;
	int seatingCapacity;
	bool hasInFlightEntertainment;
	string engineType;
	double fuelCapacity;
public:
	Plain() : airline(""), flightRange(0), seatingCapacity(0), hasInFlightEntertainment(false), engineType(""), fuelCapacity(0.0) {}
	Plain(const string& t, int y, int ms, double w, int c, double ws, double ma, double r, int ec, const string& at, const string& al, int fr, int sc, bool hie, const string& et, double fc)
		: FlyVeh(t, y, ms, w, c, ws, ma, r, ec, at),
		airline(al), flightRange(fr), seatingCapacity(sc), hasInFlightEntertainment(hie), engineType(et), fuelCapacity(fc) {
	}
	void setAirline(const string& al) { airline = al; }
	void setFlightRange(int fr) { flightRange = fr; }
	void setSeatingCapacity(int sc) { seatingCapacity = sc; }
	void setHasInFlightEntertainment(bool hie) { hasInFlightEntertainment = hie; }
	void setEngineType(const string& et) { engineType = et; }
	void setFuelCapacity(double fc) { fuelCapacity = fc; }
	void Print() override
	{
		FlyVeh::Print();
		cout << "Airline: " << airline << endl;
		cout << "Flight Range: " << flightRange << " km" << endl;
		cout << "Seating Capacity: " << seatingCapacity << endl;
		cout << "Has In-Flight Entertainment: " << (hasInFlightEntertainment ? "Yes" : "No") << endl;
		cout << "Engine Type: " << engineType << endl;
		cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double ws, double ma, double r, int ec, string at,
		string al, int fr, int sc, bool hie, string et, double fc)
	{
		FlyVeh::Init(t, y, ms, w, c,
			ws, ma, r, ec, at);
		airline = al;
		flightRange = fr;
		seatingCapacity = sc;
		hasInFlightEntertainment = hie;
		engineType = et;
		fuelCapacity = fc;
	}
};