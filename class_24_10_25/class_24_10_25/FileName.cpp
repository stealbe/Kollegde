#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void bubbleSort(int a[], long size) {
	long i, j;
	int x;
	for (i = 0; i < size; i++) {            // i - номер прохода
		for (j = size - 1; j > i; j--) {     // внутренний цикл прохода
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
}


int BinarySearch(int A[], int Lb, int Ub, int Key)
{
	int M;
	while (1) {
		M = (Lb + Ub) / 2;
		if (Key < A[M])
			Ub = M - 1;
		else if (Key > A[M])
			Lb = M + 1;
		else
			return M;

		if (Lb > Ub)
			return -1;
	}
}

void Print(int ar[], int SIZE)
{
	for (int i = 0; i < SIZE; i++) {

		cout << ar[i] << "\t";
	}
	cout << endl;
}

void main() {
	srand(time(NULL));
	const long SIZE = 10;
	int ar[SIZE];
	int key, ind;

	// до сортировки
	for (int i = 0; i < SIZE; i++) {
		ar[i] = rand() % 20;
	}
	Print(ar, SIZE);
	bubbleSort(ar, SIZE);
	Print(ar, SIZE);
	cout << "\n\n";
	cout << "Enter any digit:";
	cin >> key;
	ind = BinarySearch(ar, 0, SIZE, key);
	cout << "Index - " << ind << "\t";
	cout << "\n\n";
}

