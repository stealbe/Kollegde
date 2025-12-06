#pragma once
#include <string>
using namespace std;

class Human : public Entity {
protected:
	string FName;
	string LName;
	int age;
	friend istream& operator>>(istream& in, Human& human)
	{
		cout << "Enter First Name: ";
		in >> human.FName;
		cout << "Enter Last Name: ";
		in >> human.LName;
		cout << "Enter Age: ";
		in >> human.age;
		return in;
	}
public:
	Human() : Entity(), FName("Guest"), LName("undefined"), age(0) {}
	Human(string fName, string lName, int age) : Entity(), FName(fName), LName(lName), age(age) {}
	Human(bool isActive, string fName, string lName, int age) : Entity(isActive), FName(fName), LName(lName), age(age) {}
	void arrive() override {
		if (isActive) throw "Human is already on the base.";
		isActive = true;
	}
	bool leave() override {
		if (!isActive) return 0;
		if (Base::getPeople() <= 0) throw "No people on the base.";
		isActive = false;
		Base::setPeople(Base::getPeople() - 1);
		return 1;
	}
	void PrintInfo() const {
		cout << "Name: " << FName << " " << LName << ", Age: " << age << ", Active: " << (isActive ? "Yes" : "No") << "\n";
	}
	void PrintName() const {
		cout << FName << " " << LName << "\n";
	}
};