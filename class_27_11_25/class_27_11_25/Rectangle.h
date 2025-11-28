#pragma once
#include <iostream>
using namespace std;
#include "Figure.h"

class Rectangle :
    public Figure
{
public:
    void ShowArea() const { cout << "Square of rectangle: " << m_value1 * m_value2 << endl; }
	void Init(double value1, double value2) { m_value1 = value1; m_value2 = value2; }
    void Print() const {
        cout << "Rectangle: length = " << m_value1 << ", width = " << m_value2 << endl;
        }
    void ShowLength() const {
        cout << "Length of rectangle: " << 2 * (m_value1 + m_value2) << endl;
	}
    void ShowPerimeter() const {
        cout << "Perimeter of rectangle: " << 2 * (m_value1 + m_value2) << endl;
	}
};