#pragma once
#include <iostream>
using namespace std;

class Figure
{
protected:

    double m_value1;
    double m_value2;

public:
	Figure() : m_value1(0), m_value2(0) {}
    void SetDimension(const double value1);
    void SetDimension(const double value1, const double value2);
    virtual void ShowArea() const;
    virtual void ShowLength() const { cout << "value 2 = " << m_value2 << endl; }
    virtual void Init(double m_value1, double m_value2)
    {
        this->m_value1 = m_value1;
        this->m_value2 = m_value2;
    }
    virtual void Print() const { cout << "value 1 = " << m_value1 << "\tvalue 2 = " << m_value2 << endl; }
};