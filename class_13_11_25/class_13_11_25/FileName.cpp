#include<iostream>
using namespace std;

class Human
{
protected:
	string name;
	int age;
public:
	Human() {}
	Human(string n, int a) { name = n; age = a; }
	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
};

class Student : public Human
{
	/*string name;
	int age;*/
	int year;
	double Average;
public:
	Student() {}
	Student(string n, int a, int y, double Av)
	{
		name = n;
		age = a;
		year = y;
		Average = Av;
	}
	void Print() //переопределение метода 
	{
		Human::Print(); // вызов метода Print базового класса
		cout << "Year: " << year << "\t Average: " << Average << endl;
	}
};

class Teacher : public Human
{
	string subject;
	double salley;
	string academy;
public:
	Teacher(string sub, double sal, string acad)
	{
		subject = sub;
		salley = sal;
		academy = acad;
	}
	void Print()
	{
		Human::Print();
		cout << "Subject: " << subject << "\t Salley: " << salley << "\t Academy: " << academy << endl;
	}
};

int main()
{
	Student obj1("Ivan", 20, 2, 3.6);
	obj1.Print();

}