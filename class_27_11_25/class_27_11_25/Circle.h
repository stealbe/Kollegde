#pragma once
#include <iostream>
using namespace std;
#include "Figure.h"

class Circle :
    public Figure
{
public:
    void ShowArea() const { cout << "Square of circle: " << 3.14159 * m_value1 * m_value2 << endl; }
	void Init(double value1, double value2) { m_value1 = value1; m_value2 = value2; }
    void Print() const {
        cout << "Circle: radius = " << m_value1 << endl;
	}
    void ShowLength() const {
        cout << "Length of circle: " << 2 * 3.14 * m_value1 << endl;
	}
    void ShowPerimeter() const {
        cout << "Perimeter of circle: " << 2 * 3.14 * m_value1 << endl;
	}
};