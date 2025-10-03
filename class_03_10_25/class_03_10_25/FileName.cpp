#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void insertSort(int a[], long size) {
    int x;
    long i, j;
    int count = 0;

    for (i = 0; i < size; i++) {  // ���� ��������, i - ����� �������
        x = a[i];

        // ����� ����� �������� � ������� ������������������ 
        for (j = i - 1; j >= 0 && a[j] > x; j--)
        {
            a[j + 1] = a[j];    // �������� ������� �������, ���� �� �����
            count++;
        }
        // ����� �������, �������� �������
        a[j + 1] = x;
    }
}

int main() {
    srand(time(NULL));
    const long SIZE = 10;
    int ar[SIZE];

    // �� ����������
    for (int i = 0; i < SIZE; i++) {
        ar[i] = rand() % 30;
        cout << ar[i] << "\t";
    }
    cout << "\n\n";
    insertSort(ar, SIZE);

    // ����� ����������
    for (int i = 0; i < SIZE; i++) {
        cout << ar[i] << "\t";
    }
    cout << "\n\n";
}
