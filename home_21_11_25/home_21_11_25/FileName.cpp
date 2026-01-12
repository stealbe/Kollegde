#include <iostream>
#include <vector>
#include "Point.h"
#include <algorithm>
using namespace std;

int main() {
    vector<Point> graphic(20);
	for (size_t i = 0; i < graphic.size(); i++)
	{
		graphic.at(i).Init(rand() % 20, rand() % 20);
		cout << graphic[i] << endl;
	}
	vector<Point> vec2(20);
	for (auto ptr = graphic.begin(); ptr != graphic.end() && ptr - graphic.begin() < vec2.size(); ptr++)
	{
		vec2[ptr - graphic.begin()] = *ptr;
		cout << vec2[ptr - graphic.begin()] << endl;
	}
	vec2.erase(vec2.begin() + 2);
	vec2.push_back(Point(214, 532));
	sort(vec2.begin(), vec2.end());
    return 0;
}