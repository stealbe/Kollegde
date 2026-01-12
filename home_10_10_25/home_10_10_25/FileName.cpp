#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string name;
    string h_number;
    string m_nuber;
public:
    User() = default;
    User(const string name, const string h_num, const string m_num)
    {
        Init(name, h_num, m_num);
    }
    void Init(const string name, const string h_num, const string m_num)
    {
        this->name = name;
        this->h_number = h_num;
        this->m_nuber = m_num;
    }
    void Cpy(const User& obj)
    {
        this->name = obj.name;
        this->h_number = obj.h_number;
        this->m_nuber = obj.m_nuber;
    }
    void operator= (const User& obj)
    {
        this->name = obj.name;
        this->h_number = obj.h_number;
        this->m_nuber = obj.m_nuber;
    }
    int Compare_h_nums_num(const User& obj)
    {
        size_t len = min(h_number.size(), obj.h_number.size());
        for (size_t i = 0; i < len; i++) {
            if (h_number[i] > obj.h_number[i]) return 1;
            if (h_number[i] < obj.h_number[i]) return -1;
        }
        if (h_number.size() > obj.h_number.size()) return 1;
        if (h_number.size() < obj.h_number.size()) return -1;
        return 0;
    }
    int Compare_m_nums_num(const User& obj)
    {
        size_t len = min(m_nuber.size(), obj.m_nuber.size());
        for (size_t i = 0; i < len; i++) {
            if (m_nuber[i] > obj.m_nuber[i]) return 1;
            if (m_nuber[i] < obj.m_nuber[i]) return -1;
        }
        if (m_nuber.size() > obj.m_nuber.size()) return 1;
        if (m_nuber.size() < obj.m_nuber.size()) return -1;
        return 0;
    }
    bool IsSimpleName(const string name)
    {
        return this->name == name;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Home number: " << h_number << endl;
        cout << "Mobile number: " << m_nuber << endl;
    }
};

class PhBook {
private:
    User* book;
    int size;
public:
    PhBook()
    {
        book = nullptr;
        size = 0;
    }
    PhBook(int size)
    {
        srand(time(0));
        this->size = size;
        book = new User[size];

        for (int i = 0; i < size; i++) {
            book[i] = User(
                "User" + to_string(rand()),
                "38050" + to_string(1000001 + rand() % 999999),
                "38050" + to_string(1000001 + rand() % 999999)
            );
        }
    }
    PhBook(const User* arr, const int size)
    {
        this->size = size;
        book = new User[size];
        if (size <= 0) return;
        for (size_t i = 0; i < size; i++)
        {
            book[i] = arr[i];
        }
    }
    ~PhBook()
    {
        delete[] book;
    }
    // эти были сложными + часть функций стринга с инета
    void sortViaHNumbers()
    {
        for (int i = 1; i < size; i++)
        {
            User buf = book[i];
            int j = i - 1;

            while (j >= 0 && buf.Compare_h_nums_num(book[j]) < 0)
            {
                book[j + 1] = book[j];
                j--;
            }

            book[j + 1] = buf;
        }
    }
    void sortViaMNumbers()
    {
        for (int i = 1; i < size; i++)
        {
            User buf = book[i];
            int j = i - 1;

            while (j >= 0 && buf.Compare_m_nums_num(book[j]) < 0)
            {
                book[j + 1] = book[j];
                j--;
            }

            book[j + 1] = buf;
        }
    }
    int IndexUserViaName(string name)
    {
        for (int i = 0; i < size; i++)
        {
            if (book[i].IsSimpleName(name)) return i;
        }
        return -1;
    }
    void PrintUserViaName(string name)
    {
        book[IndexUserViaName(name)].Print();
    }
    void PrintUserViaId(int id)
    {
        book[id].Print();
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            PrintUserViaId(i);
        }
    }
    void Exit()
    {
        delete[] this;
    }
};

int main() {

    int menu;
    PhBook book(10);
    do
    {
        cout << "Menu:: \b 1) Sort via mobile\b 2) Sort via home\b 3) Show\b 0) Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Mobile numbers sort:: " << endl;
            book.sortViaMNumbers();
            break;
        case 2:
            cout << "Home numbers sort:: " << endl;
            book.sortViaHNumbers();
            break;
        case 3:
            cout << "Phone book:: " << endl;
            book.Print();
            break;
        default:
            break;
        }
    } while (menu);
    book.Exit();
    return 0;
}