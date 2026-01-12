#pragma once
#include <iostream>
//#include "User.h"
using namespace std;

class User;

class Book
{
private:
	int id;
	string name;
	string authtor;
	string genre;
	bool is_avalible;
	User* owner;
	static int count;
	friend ostream& operator<< (ostream& os, const Book& obj);
	friend istream& operator>> (istream& is, Book& obj);
public:
	Book();
	Book(string name, string authtor, string genre);
	void SetOwner(User* smb);
	User* GetOwer() { return this->owner; };
	void RemoveOwner();
	void SetAvalible(bool is_avalible);
	int GetId() { return this->id; };
	bool IsAvalible() { return this->is_avalible; };
	string GetAuthtor() { return this->authtor; };
	string GetName() { return this->name; };
	string GetGenre() {	return this->genre;};

	Book& operator= (const Book& obj);
};