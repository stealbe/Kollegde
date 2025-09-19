#include <iostream>
using namespace std;

void UnCat(int* arr, const int size = 10, int* arr_s1, int* arr_s2)
{
	arr_s1 = new int[size / 2];
	arr_s2 = new int[size / 2];
	for (size_t i = 0; i < size / 2; i++)
	{
		arr_s1[i] = arr[i];
		arr_s2[i + size / 2] = arr[i + size / 2];
	}
}

int* Sum_arrs(const int* arr1, const int size1, const int* arr2, const int size2)
{
	int size = (size1 > size2 ? size1 : size2);
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		if (size1 > size2 && i >= size1) arr[i] = arr1[i];
		else if (size1 < size2 && i >= size2) arr[i] = arr2[i];
		else arr[i] = arr1[i] + arr2[i];
	}
	return arr;
}

int main() {

    return 0;
}