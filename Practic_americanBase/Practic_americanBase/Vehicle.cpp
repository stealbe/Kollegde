#include "Base.h"
#include "Vehicle.h"

void Vehicle::arrive()
{
	if (driver == nullptr) throw "Vehicle has no driver.";
	if (fuel <= 0 || fuelConsumption / 100 > fuel) throw "Vehicle has no enought fuel.";
	if (isActive) throw "Vehicle is already on the base.";
	isActive = true;
	Base::setVehicles(Base::getVehicles() + 1);
	Base::setPeople(Base::getPeople() + 1);
	fuel -= fuelConsumption / 100;
	isActive = true;
}

bool Vehicle::leave()
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

	if (fuel <= 0 || fuelConsumption / 100 > fuel) return 0;
	Base::setVehicles(Base::getVehicles() - 1);
	Base::setPeople(Base::getPeople() - 1);
	fuel -= fuelConsumption / 100;
	isActive = false;
	return 1;
}