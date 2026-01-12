#include<iostream>
#include<time.h>
#include "DynamicArr.h"
using namespace std;

int main()
{
	srand(time(0));
	D_array<int> obj1(10);
	obj1.Input();
	obj1.Output();

	D_array<char> obj2;
	obj2.Input(10);
	obj2.Output();

	D_array<double>obj3;
	obj3.Input(15);
	obj3.Output();

	cout << obj1.GetIndex(1) << endl;

	cout << obj1 << endl;
	cout << obj2 << endl;

	obj1++;
	obj1--;

	system("pause");
}