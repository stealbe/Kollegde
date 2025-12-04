#pragma once
#include <string>
using namespace std;

class Human {
protected:
	string FName;
	string LName;
	int age;
public:
	Human() : FName("Guest"), LName("undefined"), age(0) {}
	Human(string fName, string lName, int age) : FName(fName), LName(lName), age(age) {}
};