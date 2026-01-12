#include "RHome.h"
#include <iostream>
using namespace std;

void RHome::ShowArea() const
{
	cout << "Square of rhombus: " << m_value1 * m_value2 << endl;
}

void RHome::Init(double m_value1, double m_value2)
{
	this->m_value1 = m_value1;
	this->m_value2 = m_value2;
}

void RHome::Print() const
{
	cout << "a = " << m_value1 << "\th = " << m_value2 << endl;
}
