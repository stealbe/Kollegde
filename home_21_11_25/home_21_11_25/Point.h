#pragma once// файл дизайна
#include <iostream>
using namespace std;

class Point
{ 
	// реализация класса
	int x;
	int y;
	static int count; // создаем статическое поле
	friend ostream& operator<< (ostream& os, Point& obj);

public:// интерфейс класса, прототипы методов
	Point();
	Point(int a, int b);
	void Init(int a, int b);
	void Init();  // ввод с клавиатуры
	void Print();
	static int Count();
	Point operator+ (Point& obj);
	Point operator+ (int n);
	Point operator- (Point& obj);
	Point operator- (int n);
	Point operator% (Point& obj);
	Point operator% (int n);
	Point& operator= (Point& obj);
	bool operator== (Point& obj);
	bool operator!= (Point& obj);
	bool operator> (Point& obj);
	bool operator< (Point& obj);
	bool operator>= (Point& obj);
	bool operator<= (Point& obj);
	Point& operator++ ();
	Point operator++ (int);
	Point& operator-- ();
	Point operator-- (int);
};

inline ostream& operator<<(ostream& os, Point& obj)
{
	os << "x: " << obj.x << "\ty: " << obj.y << endl;
	return os;
}