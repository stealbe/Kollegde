#include <iostream>
using namespace std;

class Fract {
private:
    int nom = 1;
    int dnom = 1;
public:
    Fract()
    {
        this->nom = 1;
        this->dnom = 1;
    }
    Fract(int _nom, int _dnom)
    {
        this->nom = _nom;
        if (dnom != 0)this->dnom = _dnom;
    }
    void Init(int _nom, int _dnom)
    {
        this->nom = _nom;
        if (dnom != 0)this->dnom = _dnom;
    }
    void Print()
    {
        cout << this->nom << "/" << this->dnom << endl;
    }
    Fract Sum(Fract& b)
    {
        Fract buf_fract(this->dnom != b.dnom ? this->nom * b.dnom + b.nom * this->dnom, this->dnom * b.dnom : this->nom + b.nom, this->dnom);
        return (buf_fract);
    }
    Fract Minus(Fract& b)
    {
        Fract buf_fract(this->dnom != b.dnom ? this->nom * b.dnom - b.nom * this->dnom, this->dnom * b.dnom : this->nom - b.nom, this->dnom);
        return (buf_fract);
    }
    Fract Nom(Fract& b)
    {
        Fract buf_fract(this->nom * b.nom, this->dnom * b.dnom);
        return(buf_fract);
    }
    Fract Dnom(Fract& b)
    {
        Fract buf_fract(this->nom * b.dnom, this->dnom * b.nom);
        return(buf_fract);
    }
};

int main() {

    return 0;
}