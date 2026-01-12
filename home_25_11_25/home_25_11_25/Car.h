#pragma once
#include "GroundVeh.h"

class Car : public GroundVeh
{
	protected:
	string Brand;
	string Model;
	bool hasSunroof;
	string interiorMaterial;
	int trunkCapacity;
	string infotainmentSystem;
public:
	Car() : Brand(""), Model(""), hasSunroof(false), interiorMaterial(""), trunkCapacity(0), infotainmentSystem("") {}
	Car(const string& t, int y, int ms, double w, int c, int wc, int hp, int dc, const string& tt, const string& ft, const string& ct, const string& br, const string& mo, bool hs, const string& im, int tc, const string& is)
		: GroundVeh(t, y, ms, w, c, wc, hp, dc, tt, ft, ct),
		Brand(br), Model(mo), hasSunroof(hs), interiorMaterial(im), trunkCapacity(tc), infotainmentSystem(is) {
	}
	void setBrand(const string& b) { Brand = b; }
	void setModel(const string& m) { Model = m; }
	void setHasSunroof(bool hs) { hasSunroof = hs; }
	void setInteriorMaterial(const string& im) { interiorMaterial = im; }
	void setTrunkCapacity(int tc) { trunkCapacity = tc; }
	void setInfotainmentSystem(const string& is) { infotainmentSystem = is; }
	void Print() override
	{
		GroundVeh::Print();
		cout << "Brand: " << Brand << endl;
		cout << "Model: " << Model << endl;
		cout << "Has Sunroof: " << (hasSunroof ? "Yes" : "No") << endl;
		cout << "Interior Material: " << interiorMaterial << endl;
		cout << "Trunk Capacity: " << trunkCapacity << " liters" << endl;
		cout << "Infotainment System: " << infotainmentSystem << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		int wc, int hp, int dc, string tt, string ft, string ct,
		string br, string mo, bool hs, string im, int tc, string is)
	{
		GroundVeh::Init(t, y, ms, w, c,
			wc, hp, dc, tt, ft, ct);
		Brand = br;
		Model = mo;
		hasSunroof = hs;
		interiorMaterial = im;
		trunkCapacity = tc;
		infotainmentSystem = is;
	}
};