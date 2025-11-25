#pragma once
#include "WaterVeh.h"

class Boat : public WaterVeh
{
	protected:
	string boatType;
	double length;
	double beam;
	double draft;
	int passengerCapacity;
	string engineType;
public:
	Boat() : boatType(""), length(0.0), beam(0.0), draft(0.0), passengerCapacity(0), engineType("") {}
	Boat(const string& t, int y, int ms, double w, int c,
		double d, double disp, const string& hm, int ec, const string& pt,
		const string& bt, double l, double be, double dr, int pc, const string& et)
		: WaterVeh(t, y, ms, w, c,
			d, disp, hm, ec, pt),
		boatType(bt), length(l), beam(be), draft(dr), passengerCapacity(pc), engineType(et) {
	}
	void setBoatType(const string& bt) { boatType = bt; }
	void setLength(double l) { length = l; }
	void setBeam(double b) { beam = b; }
	void setDraft(double d) { draft = d; }
	void setPassengerCapacity(int pc) { passengerCapacity = pc; }
	void setEngineType(const string& et) { engineType = et; }
	void Print() override
	{
		WaterVeh::Print();
		cout << "Boat Type: " << boatType << endl;
		cout << "Length: " << length << " meters" << endl;
		cout << "Beam: " << beam << " meters" << endl;
		cout << "Draft: " << draft << " meters" << endl;
		cout << "Passenger Capacity: " << passengerCapacity << endl;
		cout << "Engine Type: " << engineType << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double d, double disp, string hm, int ec, string pt,
		string bt, double l, double be, double dr, int pc, string et)
	{
		WaterVeh::Init(t, y, ms, w, c,
			d, disp, hm, ec, pt);
		boatType = bt;
		length = l;
		beam = be;
		draft = dr;
		passengerCapacity = pc;
		engineType = et;
	}
};