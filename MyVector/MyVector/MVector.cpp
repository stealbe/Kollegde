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

void MVector::Init(int* nArr, const int nSize)
{
	if (arr != nullptr) delete[] arr;
	arr = nArr;
	size = nSize;
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

void MVector::SetIndex(int i, int n)
{
	arr[i] = n;
}

int MVector::GetIndex(int i)
{
	return arr[i];
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

MVector::operator int()
{
	return size;
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

void MVector::operator() ()
{
	Print();
}

void MVector::operator() (int* arr, int size)
{
	this->size = size;
	if (this->arr != nullptr) delete[] this->arr;
	this->arr = new int[size + 1];
	for (size_t i = 0; i < this->size + 1; i++)
	{
		this->arr[i] = arr[i];
	}
}

MVector& MVector::operator=(MVector&& obj)noexcept
{
	size = obj.size;
	if (arr != nullptr) delete[] arr;
	arr = new int[size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = obj.arr[i];
	}
	delete[] obj.arr;
	obj.size = 0;
	return *this;
}

MVector& MVector::operator+=(int n)
{
	int* tempArr = new int[size + n + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		tempArr[i] = arr[i];
	}
	for (size_t i = size + 1; i < size + n + 1; i++)
	{
		tempArr[i] = 0;
	}
	tempArr[size += n] = '\0';
	return *this;
}

MVector& MVector::operator+=(MVector& obj)
{
	int* tempArr = new int[size + obj.size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		tempArr[i] = arr[i];
	}
	for (size_t i = size + 1; i < size + obj.size + 1; i++)
	{
		tempArr[i] = obj.arr[i - size];
	}
	tempArr[size += obj.size] = '\0';
	return *this;
}

MVector& MVector::operator-=(int n)
{
	int* tempArr = new int[size - n + 1];
	for (size_t i = 0; i < size - n + 1; i++)
	{
		tempArr[i] = arr[i];
	}
	tempArr[size -= n + 1] = '\0';
	return *this;
}

MVector& MVector::operator-=(MVector& obj)
{
	int* tempArr = new int[size - obj.size + 1];
	for (size_t i = 0; i < size - obj.size + 1; i++)
	{
		tempArr[i] = arr[i];
	}
	tempArr[size -= obj.size + 1] = '\0';
	return *this;
}

MVector& MVector::operator*=(int n)
{
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] *= n;
	}
	return *this;
}

MVector& MVector::operator*=(MVector& obj)
{
	if (size >= obj.size)
	{
		for (size_t i = 0; i < obj.size + 1; i++)
		{
			arr[i] *= obj.arr[i];
		}
	}
	else
	{
		int* tempArr = new int[obj.size + 1];
		for (size_t i = 0; i < size + 1; i++)
		{
			tempArr[i] = arr[i] * obj.arr[i];
		}
		for (size_t i = size + 1; i < obj.size + 1; i++)
		{
			tempArr[i] = obj.arr[i];
		}
		delete[] arr;
		size = obj.size;
		tempArr[size] = '\0';
		arr = tempArr;
	}
	return *this;
}

MVector& MVector::operator/=(int n)
{
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] /= n;
	}
	return *this;
}

MVector& MVector::operator/=(MVector& obj)
{
	if (size >= obj.size)
	{
		for (size_t i = 0; i < obj.size + 1; i++)
		{
			arr[i] *= obj.arr[i];
		}
	}
	else
	{
		int* tempArr = new int[obj.size + 1];
		for (size_t i = 0; i < size + 1; i++)
		{
			tempArr[i] = arr[i] / obj.arr[i];
		}
		for (size_t i = size + 1; i < obj.size + 1; i++)
		{
			tempArr[i] = 0;
		}
		delete[] arr;
		size = obj.size;
		tempArr[size] = '\0';
		arr = tempArr;
	}
	return *this;
}
