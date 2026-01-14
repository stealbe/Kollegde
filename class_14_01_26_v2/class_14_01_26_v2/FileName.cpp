#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void printNums()
{
	for (size_t i = 0; i <= 100; i++)
	{
		cout << i << endl;
		Sleep(200);
	}
}

void printChars()
{
	for (char i = 'A'; i < 'Z'; i++)
	{
		cout << i << endl;
		Sleep(500);
	}
}

int sumof(int start, int end)
{
	int sum = 0;
	for (size_t i = start; i <= end; i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	thread th2(printChars);

	thread th1(printNums);

	th1.join();
	th2.join();

	cout << sumof(1, 34) << endl;

	cout << "ending...";
	return 0;
}