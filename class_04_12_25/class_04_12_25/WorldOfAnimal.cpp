#include "NorthAmerica.h"
#include "Africa.h"
#include <iostream>
using namespace std;

#include "Bison.h"
#include "Wildebeest.h"
#include "Wolf.h"
#include "Lion.h"

int main()
{
	NorthAmerica na(
		vector<Carnivore*>{ new Wolf(16.0), new Lion(22.0) },
		vector<Herbivore*>{ new Bison(13.0), new Wildebeest(11.0) }
	);
	Africa af(
		vector<Carnivore*>{ new Lion(25.0), new Wolf(19.0) },
		vector<Herbivore*>{ new Wildebeest(12.0), new Bison(15.0) }
	);
	int menu = 0;
	do
	{
		cout << "Menu:" << endl;
		cout << "1. North America Herbivores Eat" << endl;

		cout << "2. North America Carnivores Hunt" << endl;
		cout << "3. Africa Herbivores Eat" << endl;
		cout << "4. Africa Carnivores Hunt" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			na.MealsHerbivores();
			break;
		case 2:
			na.NutritionCarnivores();
			break;
		case 3:
			af.MealsHerbivores();
			break;
		case 4:
			af.NutritionCarnivores();
			break;
		default:
			cout << "Exit;" << endl;
			return 0;
		}
	} while (true);
	return 0;
}