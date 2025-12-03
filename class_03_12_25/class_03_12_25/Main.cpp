#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "RHome.h"
#include "Square.h"
#include "Paral.h"

using namespace std;

int main()
{
    Figure* figure = nullptr;

    int choice = 0;

    cout << "1. Square circle" << endl;
    cout << "2. Square rectangle" << endl;
    cout << "3. Square triangle" << endl;
	cout << "4. Square rhome" << endl;
	cout << "5. Square square" << endl;
	cout << "6. Square parallelogram" << endl;
    cout << "Make your choice: ";

    cin >> choice;

    switch (choice)
    {
        case 1:
            figure = new Circle;
            break;
        case 2:
            figure = new Rectangle;
            break;
        case 3: 
            figure = new Triangle;
            break;
		case 4:
			figure = new RHome;
			break;
		case 5:
			figure = new Square;
			break;
		case 6:
			figure = new Paral;
            break;
        default:
            cout << "Invalid choice!" << endl;
			break;
    }

	figure->SetDimension(5.0, 10.0);
    if (figure != nullptr) figure->ShowArea();

	IPrint* ptr = new Dog();
	ptr->PrintConsole();
    delete ptr;
	ptr = new Square();

    return 0;
}