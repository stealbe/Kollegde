#pragma once

class Figure
{
protected:

    double m_value1;
    double m_value2;

public:

    virtual void SetDimension(const double value1) = 0;
    virtual void SetDimension(const double value1, const double value2) = 0;
    virtual void ShowArea() const = 0;
};