#include<iostream>
using namespace std;

class Student
{
    char* name;
    int age;
public:
    ////  prototype 
    Student();
    Student(const char*, int); // construct by 2 param
    Student(const Student& obj2);
    void Output();
    Student& operator= (Student& obj);
    ~Student();

};
Student::Student(const Student& obj2) // copy constructor
{
    name = new char[strlen(obj2.name) + 1];
    strcpy_s(name, strlen(obj2.name) + 1, obj2.name);
    age = obj2.age;
}
Student::Student()
{
    name = nullptr;
    age = 0;
}
Student::Student(const char* Name, int Age)
{
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
    age = Age;
}
void Student::Output()
{
    cout << "Name: " << name << endl
        << "Age: " << age << endl << endl;
}
Student& Student::operator=(Student& obj)
{
    if (this == &obj) return *this;
    if (name != nullptr) delete[] name;
    name = new char[strlen(obj.name) + 1];
    strcpy_s(name, strlen(obj.name) + 1, obj.name);
    age = obj.age;
    return *this;
}
Student::~Student()
{
    delete[] name;
}

int main()
{
    Student obj1("Oleg", 21);
    obj1.Output();



}
