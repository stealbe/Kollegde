#include <forward_list>
#include <list>
#include <iostream>
using namespace std;

class Student
{
protected:
    string name;
    int age;
    friend ostream& operator<< (ostream& os, Student& obj);
    friend istream& operator>> (istream& is, Student& obj);
public:
    Student(): name(""), age(0) {}
    Student(string n, int a) { name = n, age = a; }
    virtual void Init(string n, int a) { name = n, age = a; }
    virtual void Print() const { cout << "Name: " << name << endl << "Age: " << age << endl; }
};

int main() {
    forward_list<int> a;

    for (int i = 0; i < 5; i++)
    {
        a.push_front(i + 1);
    }

    for (auto ptr = a.begin(); ptr != a.end(); ptr++)
    {
        cout << *ptr << "\t";
    }
    cout << endl;
    a.pop_front();
    for (auto ptr = a.begin(); ptr != a.end(); ptr++)
    {
        cout << *ptr << "\t";
    }
    cout << endl;

    for (auto i : a)
    {
        cout << i << "\t";
    }
    cout << endl;

    list<int> b;

    for (int i = 0; i < 5; i++)
    {
        b.push_back(i + 1);
    }

    for (auto ptr = b.begin(); ptr != b.end(); ptr++)
    {
        cout << *ptr << "\t";
    }
    cout << endl;
    b.pop_front();
    b.pop_back();
    for (auto ptr = b.begin(); ptr != b.end(); ptr++)
    {
        cout << *ptr << "\t";
    }
    cout << endl;

    for (auto i : b)
    {
        cout << i << "\t";
    }
    cout << endl;

    list<Student> group;
    for (int i = 0; i < 5; i++)
    {
        group.push_back(Student("Ivan", 20 + i));
    }

    for (auto n : group)
    {
        cout << n << "\t";
    }
    cout << endl;

    list<Student> group2;
    for (int i = 0; i < 5; i++)
    {
        Student buf;
        cin >> buf;
        group2.push_back(buf);
    }
    for (auto n : group2)
    {
        cout << n << endl;
    }
    return 0;
}

ostream& operator<<(ostream& os, Student& obj)
{
    os << "Name: " << obj.name << endl << "Age: " << obj.age << endl;
    return os;
}

istream& operator>>(istream& is, Student& obj)
{
    cout << "Name: ";
    is >> obj.name;
    cout << "Age: ";
    is >> obj.age;
    return is;
}
