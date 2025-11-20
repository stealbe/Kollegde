#include "Square.h"
#include <iostream>
using namespace std;

void Square::ShowArea() const
{
	cout << "Square of square: " << m_value1 * m_value1 << endl;
}

void Square::Print() const
{
	cout << "a = " << m_value1 << endl;
}
