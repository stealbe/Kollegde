#include <iostream>
using namespace std;

#include "Developer.h"
#include "Employee.h"
#include "Manager.h"
#include <vector>

int main()
{
	vector<Employee*> arr;
	arr.push_back(new Manager("Hight-manager", "Ivan", 21, 1800));
	arr.push_back(new Developer("Senoir", "Oleg", 42, 3800));
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i]->Print();
	}
	return 0;
}