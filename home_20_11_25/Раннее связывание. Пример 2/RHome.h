#pragma once
#include "Figure.h"

class RHome : public Figure
{
public:
    void ShowArea() const;
    void ShowLength() const { cout << "h = " << m_value2 << endl; }
    void Init(double m_value1, double m_value2);
    void Print() const;
};