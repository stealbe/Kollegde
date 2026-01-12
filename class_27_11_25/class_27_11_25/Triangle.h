#pragma once
#include <iostream>
using namespace std;
#include "Figure.h"

class Triangle :
    public Figure
{
public:
    void ShowArea() const { cout << "Square of triangle: " << 0.5 * m_value1 * m_value2 << endl; }
	void Init(double value1, double value2) { m_value1 = value1; m_value2 = value2; }
    void Print() const {
		cout << "Triangle: base = " << m_value1 << ", height = " << m_value2 << endl;
        }
    void ShowLength() const {
        double hypotenuse = sqrt(m_value1 * m_value1 + m_value2 * m_value2);
        cout << "Perimeter of triangle: " << (m_value1 + m_value2 + hypotenuse) << endl;
    }
    void ShowPerimeter() const {
        double hypotenuse = sqrt(m_value1 * m_value1 + m_value2 * m_value2);
        cout << "Perimeter of triangle: " << (m_value1 + m_value2 + hypotenuse) << endl;
	}
};