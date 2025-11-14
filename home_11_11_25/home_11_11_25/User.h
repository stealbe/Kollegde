#pragma once
#include <iostream>
//#include "Book.h"
using namespace std;

class Book;

class User
{
private:
	int id;
	string name;
	Book* library;
	int lib_size;
	int frequency;
	static int count;

	friend ostream& operator<< (ostream& os, const User& obj);
	friend istream& operator>> (istream& is, User& obj);
public:
	User() : name(""), lib_size(0), library(nullptr), id(count++), frequency(1) {};
	User(string name, const Book* library = nullptr, const int size = 0, int frequency = 1);
	User(string name, Book& book, int frequency = 1);
	User(const User& obj);
	/*User(User&& obj);*/
	Book* GetLib() { return this->library; };
	int GetId() { return this->id; };
	string GetName() { return this->name; };
	int GetFreq() { return this->frequency; };
	int GetLibSize() { return this->lib_size; };
	void AddBook(Book& obj);
	void RemoveBook(int id);

	User& operator= (const User& obj);
	~User();

};