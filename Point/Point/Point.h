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
};

