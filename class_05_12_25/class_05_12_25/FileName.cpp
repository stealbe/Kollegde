#include <iostream>
#include <set>
#include <map>
using namespace std;

class Student
{
	string name;
	int age; // key
	friend ostream& operator<< (ostream& os, const Student& obj);
public:
	Student() : name(""), age(0) {}
	Student(string n, int a) : name(n), age(a) {}
	void Print() const { cout << "Name: " << name << "\tAge: " << age << endl; }
	void setName(string n) { name = n; }
	void setAge(int a) { age = a; }
	string getName() { return name; }
	int getAge() { return age; }

	int operator> (const Student& obj) const { return age > obj.age; }
	int operator< (const Student& obj) const { return age < obj.age; }
};

ostream& operator<<(ostream& os, const Student& obj)
{
	os << "Name: " << obj.name << "\tAge: " << obj.age << endl;

	return os;
}


typedef pair<Student, Student> mypair;

int main()
{
	setlocale(0, "ru");

	set<int> set;
	set.insert(5);
	set.insert(2);
	set.insert(8);
	set.insert(-1);
	set.insert(4);
	set.insert(4);
	set.insert(4);
	set.insert(4);

	/*for (auto i : set) cout << i << "\t";
	cout << endl;*/

	for (auto ptr = set.begin(); ptr != set.end(); ptr++) cout << *ptr << "\t";
	cout << endl;

	multiset<int> mset;
	mset.insert(5);
	mset.insert(2);
	mset.insert(2);
	mset.insert(8);
	mset.insert(-1);
	mset.insert(-1);
	mset.insert(4);
	mset.insert(4);

	for (auto ptr = mset.begin(); ptr != mset.end(); ptr++) cout << *ptr << "\t";
	cout << endl;

	//map<int, string> map; // sort by keys
	//map.insert(pair<int, string>(4000, "Sidorov"));
	//map.insert(pair<int, string>(3000, "Petrov"));
	//map.insert(pair<int, string>(14000, "Kolesnikov"));
	//map.insert(pair<int, string>(1000, "Ivanov"));
	//map.insert(pair<int, string>(100, "Nikiforov"));

	//for (auto ptr = map.begin(); ptr != map.end(); ptr++) cout << ptr->second << " $:" << ptr->first << "\t";
	//cout << endl;

	multimap<Student, Student> group;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "Enter name: ";
		string name;
		cin >> name;
		cout << "Enter age: ";
		int age;
		cin >> age;
		group.insert(mypair(Student(name, age), Student(name, age)));
	}

	for (auto i : group) i.second.Print();

	return 0;
}