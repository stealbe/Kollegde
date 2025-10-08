#include "MVector.h"
#include <iostream>

using namespace std;

MVector::MVector() :arr(nullptr), size(0) {}
MVector::MVector(int size):size(size), arr(new int [size]) {}

MVector::MVector(const MVector& obj)
{
	size = obj.size;
	if (arr != nullptr) delete[] arr;
	arr = new int[size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = obj.arr[i];
	}
}

MVector::MVector(MVector&& obj)noexcept
{
	arr = obj.arr;
	size = obj.size;
	obj.arr = nullptr;
	obj.size = 0;
}

MVector::~MVector()
{
	delete[] arr;
	size = 0;
}

void MVector::Init()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}
}

void MVector::Print()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int MVector::GetSize() const
{
	return size;
}

int MVector::operator[](int i)
{
	if (i >= 0 && i < size) return arr[i];
	return -1;
}

MVector& MVector::operator=(const MVector& obj)
{
	if (this == &obj) return *this;
	if (arr != nullptr) delete arr;
	size = obj.size;
	arr = new int[size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

MVector MVector::operator--(int)
{
	MVector temp = *this;
	int* tempArr = new int[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		tempArr[i] = arr[i];
	}
	tempArr[--size] = '\0';
	delete[] arr;
	arr = tempArr;
	return temp;
}

MVector MVector::operator++(int)
{
	MVector temp = *this;
	int* tempArr = new int[size + 2];
	for (size_t i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}
	tempArr[size] = 0;
	tempArr[size++ + 1] = '\0';
	delete[] arr;
	arr = tempArr;
	return temp;
}
