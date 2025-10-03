#include <iostream>
using namespace std;

struct Mounth
{
	char* name;
	int name_size = 0;
	double profit = 0;
};

double Sum(Mounth* arr, const int size = 6)
{
    double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i].profit;
	}
	return sum;
}

void Print_arr_rev(int* arr, const int size)
{
	for (size_t i = size; i > 0; i--)
	{
		cout << arr[i] << endl;
	}
}

double P_rect(double* sides)
{
	return(sides[0] * 2 + sides[1] * 2);
}

int HProfM(Mounth* arr, const int size = 12)
{

}

int LProfM(Mounth* arr, const int size = 12)
{

}

int main() {

    return 0;
}
