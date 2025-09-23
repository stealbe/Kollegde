#include "MStr.h"
#include <iostream>
using namespace std;

MStr::MStr()
{
	length = 80;
	str = new char[length];
	count++;
}

MStr::MStr(int size)
{
	length = size;
	str = new char[length];
	count++;
}

MStr::MStr(const char* _str)
{
	length = strlen(_str);
	str = new char[length + 1];
	strcpy_s(str, length + 1, _str);
	count++;
}

MStr::MStr(const MStr& _str)
{
	length = _str.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, _str.str);
	count++;
}

MStr::MStr(MStr&& _str)
{
	str = _str.str;
	_str.str = nullptr;
	length = _str.length;
	_str.length = 0;
	count++;
}

MStr::~MStr()
{
	count--;
	delete[] str;
}

void MStr::Cpy(const MStr& st)
{
	if (str != nullptr) delete[] str;
	length = st.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, st.str);
}

bool MStr::StrStr(const char* st)
{
	char* temp = strstr(str, st);
	if (temp != nullptr) return true;
	return false;
}

void MStr::Print()
{
	cout << str << endl;
}

int MStr::Len()
{
	return strlen(str);
}

void MStr::Inp(const char* st)
{
	if (str != nullptr) delete[] str;
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
}

int MStr::StrChr(char chr)
{
	for (size_t i = 0; i < length + 1; i++)
	{
		if (str[i] == chr) return i;
	}
	return -1;
}

void MStr::Cat(MStr& b)
{
	char* newStr = new char[length + b.length + 1];
	strcpy_s(newStr, length + 1, str);
	for (size_t i = 0; i < b.length; i++)
		newStr[length + i] = b.str[i];

	newStr[length + b.length] = '\0';
	delete[] str;
	str = newStr;
	length += b.length;
}

void MStr::DelChr(char chr)
{
	MStr temp(length);
	int j = 0;
	for (size_t i = 0; i < length - 1; i++)
	{
		if (str[i] != chr) temp.str[j++] = str[i];
	}
	temp.str[j] = '\0';
 	Inp(temp.str);
}

int MStr::StrCmp(MStr& b)
{
	return (length != b.length ? (length > b.length ? 1 : -1) : 0);
}

int MStr::Count()
{
	return count;
}

int MStr::count = 0;