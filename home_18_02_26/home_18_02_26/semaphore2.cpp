#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <semaphore>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::thread;
using std::ofstream;

class Car
{
private:
    string model;
    string plates;
public:
    Car(string model, string plates) { model = model; plates = plates; }
    void nearParck() { cout << "Car near parcking" << endl; }
};

/*
* Задание 1.
Реализация в ООП!! 
Создать класс Car
Вместо ИД, название и гос номер.

Реализуйте модель парковки с ограниченным количеством мест.
На парковке всего 3 места. Несколько машин (потоков) пытаются припарковаться.
Каждая машина должна:

«Подъехать» к парковке (вывести сообщение).
Ждать свободного места, если парковка занята.
Припарковаться, заняв одно место.
Постять на парковке некоторое фиксированное время (например, 1 секунду).
Уехать, освободив место.
Разбудить одну из ожидающих машин.

Количество машин (потоков) — не менее 6.
Вывод программы должен ясно показывать, что одновременно припарковано не более трёх машин.

-------------------------------------------------------------
Задание 2.
Создайте программу, в которой:
Есть один текстовый файл (например, log.txt).
Есть несколько потоков (не меньше 6).

Каждый поток должен:

начать работу и вывести сообщение;
попытаться записать свою строку в файл;
но доступ к файлу ограничен семафором на 2 пропуска
(то есть одновременно в файл могут писать только 2 потока).


Поток, получивший доступ, записывает строку вида:
 "Поток X записал данные"
После записи поток освобождает место в семафоре.

Файл должен корректно показывать записи, без перемешивания и обрывов.

Задание 3
Создайте программу, в которой:

Есть глобальный массив из 20 элементов (например int data[20];), изначально заполненный нулями.

Есть несколько потоков (например 5).

Каждый поток должен:
получить «разрешение» от семафора (например на 2 пропуска),
найти первый нулевой элемент массива,
записать туда номер потока (или любое своё значение),
освободить разрешение семафора.

Работа продолжается, пока весь массив не будет заполнен.

После завершения работы программа выводит массив.

Важно:
Необходимо предотвратить ситуацию, когда два потока одновременно пытаются записать в один и тот же индекс.
*/
std::counting_semaphore<3> parking(3);
// 3 свободных места на парковке

void car(int id) {
    using namespace std::chrono;

    std::cout << "Машина " << id << " подъехала и пытается припарковаться...\n";

    // Ожидание свободного места, если мест нет — поток блокируется
    parking.acquire();
    std::cout << "Машина " << id << " припарковалась.\n";

    // Машина стоит на парковке фиксированное время
    std::this_thread::sleep_for(seconds(1));

    std::cout << "Машина " << id << " уехала.\n";
    parking.release(); // освобождение места
}

string fileName = "log.txt";
const int thCount = 6;
std::counting_semaphore<2> logFile(2);

string thStroke(int n) { return ("Поток " + std::to_string(n) + " записал данные"); }

void logToFile(string stroke)
{
    ofstream file(fileName, std::ios::app);
    cout << stroke << endl;
    logFile.acquire();
    file << stroke << "\n";
    logFile.release();
    file.close();
}

//3

int arr[20];
std::counting_semaphore<2> writeToArr(2);

void initArr(int n) {
    writeToArr.acquire();
    for (size_t i = 0; i < 20; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = n;
            break;
        }

    }
    writeToArr.release();
}

int main() {
    setlocale(0, "ru");
    //std::vector<std::thread> cars;

    //// Пусть подъедут 6 машин
    //for (int i = 1; i <= 6; ++i) {
    //    cars.emplace_back(car, i);
    //}

    //for (auto& t : cars) t.join();

    //std::cout << "Парковка свободна. Все машины обработаны.\n";

    ofstream clearFile(fileName, std::ios::trunc);
    clearFile.close();

    vector<thread> logs;
    for (size_t i = 1; i <= thCount; i++)
    {
        logs.emplace_back(logToFile, thStroke(i));
    }

    for (auto& n : logs) n.join();

    for (size_t i = 0; i < 20; i++)
    {
        arr[i] = 0;
    }

    // 3

    for (size_t i = 0; i < 4; i++)
    {
        vector<thread> arrWriters;

        for (size_t i = 1; i <= 5; i++)
        {
            arrWriters.emplace_back(initArr, i);
        }

        for (auto& n : arrWriters) n.join();
    }

    for (auto& i : arr) cout << i << "\n";

    return 0;
}
/*
Одновременно паркуются не более 3 машин, потому что семафор ограничивает доступ.
Остальные автомобили ожидают, пока кто‑то не вызовет parking.release().
Логика потоков полностью детерминирована, нет случайных задержек.
*/

