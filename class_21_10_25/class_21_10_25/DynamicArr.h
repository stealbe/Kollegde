#pragma once
#include <iostream>
using namespace std;

template<class T>
class D_array
{
	T* mas = nullptr;
	int size;

	friend ostream& operator<< (ostream& os, D_array<T>& obj);
	friend istream& operator>> (istream& is, D_array<T>& obj);
public:
	D_array();
	D_array(int size);
	void Output();
	~D_array();
	T operator[](int index);
	D_array& operator-(D_array& obj);
	D_array& operator--(int);
	D_array& operator++(int);
	D_array& operator=(const D_array& obj);
	int GetSize()const
	{
		return size;
	}
	T* GetPtr()const
	{
		return mas;
	}
	void SetSize(int s)
	{
		size = s;
	}
	void Init(T* nArr, int nSize);
	void Input();
	void Input(int size);

	T GetIndex(int id);
	void SetIndex(T n, int id);
};
template<class T>
D_array<T>::D_array()
{
	size = 10;
	mas = new T[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 100 * 1.2;
	}
}
template<class T>D_array<T>::D_array(int size)
{
	this->size = size;
	mas = new T[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 100 * 1.2;
	}
}
template<class T>void D_array<T>::Output()
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << endl << endl;
}
template<class T>D_array<T>::~D_array()
{
	if (mas != nullptr)
	{
		delete[] mas;
	}
}

template<class T>T D_array<T>::operator[](int index)
{
	return mas[index];
}

template<class T>
inline D_array<T>& D_array<T>::operator-(D_array& obj)
{
	D_array<T> temp(max(size, obj.size));
	for (size_t i = 0; i < max(size, obj.size); i++)
	{
		if (size > obj.size && i > min(size, obj.size)) temp[i] = mas[i];
		else if (size < obj.size && i > min(size, obj.size)) temp[i] = obj.mas[i];
		else temp[i] = mas[i] - obj.mas[i];
	}
	return temp;
}

template<class T>
inline D_array<T>& D_array<T>::operator--(int)
{
	D_array temp = *this;
	if (mas != NULL) delete[] mas;
	mas = new T[size - 1];
	for (size_t i = 0; i < size - 1; i++)
	{
		mas[i] = temp.mas[i];
	}
	return temp;
}

template<class T>
inline D_array<T>& D_array<T>::operator++(int)
{
	D_array temp = *this;
	if (mas != NULL) delete[] mas;
	mas = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		mas[i] = temp.mas[i];
	}
	mas[size++] = rand() % 100 * 1.2;

	return temp;
}

template<class T>
inline D_array<T>& D_array<T>::operator=(const D_array& obj)
{
	if (this == &obj) return *this;
	if (mas != NULL) delete[] mas;
	size = obj.size;
	mas = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		mas[i] = obj.mas[i];
	}
	return *this;
}

template<class T>
inline void D_array<T>::Init(T* nArr, int nSize)
{
	if (mas != NULL) delete[] mas;
	size = nSize;
	mas = nArr;
}

template<class T>
void D_array<T>::Input()
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> mas[i];
	}
}

template<class T>
void D_array<T>::Input(int size)
{
	this->size = size;
	mas = new T[size];
	for (size_t i = 0; i < this->size; i++)
	{
		cin >> mas[i];
	}
}

template<class T>
inline T D_array<T>::GetIndex(int id)
{
	return mas[id];
}

template<class T>
inline void D_array<T>::SetIndex(T n, int id)
{
	mas[id] = n;
}

template<class T>
ostream& operator<< (ostream& os, D_array<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.mas[i];
	}
	os << endl;
	return os;
}

template<class T>
istream& operator>> (istream& is, D_array<T>& obj)
{
	int iSize;
	cout << "size: ";
	is >> iSize;
	T* iArr = new T[iSize];
	cout << "Array of " << iSize << " nums: ";
	for (size_t i = 0; i < iSize; i++)
	{
		cout << i + 1 << ": ";
		T n;
		is >> n;
		iArr[i] = n;
	}
	obj.mas = iArr;
	obj.size = iSize;
	return is;
}