#include <iostream>
#include "Matrix.h"
using namespace std;

class Point
{
    int x;
    int y;
    friend istream& operator>> (istream& os, Point& obj);
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    template<class T> Point operator=(T n);
    template<class T> Point operator+(T n);
    template<class T> Point operator-(T n);
    template<class T> Point operator*(T n);
    template<class T> Point operator/(T n);

    Point& operator= (const Point& obj)
    {
        if (this == &obj) return *this;
        x = obj.x;
        y = obj.y;
        return *this;
    }

    Point operator+ (Point& obj) const
    {
        return Point(x + obj.x, y + obj.y);
    }
    
    Point operator- (Point& obj) const
    {
        return Point(x - obj.x, y - obj.y);
    }
    
    Point operator* (Point& obj) const
    {
        return Point(x * obj.x, y * obj.y);
    }
    
    Point operator/ (Point& obj) const
    {
        return Point(x / obj.x, y / obj.y);
    }
    int GetX() { return this->x; }
    int GetY() { return this->y; }
};

ostream& operator<< (ostream& os, Point& obj)
{
    os << "(" << obj.GetX() << "; " << obj.GetY() << ")";
    return os;
}

istream& operator>> (istream& is, Point& obj)
{
    int a;
    int b;
    is >> a;
    obj.x = a;
    is >> b;
    obj.y = b;
    return is;
}

int main() {
    //Matrix<> mat(3, 5);
    //mat.Print();
    //mat.FillCin();
    //mat.Print();
    //mat.MaxE();
    //mat.MinE();
    //Matrix<> mat1(3, 5);
    //Matrix<> mat2 = mat + mat1;
    //mat2.Print();
    //mat2 = mat - mat1;

    // home - 23_10_25

    Matrix<Point> obj1(2, 4);
    obj1.FillRandom();
    obj1.Print();

    return 0;
}

template<class T>
Point Point::operator=(T n)
{
    x = n;
    y = n;
    return *this;
}

template<class T>
Point Point::operator+(T n)
{
    return Point(x + n, y + n);
}

template<class T>
Point Point::operator-(T n)
{
    return Point(x - n, y - n);
}

template<class T>
Point Point::operator*(T n)
{
    return Point(x * n, y * n);
}

template<class T>
Point Point::operator/(T n)
{
    return Point(x / n, y / n);
}
