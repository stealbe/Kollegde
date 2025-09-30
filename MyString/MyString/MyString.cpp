#include <iostream>
#include "MStr.h"
using namespace std;

int main() {
    MStr obj("Hello world");
    MStr obj2("Test");
    MStr rez = obj + obj2;
    rez.Print();
    MStr rez2 = obj + "!!!";
    rez2.Print();
    MStr rez3 = obj + '?';
    rez3.Print();
    MStr rez4 = obj - "world";
    rez4.Print();
}