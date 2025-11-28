#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;

class Manager : public Employee
{
	double sallary;
public:
	Manager() : sallary(0.0) {}
	Manager(string p, string n, int a, double s) : Employee(p, n, a), sallary(s) {}
	void Init(string p, string n, int a, double s, double sallary)
	{
		Employee::Init(p, n, a);
		sallary = s;
	}
	void Print()
	{
		Employee::Print();
		cout << "Sallary: " << sallary << endl;
	}
	double GetSallary() { return sallary; }
};