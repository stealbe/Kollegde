#include <iostream>
using namespace std;

class Transport
{
protected:
	string name;
	int year;
	int mSpeed;
	double tWeight;
	int humanCapacity;
public:
	Transport()
	{
		name = "";
		year = 0;
		mSpeed = 0;
		tWeight = 0.0;
		humanCapacity = 0;
	}
	Transport(string name, int year, int mSpeed, double tWeight, int humanCapacity)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
	}
	void SetName(string name) { this->name = name; }
	void SetYear(int year) { this->year = year; }
	void SetMSpeed(int mSpeed) { this->mSpeed = mSpeed; }
	void SetTWeight(double tWeight) { this->tWeight = tWeight; }
	void SetHumanCaparity(int humanCapacity) { this->humanCapacity = humanCapacity; }

	string GetName() { return this->name; }
	int GetYear() { return this->year; }
	int GetMSpeed() { return this->mSpeed; }
	double GetTWeight() { return this->tWeight; }
	int GetHumanCapacity() { return this->humanCapacity; }
	void Print() {
		cout << "Name: " << this->name << "\tYear: " << this->year << " y" << "\tMax speed: " << this->mSpeed << " km/h" << "\tWeight:" << this->tWeight << " T" << "\tCapacity: " << this->humanCapacity << " human's" << endl;
	}
};

class Cargo : public Transport
{
	double dWheels;
	int vEngine;
public:
	Cargo(string name, int year, int mSpeed, double tWeight, int humanCapacity, double dWheels, int vEngine)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
		this->dWheels = dWheels;
		this->vEngine = vEngine;
	}
	void SetdWheels(double dWheels) { this->dWheels = dWheels; }
	void SetVEngine(int vEngine) { this->vEngine = vEngine; }

	double GetdWheels() { return this->dWheels; }
	int GetVEngine() { return this->vEngine; }
	void Print()
	{
		Transport::Print();
		cout << "Weels D: " << dWheels << " sm" << "\tEngine V: " << vEngine << endl;
	}
};

class Plane : public Transport
{
	double mWingsScope;
	int vEngine;
	Plane(string name, int year, int mSpeed, double tWeight, int humanCapacity, double mWingsScope, int vEngine)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
		this->mWingsScope = mWingsScope;
		this->vEngine = vEngine;
	}
	void SetMWingScope(double mWingsScope) { this->mWingsScope = mWingsScope; }
	void SetVEngine(int vEngine) { this->vEngine = vEngine; }

	double GetMWingScope() { return this->mWingsScope; }
	int GetVEngine() { return this->vEngine; }
	void Print()
	{
		Transport::Print();
		cout << "Wings scope: " << mWingsScope << " m" << "\tEngine V: " << vEngine << endl;
	}
};

class Boat : public Transport
{
	double mLong;
	int screwCount;
	double mWaterlineHi;
public:
	Boat(string name, int year, int mSpeed, double tWeight, int humanCapacity, double mLong, int screwCount, double mWaterlineHi)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
		this->mLong = mLong;
		this->screwCount = screwCount;
		this->mWaterlineHi = mWaterlineHi;
	}
	void SetMLong(double mLong) { this->mLong = mLong; }
	void SetScrewCount(int screwCount) { this->screwCount = screwCount; }
	void SetMWaterlineHi(double mWaterlineHi) { this->mWaterlineHi = mWaterlineHi; }

	double GetMLong() { return this->mLong; }
	int GetScrewCount() { return this->screwCount; }
	double GetMWaterlineHi() { return this->mWaterlineHi; }
	void Print()
	{
		Transport::Print();
		cout << "Long: " << mLong << " m" << "\tScrews count: " << screwCount << "\tWater line height" << mWaterlineHi << " m" << endl;
	}
};

class Car : public Transport
{
	string fuelType;
	string gearboxType;
	string carcaseType;
public:
	Car(string name, int year, int mSpeed, double tWeight, int humanCapacity, string fueType, string gearboxType, string carcaseType)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
		this->fuelType = fueType;
		this->gearboxType = gearboxType;
		this->carcaseType = carcaseType;
	}
	void SetFuelType(string fuelType) { this->fuelType = fuelType; }
	void SetGearboxType(string gearboxType) { this->gearboxType = gearboxType; }
	void SetCarcaseType(string carcaseType) { this->carcaseType = carcaseType; }

	string GetFuelType() { return this->fuelType; }
	string GetGearboxType() { return this->gearboxType; }
	string GetCarcaseType() { return this->carcaseType; }
	void Print()
	{
		Transport::Print();
		cout << "Fuel type: " << fuelType << "\tGearbox type: " << gearboxType << "\tCarcase type: " << carcaseType << endl;
	}
};

class Bike : public Transport
{
	string chasissType;
	double dWheels;
public:
	Bike(string name, int year, int mSpeed, double tWeight, int humanCapacity, string chasissType, double dWheels)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
		this->chasissType = chasissType;
		this->dWheels = dWheels;
	}
	void SetChasissType(string chasissType) { this->chasissType = chasissType; }
	void SetDWheels(double dWheels) { this->dWheels = dWheels; }

	string GetChasissType() { return this->chasissType; }
	double GetDWheels() { return this->dWheels; }
	void Print()
	{
		Transport::Print();
		cout << "Chasiss type: " << chasissType << "\tWheels D: " << dWheels << " sm" << endl;
	}
};

class Tank : public Transport
{
	string tankType;
	string fuelType;
	bool fireAvalible;
public:
	Tank(string name, int year, int mSpeed, double tWeight, int humanCapacity, string tankType, string fuelType, bool fireAvalible)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->humanCapacity = humanCapacity;
		this->tankType = tankType;
		this->fuelType = fuelType;
		this->fireAvalible = fireAvalible;
	}
	void SetTankType(string tankType) { this->tankType = tankType; }
	void SetFuelType(string fuelType) { this->fuelType = fuelType; }
	void SetFireAvalible(bool fireAvalible) { this->fireAvalible = fireAvalible; }

	string GetTankType() { return this->tankType; }
	string GetFuelType() { return this->fuelType; }
	bool GetFireAvalible() { return this->fireAvalible; }
	void Print()
	{
		Transport::Print();
		cout << "Tank type: " << tankType << "\tFuel type: " << fuelType << "\tFire: " << (fireAvalible ? "avalible" : "not avalible") << endl;
	}
};

int main() {

    return 0;
}