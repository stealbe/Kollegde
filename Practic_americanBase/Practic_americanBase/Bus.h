#pragma once
#include "Vehicle.h"
#include "Human.h"
#include "Base.h"

class Bus : public Vehicle {
	protected:
	int passengerCapacity;
	int currentPassengers;
	friend istream& operator>>(istream& in, Bus& bus)
	{
		cout << "Enter passenger capacity: ";
		in >> bus.passengerCapacity;
		Vehicle temp;
		in >> temp;
		bus.fuel = temp.getPetrolAmount();
		bus.fuelCapacity = temp.getTankVolume();
		bus.fuelConsumption = temp.getFuelConsumption();
		return in;
	}
public:
	Bus() : Vehicle(), passengerCapacity(0), currentPassengers(0) {}
	Bus(double isActive, Human* driver, double fuelCapacity, int passengerCapacity)
		: Vehicle(isActive, driver, 0, 0, fuelCapacity), passengerCapacity(passengerCapacity), currentPassengers(0) {
	}
	Bus(Human* driver, double fuel, double fuelConsumption, double fuelCapacity, int passengerCapacity)
		: Vehicle(true, driver, fuel, fuelConsumption, fuelCapacity), passengerCapacity(passengerCapacity), currentPassengers(0) {
	}
	Bus(double petrol_amount, double tank_volume, int passengerCapacity)
		: Vehicle(petrol_amount, tank_volume), passengerCapacity(passengerCapacity), currentPassengers(0) {
	}
	Bus(double tank_volume, int passengerCapacity)
		: Vehicle(tank_volume), passengerCapacity(passengerCapacity), currentPassengers(0) {
	}
	Bus(Human* driver, bool isActive, double fuelCapacity, int passengerCapacity)
		: Vehicle(driver, isActive, fuelCapacity), passengerCapacity(passengerCapacity), currentPassengers(0) {
	}
	bool boardPassengers(int number) {
		if (number > 0 && (currentPassengers + number) <= passengerCapacity) {
			currentPassengers += number;
			return true;
		}
		return false;
	}
	bool disembarkPassengers(int number) {
		if (number > 0 && number <= currentPassengers) {
			currentPassengers -= number;
			return true;
		}
		return false;
	}
	int getCurrentPassengers() const {
		return currentPassengers;
	}
	int getPassengerCapacity() {
		return passengerCapacity;
	}
	void arrive() override
	{
		if (driver == nullptr) throw "Bus has no driver.";
		if (isActive) throw "Bus is already on the base.";
		if (fuel <= 0 || fuelConsumption / 100 > fuel) throw "Bus has no enough fuel.";
		isActive = true;
		Base::setVehicles(Base::getVehicles() + 1);
		Base::setPeople(Base::getPeople() + currentPassengers + 1);
		currentPassengers = 0;
	}
	bool leave() override
	{
		if (driver == nullptr || Base::getPeople() <= 0 || !isActive || Base::getVehicles() <= 0) return 0;
		if (fuel < fuelCapacity && Base::getPetrol() > 0)
		{
			if (fuelCapacity - fuel <= Base::getPetrol())
			{
				Base::setPetrol(Base::getPetrol() - (fuelCapacity - fuel));
				fuel = fuelCapacity;
			}
			else return 0;
		}
		if (currentPassengers < passengerCapacity && Base::getPeople() > 0)
		{
			if (passengerCapacity - currentPassengers + 1 <= Base::getPeople())
			{
				Base::setPeople(Base::getPeople() - (passengerCapacity - currentPassengers + 1));
				currentPassengers = passengerCapacity;
			}
			else
			{
				currentPassengers += Base::getPeople() - 1;
				Base::setPeople(0);
			}
		}
		if (fuel <= 0 || fuelConsumption / 100 > fuel) return 0;
		isActive = false;
		Base::setVehicles(Base::getVehicles() - 1);
		return 1;
	}

};