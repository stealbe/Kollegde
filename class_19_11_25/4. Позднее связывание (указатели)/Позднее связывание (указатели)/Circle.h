#pragma once
#include <iostream>
using namespace std;
#include "Figure.h"

class Circle :
    public Figure
{
public:

    virtual void ShowArea() const
    {
        cout << "Square of circle: " << 3.14159 * m_value1 * m_value2 << endl;
    }
};