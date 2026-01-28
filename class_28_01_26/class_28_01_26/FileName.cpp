#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

atomic<int> counter{ 0 };   // общий счётчик
atomic<int> turn{ 0 };      // чей ход (0..3)

void work(int id)
{
    for (int i = 0; i < 5; i++)
    {
        // Ждём своей очереди
        while (turn.load() != id)
        {
            this_thread::yield();
        }

        // Последовательный доступ
        counter.fetch_add(1);

        cout << "Поток " << id
            << " увеличил счётчик до " << counter.load() << "\n";

        // Передаём ход следующему потоку
        turn.store((id + 1) % 4);
    }
}

int main()
{
    setlocale(0, "ru");
    thread t0(work, 0);
    thread t1(work, 1);
    thread t2(work, 2);
    thread t3(work, 3);

    t0.join();
    t1.join();
    t2.join();
    t3.join();

    std::cout << "Итог counter = " << counter.load() << "\n";
}
