#pragma once
#include "FlyVeh.h"
#include <iostream>
using namespace std;

class Airship : public FlyVeh
{
	protected:
	double envelopeVolume;
	string gasType;
	double maxPayload;
	double length;
	double diameter;
	bool hasBallonet;
public:
	Airship() : envelopeVolume(0.0), gasType(""), maxPayload(0.0), length(0.0), diameter(0.0), hasBallonet(false) {}
	Airship(const string& t, int y, int ms, double w, int c, double ws, double ma, double r, int ec, const string& at,
		double ev, const string& gt, double mp, double l, double d, bool hb)
		: FlyVeh(t, y, ms, w, c, ws, ma, r, ec, at),
		envelopeVolume(ev), gasType(gt), maxPayload(mp), length(l), diameter(d), hasBallonet(hb) {
	}
	void setEnvelopeVolume(double ev) { envelopeVolume = ev; }
	void setGasType(const string& gt) { gasType = gt; }
	void setMaxPayload(double mp) { maxPayload = mp; }
	void setLength(double l) { length = l; }
	void setDiameter(double d) { diameter = d; }
	void setHasBallonet(bool hb) { hasBallonet = hb; }
	void Print() override
	{
		FlyVeh::Print();
		cout << "Envelope Volume: " << envelopeVolume << " cubic meters" << endl;
		cout << "Gas Type: " << gasType << endl;
		cout << "Max Payload: " << maxPayload << " tons" << endl;
		cout << "Length: " << length << " meters" << endl;
		cout << "Diameter: " << diameter << " meters" << endl;
		cout << "Has Ballonet: " << (hasBallonet ? "Yes" : "No") << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		double ws, double ma, double r, int ec, string at,
		double ev, string gt, double mp, double l, double d, bool hb)
	{
		FlyVeh::Init(t, y, ms, w, c,
			ws, ma, r, ec, at);
		envelopeVolume = ev;
		gasType = gt;
		maxPayload = mp;
		length = l;
		diameter = d;
		hasBallonet = hb;
	}
};