#include "Point.h" // файл реализации
#include<iostream>
using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
	count++;
}
Point::Point(int a, int b)
{
	x = a;
	y = b;
	count++;
}
void Point::Init(int a, int b)
{
	x = a;
	y = b;
}
void Point::Init()
{
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
}
void Point::Print()
{
	cout << "X: " << x << "\tY: " << y << endl;
}

int Point::Count()
{
	return count;
}

Point Point::operator+(Point& obj)
{
	Point p(x + obj.x, y + obj.y);
	return p;
}

Point Point::operator+(int n)
{
	return Point (x + n, y + n);
}

Point Point::operator-(Point& obj)
{
	return Point (x - obj.x, y - obj.y);
}

Point Point::operator-(int n)
{
	return Point(x - n, y - n);
}

Point Point::operator%(Point& obj)
{
	return Point(x % obj.x, y & obj.y);
}

Point Point::operator%(int n)
{
	return Point(x & n, y & n);
}

bool Point::operator==(Point& obj)
{
	return (x == obj.x && y == obj.y);
}

bool Point::operator!=(Point& obj)
{
	return !(*this == obj);
}

bool Point::operator>(Point& obj)
{
	return (x+y > obj.x + obj.y);
}

bool Point::operator<(Point& obj)
{
	return (x + y < obj.x + obj.y);
}

bool Point::operator>=(Point& obj)
{
	return !(*this < obj);
}

bool Point::operator<=(Point& obj)
{
	return !(*this > obj);
}

Point& Point::operator++()
{
	++x;
	++y;
	return *this;
}

Point Point::operator++(int)
{
	Point temp = *this;
	x++;
	y++;
	return temp;
}

Point& Point::operator--()
{
	--x;
	--y;
	return *this;
}

Point Point::operator--(int)
{
	Point temp = *this;
	x++;
	y++;
	return temp;
}

int Point::count = 0; // начальная инициализация статик поля
