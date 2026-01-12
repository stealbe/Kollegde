#include <iostream>
#include <time.h>
#include "MVector.h"

using namespace std;

MVector operator+ (int n, MVector& obj)
{
    MVector res(obj);
    for (size_t i = 0; i < obj.GetSize() + 1; i++)
    {
        res.SetIndex(i, res.GetIndex(i) + n);
    }
    return res;
}

MVector& operator-- (MVector& obj)
{
    int nSize = obj.GetSize() - 1;
    int* nArr = new int[nSize + 1];
    for (size_t i = 1; i < nSize + 2; i++)
    {
        nArr[i - 1] = obj.GetIndex(i);
    }
    obj.Init(nArr, nSize);
    return obj;
}

ostream& operator<< (ostream& os, MVector& obj)
{
    for (size_t i = 0; i < obj.GetSize(); i++)
    {
        os << obj.GetIndex(i);
    }
    os << endl;
    return os;
}

istream& operator>> (istream& is, MVector& obj)
{
    int iSize;
    cout << "size: ";
    is >> iSize;
    int* iArr = new int[iSize];
    cout << "Array of " << iSize << " nums: ";
    for (size_t i = 0; i < iSize; i++)
    {
        cout << "Num " << i + 1 << ": ";
        int n;
        is >> n;
        iArr[i] = n;
    }
    obj.Init(iArr, iSize);
    return is;
}


int main() {
    srand(time(NULL));

    MVector vec1(10);
    vec1.Init();
    vec1.Print();
    cout << endl;
    cout << vec1 << endl;

    MVector vec2 = --vec1;
    //vec2 = 10 + vec2;

    cout << vec2 << endl;
    MVector vec_t;
    cin >> vec_t;
    cout << vec_t << endl;
    return 0;
}