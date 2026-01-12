#pragma once

#include "Figure.h"
#include <iostream>
using namespace std;

class Circle :
    public Figure
{
public:
    void ShowArea() const { cout << "Square of circle: " << 3.14159 * m_value1 * m_value2 << endl; }
    void ShowLength() const { cout << "d = " << 2 * m_value1 << endl; }
    void Init(double m_value1) { this->m_value1 = m_value1; }
    void Print() const { cout << "r = " << m_value1 << endl; }
	void ShowPerimeter() const { cout << "Perimeter of circle: " << 2 * 3.14159 * m_value1 << endl; }
	void PrintFile() const override
    {
		ostream& outFile = cout;
		outFile << "Circle: r = " << m_value1 << endl;
    }
    void PrintConsole() const override
    {
        cout << "Circle: r = " << m_value1 << endl;
    }
};