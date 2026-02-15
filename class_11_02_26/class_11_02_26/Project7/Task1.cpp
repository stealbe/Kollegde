#include <condition_variable> //Механизм ожидания события другим потоком.
#include <mutex>
#include <thread>
#include <queue>
#include <windows.h>
#include <iostream>
using namespace std;

mutex m;
condition_variable cv;
bool ready = false;

void worker() 
{
 unique_lock<mutex> lock(m);

    cv.wait(lock, [] 
        {
            return ready;
        }); // ждём, пока ready станет true
    // здесь ready == true, мьютекс захвачен
    cout << "Work!\n";
}

void signaler() 
{
    {
       lock_guard<mutex> lock(m);
        ready = true;                 // меняем состояние под мьютексом
    } // отпускаем мьютекс
    cv.notify_one();                  // будим один ожидающий поток
}

int main() {
    thread t(worker);
    Sleep(2000);
    thread s(signaler);

    t.join(); 
    s.join();
}
//
//Ожидать нужно только с std::unique_lock<std::mutex>.
//Всегда проверяйте условие(флаг) — либо с предикатом в wait, либо в цикле while (из‑за спонтанных пробуждений).
//Меняйте состояние под тем же мьютексом, что используется в wait.
//Сначала меняем состояние, потом notify.