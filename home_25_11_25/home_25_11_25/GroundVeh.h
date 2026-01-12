#pragma once
#include "Vehicle.h"

class GroundVeh : public Vehicle
{
protected:
	int WheelCount;
	int HorsePower;
	int DoorCount;
	string TransmissionType;
	string FuelType;
	string chassisType;
public:
	GroundVeh() : WheelCount(0), HorsePower(0), DoorCount(0), TransmissionType(""), FuelType(""), chassisType("") {}
	GroundVeh(const string& t, int y, int ms, double w, int c, int wc, int hp, int dc, const string& tt, const string& ft, const string& ct) 
		: Vehicle(t, y, ms, w, c), WheelCount(wc), HorsePower(hp), DoorCount(dc), TransmissionType(tt), FuelType(ft), chassisType(ct) {
	}
	void setWheelCount(int wc) { WheelCount = wc; }
	void setHorsePower(int hp) { HorsePower = hp; }
	void setDoorCount(int dc) { DoorCount = dc; }
	void setTransmissionType(const string& tt) { TransmissionType = tt; }
	void setFuelType(const string& ft) { FuelType = ft; }
	void setChassisType(const string& ct) { chassisType = ct; }
	void Print() override
	{
		Vehicle::Print();
		cout << "Wheel Count: " << WheelCount << endl;
		cout << "Horse Power: " << HorsePower << " hp" << endl;
		cout << "Door Count: " << DoorCount << endl;
		cout << "Transmission Type: " << TransmissionType << endl;
		cout << "Fuel Type: " << FuelType << endl;
		cout << "Chassis Type: " << chassisType << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		int wc, int hp, int dc, string tt, string ft, string ct)
	{
		Vehicle::Init(t, y, ms, w, c);
		WheelCount = wc;
		HorsePower = hp;
		DoorCount = dc;
		TransmissionType = tt;
		FuelType = ft;
		chassisType = ct;
	}
};