#pragma once

#include "Figure.h"

class Triangle :
    public Figure
{
public:

    void ShowArea() const;

    virtual ~Triangle()
    {
        cout << "Hello from Triangle" << endl;
    }
};