#pragma once

#include "Figure.h"

class Triangle :
    public Figure
{
public:
    void ShowArea() const
    {
        cout << "Square of triangle: " << 0.5 * m_value1 * m_value2 << endl;
    }
    void ShowLength() const { cout << "h = " << m_value2 << endl; }
    void Init(double m_value1, double m_value2) { this->m_value1 = m_value1; this->m_value2 = m_value2; }
    void Print() const { cout << "a = " << m_value1 << "\th = " << m_value2 << endl; }
	void ShowPerimeter() const { cout << "Perimeter of triangle: " << 3 * m_value1 << endl; }
    void PrintFile() const override
    {
        ostream& outFile = cout;
        outFile << "Triangle: a = " << m_value1 << "\th = " << m_value2 << endl;
    }
    void PrintConsole() const override
    {
        cout << "Triangle: a = " << m_value1 << "\th = " << m_value2 << endl;
	}
};