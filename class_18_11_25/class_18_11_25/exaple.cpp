#include<iostream>
using namespace std;

class Human
{
protected:
	string name;
	int age;
public:
	Human() { name = ""; age = 0; }
	Human(string n, int a) { name = n; age = a; cout << "Human constructor" << endl; }
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
	Student() : Human() { year = 0; Average = 0.0; }
	Student(string n, int a, int y, double Av) : Human(n, a)
	{
		/*name = n;
		age = a;*/
		year = y;
		Average = Av;
		cout << "Studet constructor" << endl;
	}
	void Print() //переопределение метода 
	{
		Human::Print(); // вызов метода Print базового класса
		cout << "Year: " << year << "\t Average: " << Average << endl;
	}
};

int main()
{
	Student obj1("Ivan", 20, 2, 3.6);
	obj1.Print();

}