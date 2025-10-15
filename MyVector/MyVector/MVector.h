#pragma once
class MVector {
private:
    int size;
    int* arr;
public:
    MVector();
    MVector(int size);
    MVector(const MVector& obj);
    MVector(MVector&& obj)noexcept;
    ~MVector();

    void Init();
    void Init(int* nArr);
    void Init(int* nArr, const int nSize);
    void Print();
    int GetSize()const;
    void SetIndex(int i, int n);
    int GetIndex(int i);

    int operator[] (int i);
    MVector& operator= (const MVector& obj);
    MVector operator++ (int);
    MVector operator-- (int);

    operator int();
    void operator() ();
    void operator() (int* arr, int size);

    MVector& operator= (MVector&& obj)noexcept; // с переносом
    MVector& operator+= (int n);
    MVector& operator+= (MVector& obj);
    MVector& operator-= (int n);
    MVector& operator-= (MVector& obj);
    MVector& operator*= (int n);
    MVector& operator*= (MVector& obj);
    MVector& operator/= (int n);
    MVector& operator/= (MVector& obj);
};