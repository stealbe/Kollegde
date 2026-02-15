#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <iostream>

std::mutex m;
std::condition_variable cv;
std::queue<int> q;     // Общая очередь задач

bool finished = false; // Признак, что производитель завершил работу

void producer() 
{
    for (int i = 0; i < 10; ++i)
    {
        {
            std::lock_guard<std::mutex> lock(m);
            q.push(i);                 // Кладём элемент под защитой мьютекса
        } // Выходим из критической секции как можно раньше
        cv.notify_one();               // Будим одного потребителя — работы стало больше
    }

    // Сигналим о завершении производства
    {
        std::lock_guard<std::mutex> lock(m);
        finished = true;               // Меняем состояние под мьютексом
    }
    cv.notify_all();                   // Будим всех: кто-то может ждать пустую очередь
}

void consumer(int id) {

    for (;;) 
    {
        std::unique_lock<std::mutex> lock(m);

        // Ждём, пока либо появятся элементы, либо всё окончательно завершится
        cv.wait(lock, [] { return !q.empty() || finished; });

        if (!q.empty()) {
            // Забираем элемент работы
            int v = q.front();
            q.pop();

            // Выходим из критической секции до "тяжёлой" обработки
            lock.unlock();

            // Обработка вне мьютекса — это уменьшает блокировки для других потоков
            std::cout << "Consumer " << id << " got " << v << "\n";
        }
        else if (finished) {
            // Работ больше не будет, корректно выходим
            break;
        }
    }
}

int main() {
    std::thread p(producer);

    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);
    std::thread c3(consumer, 3);
    std::thread c4(consumer, 4);

    p.join();
    c1.join();
    c2.join();
    c3.join();
    c4.join();
}

/*
* producer - записывает 1 строку в файл
* consumer - сразу считывает и выводин на консоль, после чего освобождает место в файле(строку удаляет из файла)
  и так до того момента, пока есть строки...


*/