#pragma once
#include "Figure.h"

class Square : public Figure
{
public:
    void ShowArea() const;
    void ShowLength() const { cout << m_value1 << endl; }
    void Init(double m_value1) { this->m_value1 = m_value1; };
    void Print() const;
	void ShowPerimeter() const { cout << "Perimeter of square: " << 4 * m_value1 << endl; }
};