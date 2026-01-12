#include <iostream>
using namespace std;

class Human
{
protected:
	string name;
	int age;
public:
	Human() { name = ""; age = 0; }
	Human(string n, int a) { name = n; age = a; };
	void Print()
	{
		cout << "Name: " << name << "\n" << "Age: " << age << endl;
	}

};

class Student: public Human
{
	int year;
	double Average;

public:
	Student() { name = ""; age = 0; year = 0; Average = 0; }
	Student(string n, int a, int y, double av)
	{
		name = n;
		age = a;
		year = y;
		Average = av;
	}

};

int main() {

    return 0;
}