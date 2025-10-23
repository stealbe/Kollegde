#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix<> mat(3, 5);
    mat.Print();
    mat.FillCin();
    mat.Print();
    mat.MaxE();
    mat.MinE();
    Matrix<> mat1(3, 5);
    Matrix<> mat2 = mat + mat1;
    mat2.Print();
    mat2 = mat - mat1;
    return 0;
}