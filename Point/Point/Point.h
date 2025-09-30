#pragma once// ���� �������
class Point
{ 
	// ���������� ������
	int x;
	int y;
	static int count; // ������� ����������� ����

public:// ��������� ������, ��������� �������
	Point();
	Point(int a, int b);
	void Init(int a, int b);
	void Init();  // ���� � ����������
	void Print();
	static int Count();
	Point operator+ (Point& obj);
	Point operator+ (int n);
	Point operator- (Point& obj);
	Point operator- (int n);
	Point operator% (Point& obj);
	Point operator% (int n);
};

