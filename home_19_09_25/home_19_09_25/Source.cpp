#include <iostream>
using namespace std;

void UnCat(int* arr, const int size, int*& arr_s1, int*& arr_s2)
{
	arr_s1 = new int[size / 2];
	arr_s2 = new int[size / 2];
	for (size_t i = 0; i < size / 2; i++)
	{
		arr_s1[i] = arr[i];
		arr_s2[i] = arr[i + size / 2];
	}
}

int* Sum_arrs(const int* arr1, const int size1, const int* arr2, const int size2)
{
	int size = (size1 > size2 ? size1 : size2);
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = (i < size1 ? arr1[i] : 0) + (i < size2 ? arr2[i] : 0);
	}
	return arr;
}

double AllSpend(const int* arr, const int size = 7)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double MidSpend(const int* arr, const int size = 7)
{
	return AllSpend(arr, size) / size;
}

struct SpendDay
{
	int day;
	double spend;
};

SpendDay* More100d(const int* _arr, const int _size, int& size_out)
{
	size_out = 0;
	for (size_t i = 0; i < _size; i++)
	{
		if (_arr[i] > 100)
		{
			size_out++;
		}
	}
	SpendDay* arr = new SpendDay[size_out];
	int j = 0;
	for (size_t i = 0; i < _size; i++)
	{
		if (_arr[i] > 100)
		{
			arr[j].spend = _arr[i];
			arr[j++].day = i;
		}
	}
	return arr;
}


int main() {
	setlocale(LC_ALL, "Russian");
	const int size = 10;
	int arr[size] = { 10, 20, 30, 40, 50, 150, 200, 70, 90, 120 };

	int* left = nullptr;
	int* right = nullptr;
	UnCat(arr, size, left, right);

	cout << "Первая часть: ";
	for (int i = 0; i < size / 2; i++) cout << left[i] << " ";
	cout << "\nВторая часть: ";
	for (int i = 0; i < size / 2; i++) cout << right[i] << " ";
	cout << "\n\n";

	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[7] = { 10, 20, 30, 40, 50, 60, 70 };
	int* sum = Sum_arrs(arr1, 5, arr2, 7);

	cout << "Сумма массивов: ";
	for (int i = 0; i < 7; i++) cout << sum[i] << " ";
	cout << "\n\n";

	const char* days[7] = {
			"Понедельник","Вторник","Среда",
			"Четверг","Пятница","Суббота","Воскресенье"
	};

	int spends[7];
	cout << "Введите расходы за неделю (в долларах):\n";
	for (int i = 0; i < 7; i++)
	{
		cout << days[i];
		cin >> spends[i];
	}

	cout << "\nОбщая сумма: " << AllSpend(spends, 7) << " $\n";
	cout << "Средняя сумма: " << MidSpend(spends, 7) << " $\n";

	int n;
	SpendDay* big = More100d(spends, 7, n);
	if (n > 0) {
		cout << "Дни с расходами >100$:\n";
		for (int i = 0; i < n; i++)
			cout << days[big[i].day] << " (" << big[i].spend << " $)\n";
	}
	delete[] big;
	delete[] left;
	delete[] right;
	delete[] sum;

	return 0;
}