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
    void Print();
    int GetSize()const;

    int operator[] (int i);
    MVector& operator= (const MVector& obj);
    MVector operator++ (int);
    MVector operator-- (int);

    operator int();
    void operator() ();
    void operator() (int* arr, int size);

    MVector& operator= (MVector&& obj)noexcept; // � ���������
    MVector& operator+= (int n);
    MVector& operator+= (MVector& obj);
    MVector& operator-= (int n);
    MVector& operator-= (MVector& obj);
    MVector& operator*= (int n);
    MVector& operator*= (MVector& obj);
    MVector& operator/= (int n);
    MVector& operator/= (MVector& obj);
};