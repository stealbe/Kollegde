#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix<> mat(3, 5);
    mat.Print();
    mat.FillCin();
    mat.Print();
    return 0;
}