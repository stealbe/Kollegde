#include <iostream>
#include <string>
#include <map>
using namespace std;

// для сокращения записи вводим обозначение:
typedef map<int, string> MyMap;
typedef MyMap::iterator Iter;

void main()
{
	// начальная инициализация map
	MyMap m;
	// использование value_type для формирования пары "ключ - значение"
	m.insert(MyMap::value_type(1, "Ivanov"));
	// можно непосредственно использовать тип pair
	m.insert(pair<int, string>(2, "Petrov"));
	// использование функции make_pair
	m.insert(make_pair(3, "Sidorov"));

	for(Iter it = m.begin(); it != m.end(); it++)
	{
		// использование свойств итератора:
		// first для обращения к ключу,
		// second для обращения к значению
		cout << it->first << " " << it->second << endl;
	}
}
