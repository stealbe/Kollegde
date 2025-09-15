#include <iostream>
using namespace std;

int Max_arr(const int* arr, const int size)
{
	int max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

int Min_arr(const int* arr, const int size)
{
	int min = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}

void Fill_arr(int* _arr, int size)
{
	srand(unsigned(time(0)));
	for (size_t i = 0; i < size; i++)
	{
		_arr[i] = (rand() % 100) / 10;
	}
}

int Sum_arr(int* _arr, int size, int num)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (_arr[i] < num)
		{
			sum += _arr[i];
		}
	}
	return sum;
}

void Min_arr_diap(double* _arr, const int size, int mouth_1 = 0, int mouth_2)
{
	double min;
	int min_mouth;
	for (size_t i = mouth_1; i < mouth_2 && i < size; i++)
	{
		if (min > _arr[i])
		{
			min = _arr[i];
			min_mouth = i;
		}
	}

	cout << "Min count was in " << min_mouth << " mouth: " << min << endl;
}

void Max_arr_diap(double* _arr, const int size, int mouth_1 = 0, int mouth_2)
{
	double max;
	int max_mouth;
	for (size_t i = mouth_1; i < mouth_2 && i < size; i++)
	{
		if (max < _arr[i])
		{
			max = _arr[i];
			max_mouth = i;
		}
	}

	cout << "Max count was in " << max_mouth << " mouth: " << max << endl;
}

int Sum_min(int* _arr, const int size)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (_arr[i] < 0)
		{
			sum += _arr[i];
		}
	}
	return sum;
}

int Coun_arr_diap(int* _arr, const int size, int min_d = 0, int max_d)
{
	int coun = 1;
	for (size_t i = min_d; i < max_d && i < size; i++)
	{
		coun *= _arr[i];
	}
	return coun;
}

int Coun_2_n(int* _arr, const int size)
{
	int coun = 1;
	for (size_t i = 2; i < size; i += 2)
	{
		coun *= _arr[i];
	}
	return coun;
}

int Sum_of_to_of(int* _arr, const int size)
{
	int min_n;
	int max_n;
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (_arr[i] < 0) min_n = _arr[i];
	}
	for (size_t i = size; i > 0; i--)
	{
		if (_arr[i] < 0) max_n = _arr[i];
	}
	for (size_t i = min_n; i < max_n; i++)
	{
		sum += _arr[i];
	}
	return sum;
}

int main() {

	int* arr_1 = new int[10];
	Fill_arr(arr_1, 10);
	cout << Max_arr(arr_1, 10) << endl;
	cout << Min_arr(arr_1, 10) << endl;
	cout << Sum_arr(arr_1, 10, 5) << endl;

	double* arr_mouth = new double[12];
	int min;
	int max;
	for (size_t i = 0; i < 12; i++)
	{
		cout << "Enter cout << for " << i + 1 << " mouth: " << endl;
		cin >> arr_mouth[i];
	}
	cout << "Enter (min max) mouth to search: " << endl;
	cin >> min >> max;
	Min_arr_diap(arr_mouth, 12, min, max);
	Max_arr_diap(arr_mouth, 12, min, max);

	int* arr_4 = new int[100];
	Fill_arr(arr_4, 100);
	cout << Sum_min(arr_4, 100) << endl;
	cout << Coun_arr_diap(arr_4, 100, 10, 80) << endl;
	cout << Coun_2_n(arr_4, 100) << endl;
	cout << Sum_of_to_of(arr_4, 100) << endl;
}