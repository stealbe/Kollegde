#include <iostream>
#include <string>
#include <map>
using namespace std;

// для сокращения записи вводим обозначение
typedef multimap<char, string> MyMap;
typedef MyMap::iterator Iter;

void main()
{
   // карта в качестве ключей использует названия нот, а в качестве значений - их частоты
	map<string, int> Tones;
	Tones["Do"] = 523;
	Tones["Re"] = 587;
	Tones["Mi"] = 659;
	Tones["Fa"] = 698;
	Tones["Sol"] = 783;
	Tones["La"] = 879;
	Tones["Si"] = 987;
	map<string, int>::iterator it;
	for(it = Tones.begin(); it != Tones.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}
	cout << Tones["Si#"] << endl; // ошибки не возникает - выводится значение по умолчанию
}