#include <iostream>
using namespace std;

//void Sum(int a, int b)
//{
//    cout << a + b << endl;
//}
//
//void Sum(double a, double b)
//{
//    cout << a + b << endl;
//}
//
//void Sum(char a, char b)
//{
//    cout << a + b << endl;
//}

template<class TypeA, class TypeB>
void Sum(TypeA a, TypeB b)
{
    cout << a + b << endl;
}



int main() {
    Sum(1, 2);
    Sum(3.3, 4.5);
    Sum('a', 'b');
    /*char* arr = new char[10] {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', '\0' };
    Sum(arr, arr);*/
    return 0;
}