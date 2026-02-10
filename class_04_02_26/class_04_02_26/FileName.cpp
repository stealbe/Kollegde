#include<iostream>
#include<thread>
#include<mutex>
#include<Windows.h>
using namespace std;

int arr[100]; // разделяемый ресурс
mutex flag;

void Init()
{
    flag.lock();
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        cout << "Init\t";
        arr[i] = rand() % 41 - 20;
        //Sleep(10);    
    }
    flag.unlock();
}
void Print()
{
    flag.lock();
    for (int i = 0; i < 100; i++)
    {
        cout << "print:";
        cout << arr[i] << "\t";
    }
    cout << endl;
    flag.unlock();
}

/*
* Добавляем следующие потоковые функции с монопольным доступом к массиву:
* Функция выводит сумму положительных элементов
* Функция выводит среднее арифм значение
* функция выводит массив в обратном порядке (переворачивает массив в памяти)
*/

void SumPositive()
{
    flag.lock();
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        if (arr[i] > 0)
            sum += arr[i];
    }
    cout << "Sum of positive elements: " << sum << endl;
    flag.unlock();
}

void Average()
{
    flag.lock();
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / 100;
    cout << "Average value: " << average << endl;
    flag.unlock();
}

void ReverseArray()
{
    flag.lock();
    for (int i = 0; i < 50; i++)
    {
        swap(arr[i], arr[99 - i]);
    }
    cout << "Array reversed." << endl;
    flag.unlock();
}

int main()
{
    thread t1(Init); // инициализация и запуск
    thread t2(Print);

    t1.join(); // пауза ДО завершения дочернего потока t1
    t2.join(); // пауза ДО завершения дочернего потока t2

    cout << "End main\n";
}