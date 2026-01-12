#include<iostream>
#include "Point.h"
using namespace std;

int main()
{
	Point a(1, 2);
	Point c = a++;
	a.Print();
	c.Print();
	
}