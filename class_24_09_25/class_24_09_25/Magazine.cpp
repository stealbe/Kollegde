#include "Magazine.h"

Magazine::Magazine()
{
	year = 0;
	count++;
}

Magazine::Magazine(string _name, string _descript, string _tell, string _email, int _year)
{
	name = _name;
	descript = _descript;
	tell = _tell;
	email = _email;
	year = _year;
	count++;
}

void Magazine::Input()
{
	char buff[100];
	cin.getline(buff, 100);
}

void Magazine::Print()
{
	cout << name << "\t" << descript << "\t" << tell << "\t" << email << "\t" << year << endl;
}

void Magazine::SetName(string n)
{
	name = n;
}

void Magazine::SetDescription(string n)
{
	descript = n;
}

void Magazine::SetTell(string n)
{
	tell = n;
}

void Magazine::SetEmail(string n)
{
	email = n;
}

void Magazine::SetYear(int y)
{
	year = y;
}

string Magazine::GetName()
{
	return name;
}

string Magazine::GetDescription()
{
	return descript;
}

string Magazine::GetTell()
{
	return tell;
}

string Magazine::GetEmail()
{
	return email;
}

int Magazine::GetYear()
{
	return year;
}

int Magazine::Count()
{
	return count;
}

int Magazine::count = 0;