#include<iostream>
#include "Point.h"
using namespace std;

int main()
{
	Point a(1, 2), b(3, 4), c(10, 20);
	cout << Point::Count() << endl;
}