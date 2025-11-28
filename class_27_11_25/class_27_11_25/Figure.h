#pragma once

class Figure
{
protected:

    double m_value1;
    double m_value2;

public:
	Figure() : m_value1(0), m_value2(0) {}
    void SetDimension(const double value1) { m_value1 = value1; }
	void SetDimension(const double value1, const double value2) { m_value1 = value1; m_value2 = value2; }
    virtual void ShowArea() const = 0;
	virtual void Init(double value1, double value2) = 0;
	virtual void Print() const = 0;
	virtual void ShowLength() const = 0;
	virtual void ShowPerimeter() const = 0;
};