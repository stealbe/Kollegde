#pragma once
#include "Vehicle.h"

class FlyVeh : public Vehicle
{
	protected:
	double wingSpan;
	double maxAltitude;
	double range;
	int engineCount;
	string aircraftType;
public:
	FlyVeh() : wingSpan(0.0), maxAltitude(0.0), range(0.0), engineCount(0), aircraftType("") {}
	FlyVeh(const string& t, int y, int ms, double w, int c, double ws, double ma, double r, int ec, const string& at)
		: Vehicle(t, y, ms, w, c), wingSpan(ws), maxAltitude(ma), range(r), engineCount(ec), aircraftType(at) {
	}
	void setWingSpan(double ws) { wingSpan = ws; }
	void setMaxAltitude(double ma) { maxAltitude = ma; }
	void setRange(double r) { range = r; }
	void setEngineCount(int ec) { engineCount = ec; }
	void setAircraftType(const string& at) { aircraftType = at; }
	void Print() override
	{
		Vehicle::Print();
		cout << "Wing Span: " << wingSpan << " meters" << endl;
		cout << "Max Altitude: " << maxAltitude << " meters" << endl;
		cout << "Range: " << range << " km" << endl;
		cout << "Engine Count: " << engineCount << endl;
		cout << "Aircraft Type: " << aircraftType << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double ws, double ma, double r, int ec, string at)
	{
		Vehicle::Init(t, y, ms, w, c);
		wingSpan = ws;
		maxAltitude = ma;
		range = r;
		engineCount = ec;
		aircraftType = at;
	}
};