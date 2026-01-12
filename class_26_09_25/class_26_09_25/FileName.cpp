#include <iostream>
using namespace std;

void Fill_arr(int* _arr, int size)
{
    srand(unsigned(time(0)));
    for (size_t i = 0; i < size; i++)
    {
        _arr[i] = ((rand() % 199) - 99);
    }

}

void BubbleSort(int arr[], int size)
{
    int temp;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void PrintArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void Arr_shift(int* arr, const int size, const int from = 0, const int to, int rp);

void Mix_arr(int* arr, const int size)
{
    int maxOddElem = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > maxOddElem && arr[i] % 2 != 0) maxOddElem = i;
    }
    Arr_shift(arr, size, 0, maxOddElem, 1);
    Arr_shift(arr, size, size, maxOddElem, 3);
}

void Arr_shift(int* arr, const int size, const int from = 0, const int to, int rp)
{
    if (to > from)
    {
        int len = to - from;
        if (len == 0) return;

        rp %= len;
        int* temp = new int[len];
        for (size_t i = 0; i < len; i++)
        {
            temp[i] = arr[from + i];
        }
        for (size_t i = 0; i < len; i++)
        {
            arr[from + (i + rp) % len] = temp[i];
        }

        delete[] temp;
    }
    else
    {
        size_t len = to - from;
        if (len == 0) return;

        rp %= len;

        int* temp = new int[len];

        for (size_t i = 0; i < len; i++)
        {
            temp[i] = arr[from + i];
        }

        for (size_t i = 0; i < len; i++)
        {
            arr[from + i] = temp[(i + rp) % len];
        }

        delete[] temp;
    }
}

int SumNearZero(int* arr, const int size)
{
    int zero1 = -1;
    int zero2 = -1;
    for (size_t i = 0; i < size && zero1 == -1; i++)
    {
        if (arr[i] == 0) zero1 = i;
    }
    if (zero1 == -1) return 0;
    for (size_t i = 0; i < size && zero2 == -1; i++)
    {
        if (arr[i] == 0) zero2 = i;
    }
    if (zero2 == -1) return 0;
    int sum = 0;
    for (size_t i = zero1; i < zero2; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[5]{ 4,2,3,1,5 };
    BubbleSort(arr, 5);
    PrintArr(arr, 5);

    int* arr2 = new int[100];
    Fill_arr(arr2, 100);
    cout << "Before: ";
    PrintArr(arr2, 100);
    Mix_arr(arr2, 100);
    cout << "After: ";
    PrintArr(arr2, 100);
    cout << SumNearZero(arr2, 100) << endl;
}
