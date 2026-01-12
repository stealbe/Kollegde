#include "Reservior.h"
#include <iostream>
using namespace std;

Reservior::Reservior()
{
	name = nullptr;
	width = 0;
	length = 0;
	deph = 0;
}

Reservior::Reservior(char* _name, double _w, double _l, double _d)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	width = _w;
	length = _l;
	deph = _d;
}

Reservior::Reservior(Reservior& obj)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	width = obj.width;
	length = obj.length;
	deph = obj.deph;
}

Reservior::~Reservior()
{
	delete[] name;
}

double Reservior::Capacity() const
{
	return (width * length);
}

double Reservior::Square() const
{
	return (width * length * deph);
}

bool Reservior::Test(const char* type) const
{
	return strcmp(name, type);
}

bool Reservior::Test_square(Reservior& obj) const
{
	return (Square() == obj.Square() ? true : false);
}

void Reservior::Copy(const Reservior& obj)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	width = obj.width;
	length = obj.length;
	deph = obj.deph;
}
