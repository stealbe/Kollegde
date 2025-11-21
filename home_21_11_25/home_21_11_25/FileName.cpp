#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

int main() {
    vector<Point> graphic(20);
	for (size_t i = 0; i < graphic.size(); i++)
	{
		graphic.at(i).Init(rand() % 20, rand() % 20);
		cout << graphic[i] << endl;
	}
    return 0;
}