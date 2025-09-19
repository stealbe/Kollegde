#include <iostream>
#include <Windows.h>
using namespace std;

void Resize(int* arr, const int size)
{
	int* temp = new int[size];
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != 0)  temp[j++] = arr[i];
	}
	while (j < size)
	{
		temp[j++] = -1;
	}
}

void Cat(int* arr, int* arr2, const int size = 5, const int size2 = 5)
{
	int* temp = new int[size + size2];
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > 0) temp[j++] = arr[i];
		if (arr2[i] > 0) temp[j++] = arr2[i];
	}
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0) temp[j++] = arr[i];
		if (arr2[i] == 0) temp[j++] = arr2[i];
	}
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < 0) temp[j++] = arr[i];
		if (arr2[i] < 0) temp[j++] = arr2[i];
	}
}

int main() {

    return 0;
}