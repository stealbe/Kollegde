#pragma once

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
};