#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* Практика.
* Разделяемый ресурс - файл.
waitingThread() - реализует чтение из файла и вывод на консоль
signalingThread() - реализует запись данных в файл(запись строк в цикле)
*/

string fileName = "data.txt";
const int numIterations = 10;

mutex mtx;
bool ready = false;
condition_variable cv;


void waitingThread()
{
	unique_lock<mutex> lock(mtx);
	cv.wait(lock, [] { return ready; });
	ifstream readRes(fileName);
	if (readRes.is_open())
	{
		string line;
		getline(readRes, line);
			lock.unlock();
			cout << line << "\n";

		readRes.close();
	}
	else
	{
		cout << "Unable to open file for reading\n";
	}
}

void signalingThread(string stroke)
{
	for (int i = 0; i < numIterations; ++i)
	{
		{
			lock_guard<mutex> lock(mtx);
			ofstream writeRes(fileName);
			if (writeRes.is_open())
			{
				writeRes << stroke << "\n";
			}
			else {
				break;
			}
			writeRes.close();
		}
		cv.notify_one();
	}

	{
		std::lock_guard<std::mutex> lock(mtx);
		ready = true;
	}
	cv.notify_all();
}

int main2();


int main()
{
	/*ofstream clearFile(fileName, ios::trunc);
	clearFile.close();
	vector<thread> readThreads;
	for (int i = 0; i < numIterations;i++)
	{
		readThreads.push_back(thread(waitingThread));
	}
	thread t2(signalingThread, "Hello world!");

	for (auto& t : readThreads)
	{
		t.join();
	}
	t2.join();*/
	main2();
	return 0;
}

// --------------------------------------------------------------------

//using std::condition_variable;
//using std::ifstream;
//using std::mutex;
//using std::string;
//using std::lock_guard;
//using std::unique_lock;

//condition_variable cv;
//mutex mtx;

int* arr = nullptr;
string fileName2 = "input.txt";
int stokeCounter = 0;
bool finished = false;

void producer()
{
	ifstream readFile(fileName2);
	if (readFile.is_open())
	{
		string line;
		while (getline(readFile, line))
		{
			int number = stoi(line);
			{
				lock_guard<mutex> lock(mtx);
				arr[stokeCounter++] = number;
			}
			cv.notify_one();
		}
		readFile.close();
	}
	else
	{
		cout << "Unable to open file for reading\n";
	}
	{
		lock_guard<mutex> lock(mtx);
		finished = true;
	}
	cv.notify_all();
}

void consumer()
{
	while (true)
	{
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] { return stokeCounter > 0 || finished; });
		if (stokeCounter > 0)
		{
			int number = arr[--stokeCounter];
			lock.unlock();
			cout << "Square of " << number << " is " << number * number << "\n";
		}
		else if (finished)
		{
			break;
		}
	}
}

int main2()
{
	ifstream file(fileName2);
	int count = 0;
	std::string line;

	while (getline(file, line)) {
		count++;
	}
	file.close();
	arr = new int[count];
	thread producerThread(producer);
	thread consumerThread(consumer);
	producerThread.join();
	consumerThread.join();
	delete[] arr;
	return 0;
}

/*
**ЗАДАНИЕ 1:(продвинутый уровень)
«Потокобезопасная обработка данных из файла с использованием глобального массива»**
 Условие

Дан текстовый файл input.txt, содержащий N целых чисел (одно число в строке).
Создать глобальный массив int data[], размер которого равен количеству чисел в файле.

Написать две функции, выполняемые в потоках:
Поток 1 (producer — читатель):
*Открывает файл
*Последовательно читает числа
*Помещает их в глобальный массив
*После записи каждого числа отправляет сигнал другому потоку через std::condition_variable
*Завершает поток, установив глобальный флаг finished = true и уведомив все ожидающие потоки

Поток 2 (consumer — обработчик):
*Ожидает появления новых чисел в глобальном массиве
*Как только появляется новое число — выводит его квадрат
*Завершает работу, когда finished == true и новые элементы больше не поступают

 Требования

Не использовать using namespace std; (можно using std::cout и т.п.)
Использовать:

std::mutex
std::condition_variable
глобальный массив
файл

Обязательно использовать предикат в cv.wait()
*/