#pragma once

#include "Figure.h"

class Circle :
    public Figure
{
public:
    void ShowArea() const;
    void ShowLength() const { cout << "d = " << m_value1 << endl; }
    void Init(double m_value1) { this->m_value1 = m_value1; }
    void Print() const { cout << "d = " << m_value1 << endl; }
};