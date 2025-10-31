#include <iostream>
using namespace std;

template<class T>
void Fill_arr(T** arr, const int& size = 0)
{
	if (size == 0) throw "Size == 0";
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 50.0;
	}
	arr[size] = nullptr;
}

template<class T>
void Print(T& arr, const int& size = 0)
{
	if (size == 0) throw "Size == 0";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

template <class T>
void Add_l_elem(T** arr, const int& size = 0, const T& n = 0)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = *arr[i];
	}
	temp[size + 1] = nullptr;
	delete[] arr;
	temp[size] = n;
	arr = &temp;
}

template <class T>
void Add_f_elem(T** arr, const int& size = 0, const T& n = 0)
{
	T* temp = new T[size + 1];
	temp[0] = n;
	for (size_t i = 1; i < size + 1; i++)
	{
		temp[i] = *arr[i];
	}
	temp[size + 1] = nullptr;
	delete[] arr;
	arr = &temp;
}

template <class T>
void Init_elem(T** arr, const int& id = -1, const T& n = 0)
{
	if (id < 0) throw "Id can't be < 0";
	arr[id] = n;
}

template<class T1, class T2, class T3>
void Add_arr(T1** arr1, const int& size1, T2** arr2, const int& size2)
{
	T3* res = new T3[size1 + size2 + 1];
	for (size_t i = 0; i < size1; i++)
	{
		res[i] = *arr1[i];
	}
	for (size_t i = 0; i < size2; i++)
	{
		res[i + size1] = *arr2[i];
	}
	res[size1 + size2 + 1] = nullptr;
	delete[] arr1;
	arr1 = &res;
}

template <class T>
T& Del_l_elem(T& arr, const int size = 0)
{
	T* temp = new T[size - 1];
	for (size_t i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	temp[size - 1] = nullptr;
	delete[] arr;
	arr = temp;
	return arr;
}

template <class T>
T& Del_f_elem(T& arr, const int size = 0)
{
	T* temp = new T[size - 1];
	for (size_t i = 1; i < size; i++)
	{
		temp[i - 1] = arr[i];
	}
	temp[size - 1] = nullptr;
	delete[] arr;
	arr = temp;
	return arr;
}

template<class T>
T& Del_arr(T& arrM, const int sizeM, T& arrS, const int sizeS)
{
	int simp = 0;
	for (size_t i = 0; i < sizeM; i++)
	{
		if (arrM[i] == arrS[simp]) simp++;
		else simp = 0;
		
		if (simp == sizeS)
		{
			for (size_t i = simp; i < sizeS; i--)
			{

			}
		}
	}
}

int main() {
	srand(time(NULL));

    int size;
    cout << "Enter size: ";
	int* arr = nullptr;
	try
	{
		cin >> size;
		if (size < -0) throw "Size can't be <= 0";
		arr = new int[size] {0};
		Fill_arr(arr, size);
	}
	catch (const char* err)
	{
		cout << "Error: " << err << endl;
	}

	delete[] arr;
    return 0;
}