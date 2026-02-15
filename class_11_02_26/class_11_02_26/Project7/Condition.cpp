//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//#include <condition_variable>
//
//using namespace std;
//
//mutex mtx;
//condition_variable cv;
//bool ready = false;  // сигнальная переменная
//
//int arr[100];
//
///*
//* Разделяемый ресурс - файл.
//waitingThread() - реализует чтение из файла и вывод на консоль
//signalingThread() - реализует запись данных в файл(запись строк в цикле)
//
//*/
//
//// Поток, который ждёт сигнала
//void waitingThread() 
//{
//    unique_lock<mutex> lock(mtx);
//
//    cout << "Ожидающий поток: жду сигнал... инициализация массива!!!" << endl;
//
//    // Классический цикл ожидания
//    while (!ready) {
//        cv.wait(lock);
//    }
//    cout << "Ожидающий поток: сигнал получен! Вывод массива!!!" << endl;
//
//    for (int i = 0; i < 100; i++)
//    {
//        cout << arr[i] << "\t";
//    }
//    cout << endl;
//}
//// Поток, который подаёт сигнал
//void signalingThread() {
//    //this_thread::sleep_for(chrono::seconds(1));
//    Sleep(1000);
//    {
//        lock_guard<mutex> lk(mtx);
//        for (int i = 0; i < 100; i++)
//        {
//            arr[i] = i + 1;
//        }
//        ready = true;
//        cout << "\nСигналящий поток: ready = true МАССИВ ИНИЦИАЛИЗИРОВАН!!!" << endl;
//        Sleep(1000);
//    }
//    cv.notify_one(); 
//}
//
//int main() {
//    setlocale(0, "ru");
//    thread t1(waitingThread);
//    thread t2(signalingThread);
//
//    t1.join();
//    t2.join();
//
//    cout << "Готово." << endl;
//    return 0;
//}
//
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//mutex mtx;
//condition_variable_any cv;   // <-- ВАЖНО: condition_variable_any
//bool ready = false;
//
//void waitingThread()//  Ожидающий поток
//{
//    cout << "Ожидающий поток: жду сигнал..." << endl;
//
//    mtx.lock();
//    while (!ready) {
//        cv.wait(mtx);   // <-- ЭТО РАБОТАЕТ с condition_variable_any!
//    }
//    mtx.unlock();
//
//    cout << "Ожидающий поток: сигнал получен!" << endl;
//}
//
//void signalingThread() // Сигналящий поток
//{
//    this_thread::sleep_for(chrono::seconds(1));
//
//    {
//        lock_guard<mutex> lock(mtx);
//        ready = true;
//        cout << "Сигналящий поток: ready = true" << endl;
//    }
//
//    cv.notify_one();
//}
//
//int main() {
//    setlocale(0, "ru");
//    thread t1(waitingThread);
//    thread t2(signalingThread);
//
//    t1.join();
//    t2.join();
//
//    cout << "Готово." << endl;
//}
/*
В примере есть два потока:
1. Ожидающий поток

 Захватывает mutex вручную:
 mtx.lock();
 В цикле while (!ready) вызывает cv.wait(mtx);
 wait() временно освобождает mutex и усыпляет поток.
 Когда другой поток подаст сигнал — проснётся и проверит условие ещё раз.
 После выхода из цикла — печатает сообщение.

2. Сигналящий поток

Спит 1 секунду (имитирует работу).
Захватывает mutex через lock_guard.
Устанавливает флаг ready = true.
Вызывает cv.notify_one(), разбудив ожидающий поток.

*/