#pragma once
#include <iostream>
using namespace std;

class Employee
{
protected:
	string post;
	string name;
	int age;
public:
	Employee() : post(""), name(""), age(0) {}
	Employee(string p, string n, int a) : post(p), name(n), age(a) {}
	virtual void Init(string p, string n, int a)
	{
		post = p;
		name = n;
		age = a;
	}
	virtual void Print() { cout << "Post: " << post << "\tName: " << name << "\tAge: " << age << endl; }
	virtual double GetSallary() { return 0.0; }
};