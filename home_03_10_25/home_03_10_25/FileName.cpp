#include <iostream>
#include <string>
using namespace std;

struct Month {
    string name;
    double profit = 0;
};

void insertSort(Month* arr, int size) {
    for (int i = 1; i < size; i++) {
        Month key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].profit > key.profit) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

double Sum(Month* arr, const int size = 6)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i].profit;
    }
    return sum;
}

void Print_arr_rev(int* arr, const int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double P_pentagon(double* sides, const int n = 5) {
    double p = 0;
    for (int i = 0; i < n; i++) {
        p += sides[i];
    }
    return p;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string names[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                    "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };

    cout << "Задание 1: Прибыль за 6 месяцев\n";
    Month halfYear[6];
    for (int i = 0; i < 6; i++)
    {
        cout << "Введите прибыль за " << names[i] << " : ";
        cin >> halfYear[i].profit;
    }
    cout << "Общая прибыль за 6 месяцев: " << Sum(halfYear, 6) << endl;

    int arr[5] = { 1, 2, 3, 4, 5 };
    Print_arr_rev(arr, 5);

    double sides[5];
    for (int i = 0; i < 5; i++) {
        cout << "Введите длину стороны " << i + 1 << ": ";
        cin >> sides[i];
    }
    cout << "Периметр пятиугольника = " << P_pentagon(sides, 5) << endl;

    Month year[12];

    for (int i = 0; i < 12; i++) {
        year[i].name = names[i];
        cout << "Введите прибыль за " << names[i] << ": ";
        cin >> year[i].profit;
    }

    insertSort(year, 12);

    cout << "Месяц с минимальной прибылью: " << year[0].name << " (" << year[0].profit << ")" << endl;
    cout << "Месяц с максимальной прибылью: " << year[11].name << " (" << year[11].profit << ")" << endl;

    return 0;
}
