#include<iostream>
#include<time.h>
using namespace std;

class Test
{
	int temp;
	int temp2;
public:
	/*Test()
	{
		temp = 0;
	}*/
	Test(int t,int t2)
	{
		temp = t;
		temp2 = t2;
	}
	void Show()
	{
		cout << temp << endl;
	}
	int Gettemp()
	{
		return temp;
	}
};
class Point
{
	const int x;
	int y;
	int & z;
	Test obj;
public:
	
	Point(int x1, int y1,int z1,int t1,int t2):x(x1),z(z1),obj(t1,t2) // инициализаторы
	{
		cout << "Construct by 4 param\n";
		y = y1;

	}
	void Init()
	{
	//	x = rand() % 10;
		y = rand() % 10;
	}
	void Output()const
	{
		cout << "X: " << x << "\tY: " << y << endl;
	}
	int Getobj()
	{
		return obj.Gettemp();
	}
};

int main()
{
	srand(unsigned(time(0)));
	Point a(10,1,100,1000,8);
	Point b(20, 2,200,2000,9);
	cout << b.Getobj() << endl;
	


	a.Output();


	system("pause");
}