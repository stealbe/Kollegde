#include "Base.h"
#include <iostream>
using namespace std;

#include "Vehicle.h"
#include "Human.h"
#include "Truck.h"
#include "Bus.h"

int main()
{
	Base base(
		vector<Human*>{
			new Human("John", "Doe", 30),
			new Human("Jane", "Smith", 28),
			new Human("Mike", "Johnson", 35),
			new Human("Emily", "Davis", 25),
			new Human("Chris", "Brown", 40),
			new Human("Anna", "Wilson", 32),
			new Human("David", "Taylor", 29),
			new Human("Laura", "Anderson", 27),
			new Human("James", "Thomas", 33),
			new Human("Olivia", "Jackson", 26),
			new Human("Daniel", "White", 31),
			new Human("Sophia", "Harris", 24)
	}, vector<Vehicle*>{
			new Truck(new Human("Driver1", "Truck", 45), 100, 20.0, 10.0),
			new Bus(new Human("Driver2", "Bus", 38), 80, 15.0, 50.0),
			new Truck(new Human("Driver3", "Truck", 50), 120, 25.0, 15.0),
			new Bus(new Human("Driver4", "Bus", 42), 90, 18.0, 60.0),
			new Truck(new Human("Driver5", "Truck", 37), 110, 22.0, 12.0),
			new Bus(new Human("Driver6", "Bus", 39), 85, 16.0, 55.0),
			new Bus(30.0, 120.0, 40),
			new Truck(50.0, 200.0, 20.0),
			new Bus(new Human("Driver7", "Bus", 41), false, 95.0, 65),
			new Truck(new Human("Driver8", "Truck", 36), false, 130.0, 18.0) 
	}, 1000, 200, 5000.0, 20.0);
	int menu = 0;
	int vehicleMenu = 0;
	int vehicleType = 0;
	Vehicle* temp;
	size_t index = -1;
	int personnelMenu = 0;
	Human* newSolider;
	size_t index = -1;
	do
	{
		cout << "Base Control Menu:\n";
		cout << "1. View Base Status\n";
		cout << "2. Manage Vehicles\n";
		cout << "3. Manage Personnel\n";
		cout << "0. Exit\n";
		switch (menu)
		{
		case 1:
		{
			cout << "Base Status:\n";
			cout << "People on Base: " << Base::getPeople() << "\n";
			cout << "Vehicles on Base: " << Base::getVehicles() << "\n";
			cout << "Petrol on Base: " << Base::getPetrol() << " liters\n";
			cout << "Goods on Base: " << Base::getGoods() << " tons\n";
			break;
		}
		case 2:
		{
			cout << "Manage Vehicles selected.\n";
			
			do
			{
				cout << "Vehicle Management Menu:\n";
				cout << "1. List Vehicles\n";
				cout << "2. Add Vehicle\n";
				cout << "3. Remove Vehicle\n";
				cout << "0. Back to Main Menu\n";
				switch (vehicleMenu)
				{
				case 1:
					cout << "Listing Vehicles...\n";
					base.PrintVehicles();
					break;
				case 2:
					cout << "Adding Vehicle...\n";
					
					
					cout << "Select Vehicle Type to Add:\n";
					cout << "0. Vehicle\n";
					cout << "1. Truck\n";
					cout << "2. Bus\n";
					cin >> vehicleType;
					switch (vehicleType)
					{
					case 0:
						temp = new Vehicle();
						cin >> *temp;
						base.AddVehicle(temp);
						break;
					case 1:
						temp = new Truck();
						cin >> *temp;
						base.AddVehicle(temp);
						break;
					case 2:
						temp = new Bus();
						cin >> *temp;
						base.AddVehicle(temp);
						break;
					default:
						cout << "Invalid vehicle type selected.\n";
						continue;
					}
					break;
				case 3:
					cout << "Removing Vehicle...\n";
					cout << "Enter Vehicle Index to Remove: ";
					cin >> index;
					if (base.RemoveVehicle(index - 1)) {
						cout << "Vehicle removed successfully.\n";
					}
					else {
						cout << "Invalid index. No vehicle removed.\n";
					}
					break;
				default:
					cout << "Returning to Main Menu...\n";
					return 0;
					break;
				}
			} while (true);
			break;
		}
		case 3:
			
			do
			{
				cout << "Personnel Management Menu:\n";
				cout << "1. List Personnel\n";
				cout << "2. Add Personnel\n";
				cout << "3. Remove Personnel\n";
				cout << "0. Back to Main Menu\n";
				cin >> personnelMenu;
				switch (personnelMenu)
				{
				case 1:
					cout << "Listing Personnel...\n";
					base.PrintSoliders();
					break;
				case 2:
					cout << "Adding Personnel...\n";
					newSolider = new Human();
					cin >> *newSolider;
					base.AddSolider(newSolider);
					break;
				case 3:
					cout << "Removing Personnel...\n";

					cout << "Enter Personnel Index to Remove: ";
					cin >> index;
					if (base.RemoveSolider(index - 1)) {
						cout << "Personnel removed successfully.\n";
					}
					else {
						cout << "Invalid index. No personnel removed.\n";
					}
					break;
				default:
					cout << "Returning to Main Menu...\n";
					return 0;
					break;
				}
			} while (true);
				break;
		default:
			cout << "Exiting Base Control...\n";
			return 0;
			break;
			}
	} while (true);
};