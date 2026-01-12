#pragma once
#include "FlyVeh.h"
#include <iostream>
using namespace std;

class Heli : public FlyVeh
{
	protected:
	string rotorType;
	int bladeCount;
	double maxTakeoffWeight;
	string landingGearType;
	bool hasAutopilot;
	string avionicsSuite;
public:
	Heli() : rotorType(""), bladeCount(0), maxTakeoffWeight(0.0), landingGearType(""), hasAutopilot(false), avionicsSuite("") {}
	Heli(const string& t, int y, int ms, double w, int c, double ws, double ma, double r, int ec, const string& at,
		const string& rt, int bc, double mtw, const string& lgt, bool ha, const string& as)
		: FlyVeh(t, y, ms, w, c, ws, ma, r, ec, at),
		rotorType(rt), bladeCount(bc), maxTakeoffWeight(mtw), landingGearType(lgt), hasAutopilot(ha), avionicsSuite(as) {
	}
	void setRotorType(const string& rt) { rotorType = rt; }
	void setBladeCount(int bc) { bladeCount = bc; }
	void setMaxTakeoffWeight(double mtw) { maxTakeoffWeight = mtw; }
	void setLandingGearType(const string& lgt) { landingGearType = lgt; }
	void setHasAutopilot(bool ha) { hasAutopilot = ha; }
	void setAvionicsSuite(const string& as) { avionicsSuite = as; }
	void Print() override
	{
		FlyVeh::Print();
		cout << "Rotor Type: " << rotorType << endl;
		cout << "Blade Count: " << bladeCount << endl;
		cout << "Max Takeoff Weight: " << maxTakeoffWeight << " kg" << endl;
		cout << "Landing Gear Type: " << landingGearType << endl;
		cout << "Has Autopilot: " << (hasAutopilot ? "Yes" : "No") << endl;
		cout << "Avionics Suite: " << avionicsSuite << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double ws, double ma, double r, int ec, string at,
		string rt, int bc, double mtw, string lgt, bool ha, string as)
	{
		FlyVeh::Init(t, y, ms, w, c,
			ws, ma, r, ec, at);
		rotorType = rt;
		bladeCount = bc;
		maxTakeoffWeight = mtw;
		landingGearType = lgt;
		hasAutopilot = ha;
		avionicsSuite = as;
	}
};