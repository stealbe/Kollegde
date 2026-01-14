#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void printNums()
{
	for (size_t i = 0; i <= 10; i++)
	{
		cout << i << endl;
		Sleep(200);
	}
}

void printChars()
{
	for (char i = 'A'; i < 'A' + 10; i++)
	{
		cout << i << endl;
		Sleep(250);
	}
}

int main()
{
	thread th1(printNums);
	thread th2(printChars);

	th1.join();
	th2.join();

	cout << "ending...";
	return 0;
}