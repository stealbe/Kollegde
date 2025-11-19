#include <iostream>
using namespace std;

class Animal
{
protected:
    string type;
    double weight;
    double height;
    double width;
    double loung;
    int population;
    int age;
public:
    Animal() { type = ""; weight = 0; height = 0; width = 0; loung = 0; population = 0; age = 0; }
    Animal(string type, double weight, double height, double width, double loung, int population, int age)
    {
        Init(type, weight, height, width, loung, population, age);
    }

    void Print() { cout << "Type: " << type << "\tWeight: " << weight << "\tHeight: " << height << "\tWidth: " << width << "\tLoung: " << loung << "\tPopulatio: " << population << "\tAge: " << age << endl; }
    void Init(string type, double weight, double height, double width, double loung, int population, int age)
    {
        this->type = type;
        this->weight = weight;
        this->height = height;
        this->width = width;
        this->loung = loung;
        this->population = population;
        this->age = age;
    }
    void Eat() { cout << "Animal eat" << endl; }
    void Move() { cout << "Animal move" << endl; }
};

class Elephan : public Animal
{
    string land;
    double mHobitLong;
public:
    Elephan() : Animal() { mHobitLong = 0; }
    Elephan(string type, double weight, double height, double width, double loung, int population, int age, string land, double mHobitLong) : Animal(type, weight, height, width, loung, population, age)
    {
        this->land = land;
        this->mHobitLong = mHobitLong;
    }

    void Print()
    {
        Animal::Print();
        cout << "Lang: " << land << "\tHobit long: " << mHobitLong << " m" << endl;
    }
    void Init(string type, double weight, double height, double width, double loung, int population, int age, string land, double mHobitLong)
    {
        Animal::Init(type, weight, height, width, loung, population, age);
        this->land = land;
        this->mHobitLong = mHobitLong;
    }
};

class Pengyin : public Animal
{
    string land;
    string color;
public:
    Pengyin() : Animal() { land = ""; color = ""; }
    Pengyin(string type, double weight, double height, double width, double loung, int population, int age, string land, string color) : Animal(type, weight, height, width, loung, population, age)
    {
        this->land = land;
        this->color = color;
    }
    void Print()
    {
        Animal::Print();
        cout << "Lang: " << land << "\tColor: " << color << endl;
    }
    void Init(string type, double weight, double height, double width, double loung, int population, int age, string land, string color)
    {
        Animal::Init(type, weight, height, width, loung, population, age);
        this->land = land;
        this->color = color;
    }
};

class Parrot : public Animal
{
    bool isTalk;
    string color;
public:
    Parrot() : Animal() { isTalk = false; color = ""; }
    Parrot(string type, double weight, double height, double width, double loung, int population, int age, bool isTalk, string color) : Animal(type, weight, height, width, loung, population, age)
    {
        this->isTalk = isTalk;
        this->color = color;
    }
    void Print()
    {
        Animal::Print();
        cout << (isTalk ? "Can talk" : "Can't talk") << "\tColor: " << color << endl;
    }
    void Init(string type, double weight, double height, double width, double loung, int population, int age, bool isTalk, string color)
    {
        Animal::Init(type, weight, height, width, loung, population, age);
        this->isTalk = isTalk;
        this->color = color;
    }
};

class Shark : public Animal
{
    double nmBiteStrong;
public:
    Shark() : Animal() { nmBiteStrong = 0; }
    Shark(string type, double weight, double height, double width, double loung, int population, int age, double nmBiteStrong) : Animal(type, weight, height, width, loung, population, age)
    {
        this->nmBiteStrong = nmBiteStrong;
    }
    void Print()
    {
        Animal::Print();
        cout << "Bite strong: " << nmBiteStrong << "n/m" << endl;
    }
    void Init(string type, double weight, double height, double width, double loung, int population, int age, double nmBiteStrong)
    {
        Animal::Init(type, weight, height, width, loung, population, age);
        this->nmBiteStrong = nmBiteStrong;
    }
};

int main() {
    Animal* obj = nullptr;

    cout << "Choose animal:\n";
    cout << "1 - Elephant\n";
    cout << "2 - Shark\n";
    cout << "3 - Penguin\n";
    cout << "4 - Parrot\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nYou chose: ELEPHANT\n\n";
        obj = new Elephan("Elephant", 6000, 3.2, 1.5, 6.0, 300000, 60, "Africa", 2.4);
        break;

    case 2:
        cout << "\nYou chose: SHARK\n\n";
        obj = new Shark("Great White Shark", 1100, 1.5, 0.8, 4.5, 50000, 30, 2000);
        break;

    case 3:
        cout << "\nYou chose: PENGUIN\n\n";
        obj = new Pengyin("Penguin", 35, 1.1, 0.4, 0.8, 25000000, 20, "Antarctica", "Black-White");
        break;

    case 4:
        cout << "\nYou chose: Parrot (wtf?)\n\n";
        obj = new Parrot("Parrot", 0.3, 0.25, 0.05, 0.3, 10000000, 1, false, "Orange");
        break;

    default:
        cout << "\nWrong choice\n";
        return 0;
    }
    obj->Print();

    delete obj;
    return 0;
}