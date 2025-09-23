#pragma once// файл дизайна
class Point
{ 
	// реализация класса
	int x;
	int y;
	static int count; // создаем статическое поле

public:// интерфейс класса, прототипы методов
	Point();
	Point(int a, int b);
	void Init(int a, int b);
	void Init();  // ввод с клавиатуры
	void Print();
	static int Count();
};

