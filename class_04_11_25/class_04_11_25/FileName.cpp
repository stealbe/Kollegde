#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student(string n, string s, int a)
	{
		name = n;
		surname = s;
		age = a;
	}
	void Print()
	{
		cout << "Name: " << name << "Surname: " << surname << "\tAge: " << age << endl;
	}
	void Input()
	{
		cout << "Enter Name: ";
		cin >> name;

		cout << "Enter Surname: ";
		cin >> surname;

		cout << "Enter Age: ";
		cin >> age;
	}

	//------------- HW
	void SaveFile() {
		ofstream fs;
		fs.open("Students.txt", ios::app | ios::out);
		fs << name << " " << surname << ":" << endl << "    " << age << ";" << endl;
		fs.close();
	} // записбь объекта в файл
	void LoadFile() {
		ifstream fs;
		fs.open("Students.txt", ios::in);
		if (!fs) throw "fs can't be empty";
		do
		{
			char chr = '\0';
			fs.get(chr);
			cout << chr;
		} while (fs);
		fs.close();
	} // вывод всех студентов

};

int main()
{
	try
	{
		Student obj1("Ivan", "Ivanov", 19);

		// показать результат работы

		obj1.SaveFile();
		obj1.LoadFile();
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
}