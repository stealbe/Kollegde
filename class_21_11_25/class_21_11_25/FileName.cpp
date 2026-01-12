#include <iostream>
#include <vector>
using namespace std;

class Student
{
    string name;
    int age;
    friend ostream& operator<< (ostream& os, Student& obj);
public:
    Student() { name = ""; age = 0; }
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Print() { cout << *this << endl; }
};

int main() {
    //vector<double> arr(10);
    //for (int i = 0; i < 20; i++)
    //{
    //    arr.insert(arr.begin() + i, rand() % 20 * 0.66 * 0.33);
    //    cout << arr[i] << endl;
    //}

    //vector<double>::iterator ptr;
    //for (ptr = arr.begin(); ptr != arr.begin(); ptr++)
    //{
    //    cout << *ptr << "\t";
    //}

    vector<Student> group;
    group.push_back(Student("Irina", 21));
    group.push_back(Student("Oleg", 21));
    group.push_back(Student("Sasa", 21));
    group.push_back(Student("Belaya", 21));
    group.push_back(Student("Kto-to", 21));
    group.push_back(Student("Kto-to", 21));
    group.push_back(Student("Kto-to", 21));
    group.push_back(Student("Kto-to", 21));

    for (size_t i = 0; i < group.size(); i++)
    {
        cout << group[i] << endl;
    }

    for  (auto ptr = group.begin(); ptr != group.end(); ptr++)
    {
        ptr->Print();
    }

    return 0;
}

ostream& operator<<(ostream& os, Student& obj)
{
    os << "Name: " << obj.name << "\tAge: " << obj.age << endl;
    return os;
}
