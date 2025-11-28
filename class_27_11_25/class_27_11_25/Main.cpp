#include <iostream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "RHome.h"
#include "Paral.h"
#include "Square.h"

using namespace std;

int main()
{
    Figure* figure = nullptr;

    int choice = 0;

    cout << "1. Square circle" << endl;
    cout << "2. Square rectangle" << endl;
    cout << "3. Square triangle" << endl;
    cout << "4. RHom" << endl;
    cout << "5. Square" << endl;
    cout << "6. Paral" << endl;
    cout << "Make your choice: ";

    cin >> choice;

    switch (choice)
    {
        case 1:
            figure = new Circle;
            figure->SetDimension(10.0);
            break;
        case 2:
            figure = new Rectangle;
            figure->SetDimension(5.5, 10.0);
            break;
        case 3: 
            figure = new Triangle;
            figure->SetDimension(5.5, 10.0);
            break;
		case 4:
			figure = new RHome;
			figure->SetDimension(4.0, 5.0);
			break;
		case 5:
			figure = new Square;
			figure->SetDimension(6.0);
			break;
		case 6:
			figure = new Paral;
			figure->SetDimension(4.0, 5.0);
            break;
        default:
            cout << "Invalid choice!" << endl;
			break;
    }

    figure->ShowArea();
	figure->Print();
	figure->ShowLength();
	figure->ShowPerimeter();

    return 0;
}