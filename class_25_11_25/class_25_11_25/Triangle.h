#pragma once

#include "Figure.h"

class Triangle :
    public Figure
{
public:
    void ShowArea() const;
    void ShowLength() const { cout << "h = " << m_value2 << endl; }
    void Init(double m_value1, double m_value2) { this->m_value1 = m_value1; this->m_value2 = m_value2; }
    void Print() const { cout << "a = " << m_value1 << "\th = " << m_value2 << endl; }
};