#include <iostream>
#include <time.h>
#include "MVector.h"

using namespace std;

int main() {
    srand(time(NULL));

    MVector vec1(10);
    vec1.Init();

    for (int i = 0; i < vec1.GetSize(); i++)
    {
        cout << vec1[i] << endl;
    }

    return 0;
}