#pragma once

#include "Figure.h"

class Circle :
    public Figure
{
public:

    void ShowArea() const;

    virtual ~Circle()
    {
        cout << "Hello from Circle" << endl;
    }
};