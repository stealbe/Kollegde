#include "Book.h"
#include "User.h"

int Book::count = 0;

Book::Book()
{
	this->name = "";
	this->authtor = "";
	this->genre = "";
	this->id = count++;
	this->is_avalible = true;
	this->owner = nullptr;
}

Book::Book(string name, string authtor, string genre)
{
	this->id = count++;
	this->name = name;
	this->authtor = authtor;
	this->genre = genre;
	this->is_avalible = true;
	this->owner = nullptr;
}

void Book::SetOwner(User* smb)
{
	if (id < 0) throw "owner id can't be < 0";
	this->owner = smb;
	this->is_avalible = false;
}

void Book::RemoveOwner()
{
	this->owner = nullptr;
	this->is_avalible = true;
}

void Book::SetAvalible(bool is_avalible)
{
	if (this->is_avalible == is_avalible) throw this->is_avalible ? "Book already avalible" : "Book already not avalible";
	this->is_avalible = is_avalible;
}

Book& Book::operator=(const Book& obj)
{
	if (this == &obj) return *this;
	this->id = obj.id;
	this->name = obj.name;
	this->authtor = obj.authtor;
	this->genre = obj.genre;
	this->is_avalible = obj.is_avalible;
	this->owner = obj.owner;

	return *this;
}

ostream& operator<< (ostream& os, const Book& obj)
{
	os << obj.authtor << ": " << obj.name << " ( " << obj.genre << " ) " << (obj.is_avalible ? "avalible" : "no avalible");
	return os;
}

istream& operator>> (istream& is, Book& obj)
{
	cout << "Name: ";
	is >> obj.name;
	cout << "Authtor: ";
	is >> obj.authtor;
	cout << "Genre: ";
	is >> obj.genre;
	obj.is_avalible = true;
	return is;
}