#include <iostream>
using namespace std;

class Magazine
{
	string name;
	string descript;
	string tell;
	string email;
	static int count;
	int year;
public:
	Magazine();
	Magazine(string _name, string _descript, string _tell, string _email, int year);
	void Input();
	void Print();
	void SetName(string n);
	void SetDescription(string n);
	void SetTell(string n);
	void SetEmail(string n);
	void SetYear(int y);

	string GetName();
	string GetDescription();
	string GetTell();
	string GetEmail();
	int GetYear();
	static int Count();
};