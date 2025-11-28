#pragma once
#include "Figure.h"
#include <iostream>
using namespace std;

class Square : public Figure
{
public:
	void ShowArea() const { cout << "Square of square: " << m_value1 * m_value1 << endl; }
    void ShowLength() const { cout << m_value1 << endl; }
	void Init(double m_value1, double value2) { this->m_value1 = m_value1; this->m_value2 = value2; }
	void Print() const { cout << "a = " << m_value1 << endl; }
	void ShowPerimeter() const { cout << "Perimeter of square: " << 4 * m_value1 << endl; }
};