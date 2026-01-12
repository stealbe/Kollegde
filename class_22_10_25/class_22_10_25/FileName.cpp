#include <iostream>
#include "FileName.h"

using namespace std;

int main()
{
    cout << Foo<int>::s_count << endl;
    cout << Foo<double>::s_count << endl;
    cout << Foo<short>::s_count << endl;

    return 0;
}