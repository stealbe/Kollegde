#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>

using std::cout;
using std::mutex;
using std::condition_variable;
using std:: unique_lock;
using std::thread;

mutex m;
condition_variable cv;

bool go = false;

void worker(int id)
{
  unique_lock<mutex> lock(m);

    cv.wait(lock, [] { return go; }); // Ждём, пока go станет true
    // Все дошедшие сюда увидят go == true (после захвата мьютекса)
    cout << "Worker " << id << " proceeds\n";
}
int main() 
{
    std::vector<std::thread> pool;
    for (int i = 0; i < 3; ++i)
    {
        pool.push_back(thread(worker, i));
    }

    {
        std::lock_guard<std::mutex> lock(m);
        go = true; // Разрешаем всем продолжить
    }

    // Если используем notify_one(), проснётся только один поток,
    // остальные продолжат спать, пока снова не получится notify_*.
   // cv.notify_one();

    // Если используем notify_all(), проснутся все ожидающие потоки.
     cv.notify_all();
   

    for (auto& t : pool)
    {
        t.join();
    }

    cout << "End main\n";

}