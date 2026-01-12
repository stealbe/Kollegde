#include "Animal.h"
#include "Eleph.h"
#include "Giraffe.h"
#include "Rabbit.h"
#include "Woolf.h"
#include "Eagle.h"
#include "Shark.h"

#include <iostream>
using namespace std;

int main() {
	Animal* animal = nullptr;
	int menu = 0;
	cout << "Select an animal to see its behavior:" << endl;
	cout << "1. Elephant" << endl;
	cout << "2. Giraffe" << endl;
	cout << "3. Rabbit" << endl;
	cout << "4. Woolf" << endl;
	cout << "5. Eagle" << endl;
	cout << "6. Shark" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		animal = new Eleph();
		break;
	case 2:
		animal = new Giraffe();
		break;
	case 3:
		animal = new Rabbit();
		break;
	case 4:
		animal = new Woolf();
		break;
	case 5:
		animal = new Eagle();
		break;
	case 6:
		animal = new Shark();
		break;
	default:
		cout << "Invalid selection." << endl;
		return 1;
	}
	animal->move();
	animal->eat();
	animal->move(10, 5, 0);
	delete animal;
	return 0;
}