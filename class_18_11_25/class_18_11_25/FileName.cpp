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

class Pengyin : Animal
{
    string land;
    string color;
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

class Carrot : Animal
{
    bool isTalk;
    string color;
public:
    Carrot() : Animal() { isTalk = false; color = ""; }
    Carrot(string type, double weight, double height, double width, double loung, int population, int age, bool isTalk, string color) : Animal(type, weight, height, width, loung, population, age)
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

class Shark : Animal
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

    return 0;
}
