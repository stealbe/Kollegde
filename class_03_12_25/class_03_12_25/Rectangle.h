#pragma once
#include <iostream>
using namespace std;
#include "Figure.h"

class Rectangle :
    public Figure
{
public:
    void ShowArea() const
    {
        cout << "Square of rectangle: " << m_value1 * m_value2 << endl;
    }
    void ShowLength() const { cout << "a = " << m_value2 << endl; }
    void Init(double m_value1, double m_value2) { this->m_value1 = m_value1; this->m_value2 = m_value2; }
    void Print() const { cout << "a = " << m_value1 << "\tb = " << m_value2 << endl; }
	void ShowPerimeter() const { cout << "Perimeter of rectangle: " << 2 * (m_value1 + m_value2) << endl; }
    void PrintFile() const override
    {
        ostream& outFile = cout;
        outFile << "Rectangle: a = " << m_value1 << "\tb = " << m_value2 << endl;
    }
    void PrintConsole() const override
    {
        cout << "Rectangle: a = " << m_value1 << "\tb = " << m_value2 << endl;
	}
};