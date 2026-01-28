#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

const int arrSize = 20;
int arr[arrSize];
atomic<int> counter = { 0 };

void fillArray(const int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 41 - 20;
	}
}

void evenCount(const int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] % 2 == 0)
		{
			counter++;
		}
	}
}

void negativeCount(const int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < 0)
		{
			counter++;
		}
	}
}

int main()
{
	srand(unsigned int(time(0)));
	fillArray(arrSize);
	thread t1(evenCount, arrSize);
	thread t2(negativeCount, arrSize);
	t1.join();
	t2.join();
	cout << "Total count of even and negative numbers: " << counter.load() << endl;
	return 0;
}