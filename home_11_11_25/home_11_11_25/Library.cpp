#include "Library.h"

Library::Library()
{
	this->users = nullptr;
	users_count = 0;
	this->catalog = nullptr;
	books_count = 0;
}

Library::Library(const Book* catalog, const int books_count)
{
	if (catalog == nullptr) throw "Catalog can't be = nullptr";
	if (books_count <= 0) throw "Books count can't be <= 0";
	AddLib(catalog, books_count);
}

Library::Library(const User* users, const int users_count, const Book* catalog, const int books_count)
{
	if (users == nullptr) throw "Users can't be = nullptr";
	if (users_count <= 0) throw "Users count can't be <= 0";
	if (catalog == nullptr) throw "Catalog can't be = nullptr";
	if (books_count <= 0) throw "Books count can't be <= 0";
	AddListUs(users, users_count);
	AddLib(catalog, books_count);
}

void Library::AddUser()
{
	int newSize = this->users_count + 1;
	User* temp = new User[newSize];
	for (int i = 0; i < this->users_count; ++i) temp[i] = this->users[i];
	cin >> temp[this->users_count];
	delete[] this->users;
	this->users = temp;
	this->users_count = newSize;
}


void Library::AddListUs(const User* users, const int users_count)
{
	if (users_count <= 0) throw "Count of users can't be <= 0";
	if (users == nullptr) throw "Users can't = nullptr";
	if (this->users != nullptr) delete[] this->users;
	this->users_count = users_count;
	this->users = new User[this->users_count];
	for (size_t i = 0; i < this->users_count; i++)
	{
		this->users[i] = users[i];
	}
}

void Library::AddBook()
{
	Book* temp = new Book[this->books_count + 1];
	for (size_t i = 0; i < this->books_count; i++)
	{
		temp[i] = this->catalog[i];
	}
	delete[] this->catalog;
	cin >> temp[this->books_count++];
	this->catalog = temp;
}

void Library::AddLib(const Book* lib, const int books_count)
{
	if (books_count <= 0) throw "Count of books can't be <= 0";
	if (lib == nullptr) throw "Lib can't = nullptr";
	if (this->catalog != nullptr) delete[] this->catalog;
	this->books_count = books_count;
	this->catalog = new Book[this->books_count];
	for (size_t i = 0; i < this->books_count; i++)
	{
		this->catalog[i] = lib[i];
	}
}

void Library::RemoveUser(const int id)
{
	if (users_count == 0) return;
	int newSize = this->users_count - 1;
	User* temp = new User[newSize];
	int j = 0;
	for (int i = 0; i < this->users_count; ++i)
	{
		if (this->users[i].GetId() != id)
		{
			if (j < newSize) temp[j++] = this->users[i];
		}
	}
	delete[] this->users;
	this->users = (j > 0 ? temp : nullptr);
	this->users_count = j;
	if (j == 0) delete[] temp;
}

void Library::RemoveBook(const int id)
{
	if (books_count == 0) return;
	int newSize = this->books_count - 1;
	Book* temp = new Book[newSize];
	int j = 0;
	for (int i = 0; i < this->books_count; ++i)
	{
		if (this->catalog[i].GetId() != id)
		{
			if (j < newSize) temp[j++] = this->catalog[i];
		}
	}
	delete[] this->catalog;
	this->catalog = (j > 0 ? temp : nullptr);
	this->books_count = j;
	if (j == 0) delete[] temp;
}


Book& Library::FindBookViaName(string name)
{
	if (name.empty()) throw "Name can't be empty";
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetName() == name) return this->catalog[i];
	}
	throw "book " + name + " does not exist";
}

Book* Library::FiindBookViaGenre(string genre)
{
	if (genre.empty()) throw "Genre can't be empty";
	int res_count = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetGenre() == genre) res_count++;
	}
	if (res_count == 0) throw "Some books in " + genre + " does not exist";
	Book* res = new Book[res_count];
	int j = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetGenre() == genre) res[j++] =  this->catalog[i];
	}
	
	return res;
}

Book* Library::FindBookViaAuthtor(string authtor)
{
	if (authtor.empty()) throw "Authtor can't be empty";
	int res_count = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetAuthtor() == authtor) res_count++;
	}
	if (res_count == 0) throw "Some books of " + authtor + " does not exist";
	Book* res = new Book[res_count];
	int j = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetAuthtor() == authtor) res[j++] = this->catalog[i];
	}

	return res;
}

User& Library::MostFrequenceUs()
{
	int max = 0;
	int id = -1;
	for (int i = 0; i < this->users_count; i++)
	{
		if (this->users[i].GetFreq() > max)
		{
			max = this->users[i].GetFreq();
			id = i;
		}
	}
	if (id == -1) throw "No users exist";
	return this->users[id];
}

void Library::ShowAllLibrary()
{
	for (size_t i = 0; i < this->books_count; i++)
	{
		cout << i + 1 << ": " << catalog[i] << endl;
	}
}

void Library::ShowAvalibleLibrary()
{
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (catalog[i].IsAvalible()) cout << i << ": " << catalog[i] << endl;
	}
}

void Library::ShowAllUsers()
{
	for (size_t i = 0; i < this->users_count; i++)
	{
		cout << i + 1 << ": " << this->users[i] << endl;
	}
}

void Library::ShowUserViaId(const int id)
{
	if (id < 0) throw "id can't be < 0";
	cout << this->users[id] << endl;
	if (this->users[id].GetLibSize() > 0) cout << "Owned: " << endl;
	for (size_t i = 0; i < this->users[id].GetLibSize(); i++)
	{
		cout << this->users[id].GetLib()[i] << endl;
	}
}

void Library::ShowBookViaId(const int id)
{
	if (id < 0) throw "id can't be < 0";
	cout << this->catalog[id] << endl;
	if (!this->catalog[id].IsAvalible()) cout << "Owner: " << endl;
	cout << this->catalog[id].GetOwer() << endl;
}

void Library::ShowAllBooksViaGenre(const string genre)
{
	if (genre.empty()) throw "Genre can't be empty";
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetGenre() == genre) cout << catalog[i] << endl;
	}
}

void Library::ShowAllBooksViaAuthtor(const string authtor)
{
	if (authtor.empty()) throw "Authtor can't be empty";
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].GetAuthtor() == authtor) cout << this->catalog[i] << endl;
	}
}

void Library::LendBook(const int u_id, const int b_id)
{
	this->users[u_id].AddBook(this->catalog[b_id]);
	this->catalog[b_id].SetOwner(&this->users[u_id]);
}

void Library::ReturnBook(const int u_id, const int b_id)
{
	this->users[u_id].RemoveBook(b_id);
	this->catalog[b_id].RemoveOwner();
}

Library::~Library()
{
	delete[] users;
	delete[] catalog;
}
