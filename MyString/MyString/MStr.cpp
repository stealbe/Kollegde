#include "MStr.h"
#include <iostream>
using namespace std;

MStr::MStr()
{
	length = 80;
	str = new char[length];
	count++;
}

MStr::MStr(size_t size)
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

MStr::MStr(MStr&& _str) noexcept
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

size_t MStr::Len()
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
	for (int i = 0; i < length + 1; i++)
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

MStr MStr::operator+(MStr& obj)
{
	MStr obj(this->str);
	obj.Cat(obj);
	return obj;
}

MStr MStr::operator+(const char* str)
{
	MStr obj(this->str);
	MStr temp(str);
	obj.Cat(temp);
	return obj;
}

MStr MStr::operator+(const char chr)
{
	char* tempStr = new char[length + 2];
	strcpy_s(tempStr, length + 2, str);
	tempStr[length] = chr;
	tempStr[length + 1] = '\0';
	MStr obj(tempStr);
	return obj;
}


// Либо удалять если найдены к ряду все совпадения посимвольно
MStr MStr::operator-(const char* str)
{
	size_t temp_len = strlen(str);
	char* chr_f = strstr(this->str, str);
	if (chr_f == nullptr) return MStr(this->str);
	size_t pos = chr_f - this->str;
	size_t new_len = length - temp_len;
	char* tempStr = new char[new_len + 1];
	
	strncpy_s(tempStr, new_len + 1, this->str, pos);
	strcpy_s(tempStr + pos, new_len - pos + 1, this->str + pos + temp_len);

	return MStr(tempStr);
}

bool MStr::operator==(MStr& obj)
{
	return strcmp(this->str, obj.str) == 0;
}

bool MStr::operator!=(MStr& obj)
{
	return !(*this == obj);
}

bool MStr::operator>(MStr& obj)
{
	return strcmp(this->str, obj.str) == 1;
}

bool MStr::operator<(MStr& obj)
{
	return strcmp(this->str, obj.str) == -1;
}

bool MStr::operator>=(MStr& obj)
{
	return !(*this < obj);
}

bool MStr::operator<=(MStr& obj)
{
	return !(*this > obj);
}

bool MStr::operator==(const char* str)
{
	return strcmp(this->str, str) == 0;
}

bool MStr::operator!=(const char* str)
{
	return !(*this == str);
}

bool MStr::operator>(const char* str)
{
	return strcmp(this->str, str) == 1;
}

bool MStr::operator<(const char* str)
{
	return strcmp(this->str, str) == -1;
}

bool MStr::operator>=(const char* str)
{
	return !(*this < str);
}

bool MStr::operator<=(const char* str)
{
	return !(*this > str);
}

bool MStr::operator==(const int len)
{
	return (this->length == len);
}

bool MStr::operator!=(const int len)
{
	return !(*this == len);
}

bool MStr::operator>(const int len)
{
	return (this->length > len);
}

bool MStr::operator<(const int len)
{
	return (this->length < len);
}

bool MStr::operator>=(const int len)
{
	return !(*this < len);
}

bool MStr::operator<=(const int len)
{
	return !(*this > len);
}

//MStr MStr::operator-(const char* str)
//{
//	size_t temp_len = strlen(str);
//	if (temp_len > length) temp_len = length;
//
//	char* tempStr = new char[length - temp_len + 1];
//	strncpy_s(tempStr, length - temp_len + 1, this->str, length - temp_len);
//	tempStr[length - temp_len] = '\0';
//	MStr obj(tempStr);
//	return obj;
//}

int MStr::count = 0;