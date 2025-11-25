#pragma once
#include "WaterVeh.h"

class FuelCargo : public WaterVeh
{
	protected:
	double fuelCapacity;
	string fuelType;
	int pumpCount;
	double maxDischargeRate;
	bool hasDoubleHull;
	string cargoHandlingSystem;
public:
	FuelCargo() : fuelCapacity(0.0), fuelType(""), pumpCount(0), maxDischargeRate(0.0), hasDoubleHull(false), cargoHandlingSystem("") {}
	FuelCargo(const string& t, int y, int ms, double w, int c,
		double d, double disp, const string& hm, int ec, const string& pt,
		double fc, const string& ft, int pc, double mdr, bool hdh, const string& chs)
		: WaterVeh(t, y, ms, w, c,
			d, disp, hm, ec, pt),
		fuelCapacity(fc), fuelType(ft), pumpCount(pc), maxDischargeRate(mdr), hasDoubleHull(hdh), cargoHandlingSystem(chs) {
	}
	void setFuelCapacity(double fc) { fuelCapacity = fc; }
	void setFuelType(const string& ft) { fuelType = ft; }
	void setPumpCount(int pc) { pumpCount = pc; }
	void setMaxDischargeRate(double mdr) { maxDischargeRate = mdr; }
	void setHasDoubleHull(bool hdh) { hasDoubleHull = hdh; }
	void setCargoHandlingSystem(const string& chs) { cargoHandlingSystem = chs; }
	void Print() override
	{
		WaterVeh::Print();
		cout << "Fuel Capacity: " << fuelCapacity << " tons" << endl;
		cout << "Fuel Type: " << fuelType << endl;
		cout << "Pump Count: " << pumpCount << endl;
		cout << "Max Discharge Rate: " << maxDischargeRate << " tons/hour" << endl;
		cout << "Has Double Hull: " << (hasDoubleHull ? "Yes" : "No") << endl;
		cout << "Cargo Handling System: " << cargoHandlingSystem << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double d, double disp, string hm, int ec, string pt,
		double fc, string ft, int pc, double mdr, bool hdh, string chs)
	{
		WaterVeh::Init(t, y, ms, w, c,
			d, disp, hm, ec, pt);
		fuelCapacity = fc;
		fuelType = ft;
		pumpCount = pc;
		maxDischargeRate = mdr;
		hasDoubleHull = hdh;
		cargoHandlingSystem = chs;
	}
};