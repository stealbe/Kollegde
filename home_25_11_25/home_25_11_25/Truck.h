#pragma once
#include "GroundVeh.h"

class Truck : public GroundVeh
{
	protected:
	double cargoCapacity;
	int axleCount;
	string truckType;
	bool hasTrailer;
	string bedType;
	string towingCapacity;
public:
	Truck() : cargoCapacity(0.0), axleCount(0), truckType(""), hasTrailer(false), bedType(""), towingCapacity("") {}
	Truck(const string& t, int y, int ms, double w, int c, int wc, int hp, int dc, const string& tt, const string& ft, const string& ct, double cc, int ac, const string& trt, bool ht, const string& bt, const string& tc)
		: GroundVeh(t, y, ms, w, c, wc, hp, dc, tt, ft, ct),
		cargoCapacity(cc), axleCount(ac), truckType(trt), hasTrailer(ht), bedType(bt), towingCapacity(tc) {
	}
	void setCargoCapacity(double cc) { cargoCapacity = cc; }
	void setAxleCount(int ac) { axleCount = ac; }
	void setTruckType(const string& tt) { truckType = tt; }
	void setHasTrailer(bool ht) { hasTrailer = ht; }
	void setBedType(const string& bt) { bedType = bt; }
	void setTowingCapacity(const string& tc) { towingCapacity = tc; }
	void Print() override
	{
		GroundVeh::Print();
		cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
		cout << "Axle Count: " << axleCount << endl;
		cout << "Truck Type: " << truckType << endl;
		cout << "Has Trailer: " << (hasTrailer ? "Yes" : "No") << endl;
		cout << "Bed Type: " << bedType << endl;
		cout << "Towing Capacity: " << towingCapacity << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		int wc, int hp, int dc, string tt, string ft, string ct,
		double cc, int ac, string trt, bool ht, string bt, string tc)
	{
		GroundVeh::Init(t, y, ms, w, c,
			wc, hp, dc, tt, ft, ct);
		cargoCapacity = cc;
		axleCount = ac;
		truckType = trt;
		hasTrailer = ht;
		bedType = bt;
		towingCapacity = tc;
	}
};