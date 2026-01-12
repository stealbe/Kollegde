#include<iostream>
using namespace std;

class IPrint  // интерфейс  - контракт !!
{
public:
	virtual string GetStr() = 0;
};

class Transport: public IPrint
{
	string name;
public:
	virtual string GetStr()
	{
		return name;
	}
};

class Person: public IPrint //  абстрактный базовый класс!!!  Заготовка
{
protected:
	string name;
	int age;
public:
	Person(): name(""), age(0) {}
	Person(string n, int a)
	{
		name = n;
		age = a;
	}
	virtual void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
	//virtual string GetStr() = 0;
	
};
class Student: public Person
{
	string Academy;
public:
	Student(string n, int a, string ac):Person(n,a)
	{
		Academy = ac;
	}
	virtual void Print()
	{
		Person::Print();
		cout << "Academy: " << Academy << endl;
	}
	virtual string GetStr()
	{
		return Academy;
	}

};

void Task1(Person * obj)
{
	obj->Print();
	//string str = dynamic_cast<Student*>(obj)->GetStr(); // КОСТЫЛЬ!
}
void Task2(IPrint* ptr)
{
	cout << ptr->GetStr() << endl;
}
int main()
{
	Student obj("Irina", 20, "ItStep");
	Task1(&obj);
	Task2(&obj);

	Transport obj3;

	Task2(&obj3);

	//Person a;

}