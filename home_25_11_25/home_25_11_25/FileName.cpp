#include <iostream>
using namespace std;

#include "Vehicle.h"

#include "Car.h"
#include "Truck.h"
#include "Train.h"

#include "Boat.h"
#include "MotorShip.h"
#include "FuelCargo.h"

#include "Plain.h"
#include "Heli.h"
#include "Airship.h"

int main() {
	Vehicle* veh = nullptr;
	int choice = 0;
	cout << "Select vehicle type to create:\n";
	cout << "1. Car\n2. Truck\n3. Train\n4. Boat\n5. MotorShip\n6. FuelCargo\n7. Plain\n8. Heli\n9. Airship\n";
	cin >> choice;
	switch (choice) {
	case 1:
		veh = new Car("Sedan", 2020, 220, 1.5, 5, 4, 150, 4, "Automatic", "Gasoline", "Unibody", "Toyota", "Camry", true, "Leather", 500, "Touchscreen");
		break;
	case 2:
		veh = new Truck("Pickup", 2019, 180, 2.5, 3, 4, 200, 2, "Manual", "Diesel", "Body-on-frame", 3.0, 2, "Flatbed", true, "Open", "3500 lbs");
		break;
	case 3:
		veh = new Train("Freight", 2015, 120, 2000.0, 100, 8, 4000, 1435, "Diesel", "Freight", "Cargo", "Freight", 50, 1.435, "Union Pacific", 200.0, 10000.0);
		break;
	case 4:
		veh = new Boat("Yacht", 2018, 80, 50.0, 20, 3.0, 500.0, "Fiberglass", 2, "Inboard", "Motorboat", 30.0, 8.0, 3.0, 15, "V8 Engine");
		break;
	case 5:
		veh = new MotorShip("Cruise", 2010, 40, 30000.0, 2000, 10.0, 20000.0, "Steel", 4, "Diesel-Electric", 40000.0, 22.0, 15, "Advanced GPS", true, "Luxury");
		break;
	case 6:
		veh = new FuelCargo("Tanker", 2012, 35, 50000.0, 1500, 12.0, 40000.0, "Steel", 6, "Crude Oil", 30000.0, "Crude Oil", 8, 5000.0, true, "Automated");
		break;
	case 7:
		veh = new Plain("Commercial", 2016, 900, 80000.0, 180, 35.0, 12000.0, 15000.0, 2, "Jet", "Delta Airlines", 6500, 180, true, "Turbofan", 26000.0);
		break;
	case 8:
		veh = new Heli("Rescue", 2014, 250, 5000.0, 6, 15.0, 6000.0, 800.0, 1, "Rotorcraft", "Main Rotor", 4, 4500.0, "Skid", true, "Advanced");
		break;
	case 9:
		veh = new Airship("Surveillance", 2011, 100, 2000.0, 10, 50.0, 3000.0, 500.0, 1, "Lighter-than-air", 15000.0, "Helium", 200.0, 70.0, 20.0, true);
		break;
	default:
		cout << "Invalid choice." << endl;
		return 1;
	};
	veh->Print();
}