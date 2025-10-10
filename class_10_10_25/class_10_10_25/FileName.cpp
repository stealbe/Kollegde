#include <iostream>
#include <time.h>
using namespace std;

void selectSort(int a[], long size) {
	long i, j, k;
	int x;

	for (i = 0; i < size; i++) {   	// i - ����� �������� ����
		k = i;
		x = a[i];

		for (j = i + 1; j < size; j++)	// ���� ������ ����������� ��������
			if (a[j] < x) {
				k = j;
				x = a[j];	        // k - ������ ����������� ��������
			}
		a[k] = a[i];
		a[i] = x;   	// ������ ������� ���������� � a[i]
	}
}

int main() {
	srand(time(NULL));
	const long SIZE = 10;
	int ar[SIZE];

	// �� ����������
	for (int i = 0; i < SIZE; i++) {
		ar[i] = rand() % 50;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
	selectSort(ar, SIZE);

	// ����� ����������
	for (int i = 0; i < SIZE; i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
}
