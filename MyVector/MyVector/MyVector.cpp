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


int main() {
    srand(time(NULL));

    MVector vec1(10);
    vec1.Init();

    for (int i = 0; i < vec1.GetSize(); i++)
    {
        cout << vec1[i] << endl;
    }

    return 0;

    MVector vec2 = --vec1;
    vec2.Print();
}