#include <istream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>
#include <iostream>

using namespace std;

bool fillFileNums(const string& fileName, int numCount = 100)
{
	ofstream outputFile(fileName);
	if (!outputFile.is_open())
	{
		return false;
	}
	for (int i = 1; i <= numCount; ++i)
	{
		outputFile << i << "\n";
	}
	outputFile.close();
	return true;
}

bool fillFileChars(const string& fileName, int charCount = 26)
{
	ofstream outputFile(fileName);
	if (!outputFile.is_open())
	{
		return false;
	}
	for (int i = 0; i < charCount; ++i)
	{
		outputFile << static_cast<char>('A' + (i % 26)) << endl;
	}
	outputFile.close();
	return true;
}

bool readFromFile(const string& fileName)
{
	ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		return false;
	}
	string line;
	while (getline(inputFile, line))
	{
		cout << line + "\n";
		Sleep(50);
	}
	inputFile.close();
	return true;
}

int main()
{
	fillFileNums("numbers.txt");
	fillFileChars("characters.txt");
	thread th1(readFromFile, "numbers.txt");
	thread th2(readFromFile, "characters.txt");

	th1.join();
	th2.join();

	cout << "Reading ended";
	return 0;
}