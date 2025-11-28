#pragma once

#include "Figure.h"

class Circle :
    public Figure
{
public:
    void SetDimension(const double value1)
    {
        SetDimension(value1, value1);
    }

    void SetDimension(const double value1, const double value2)
    {
        m_value1 = value1;
        m_value2 = value2;
    }
    virtual void ShowArea() const;
};