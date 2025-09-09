#include <iostream>
using namespace std;

class Point
{
private:
	char name;
	int x;
	int y;
public:
	void Init(char n, int _x, int _y)
	{
		this->name = n;
		this->x = _x;
		this->y = _y;
	}
	void Print()
	{
		cout << this->name << " X: " << x << "\t Y: " << endl;
	}
	Point& AddX(int _x)
	{
		this->x += _x;
		return *this;
	}
};

int main()
{
	Point a;
	a.Init('A', 4, 5);
	a.Print();
	a = a.AddX(10);
	a.Print();
	
}