#pragma once
#include <iostream>
using namespace std;

template<typename T = int>
class Matrix {
private:
    T** mat;
    int size[2];
public:
    Matrix() {
        size[0] = 0;
        size[1] = 0;
        mat = nullptr;
    }
    Matrix(int r, int c) {
        size[0] = r;
        size[1] = c;
        mat = new T * [size[0]];
        for (int i = 0; i < size[0]; ++i)
            mat[i] = new T[size[1]]{};
        
        FillRandom();
    }

    Matrix(const Matrix& obj) {
        size[0] = obj.size[0];
        size[1] = obj.size[1];
        mat = new T * [size[0]];
        for (int i = 0; i < size[0]; ++i) {
            mat[i] = new T[size[1]];
            for (int j = 0; j < size[1]; ++j)
                mat[i][j] = obj.mat[i][j];
        }
    }

    ~Matrix() {
        for (int i = 0; i < size[0]; ++i)
            delete[] mat[i];
        delete[] mat;
    }

    void FillCin() {
        for (int i = 0; i < size[0]; ++i) {
            for (size_t j = 0; j < size[1]; j++)
            {
                cout << i + 1 << " (" << j + 1 << "): ";
                cin >> mat[i][j];
            }
        }
    }

    void FillCin(int r, int c) {
        size[0] = r;
        size[1] = c;
        mat = new T * [size[0]];
        for (int i = 0; i < size[0]; ++i) {
            mat[i] = new T[size[1]];
            for (size_t j = 0; j < size[1]; j++)
            {
                cout << i + 1 << " (" << j + 1 << "): ";
                cin >> mat[i][j];
            }
        }
    }

    void FillRandom(int min = 0, int max = 100) {
        for (int i = 0; i < size[0]; ++i)
            for (int j = 0; j < size[1]; ++j)
                mat[i][j] = rand() % (max - min + 1) + min;
    }

    void Print() {
        for (int i = 0; i < size[0]; ++i) {
            for (int j = 0; j < size[1]; ++j)
                cout << mat[i][j] << "\t";
            cout << endl;
        }
    }

    Matrix<T>& operator= (const Matrix<T>& obj) {
        if (this == &obj) return *this;
        if (mat != nullptr) {
            for (size_t i = 0; i < size[0]; i++)
            {
                delete[] mat[i];
            }
            delete[] mat;
        }
        size[0] = obj.size[0];
        size[1] = obj.size[1];
        if (size[0] > 0 && size[1] > 0)
        {
            mat = new T * [size[0]];
            for (size_t i = 0; i < size[0]; i++)
            {
                mat[i] = new T[size[1]];
                for (size_t j = 0; j < size[1]; j++)
                {
                    mat[i][j] = obj.mat[i][j];
                }
            }
        }
        else mat = nullptr;
        return *this;
    }

    Matrix<T> operator+ (Matrix<T>& obj) {
        Matrix<T> res;
        if (size[0] != obj.size[0] || size[1] != obj.size[1]) return *this;
        res.mat = new T * [size[0]];
        res.size[0];
        res.size[1];
        for (size_t i = 0; i < size[0]; i++)
        {
            res.mat[i] = new T[size[1]];
            for (size_t j = 0; j < size[1]; j++)
            {
                res.mat[i][j] = mat[i][j] + obj.mat[i][j];
            }
        }
        return res;
    }

    Matrix<T> operator- (Matrix<T>& obj) {
        Matrix<T> res;
        if (size[0] != obj.size[0] || size[1] != obj.size[1]) return *this;
        res.mat = new T * [size[0]];
        res.size[0] = size[0];
        res.size[1] = size[1];
        for (size_t i = 0; i < size[0]; i++)
        {
            res.mat[i] = new T[size[1]];
            for (size_t j = 0; j < size[1]; j++)
            {
                res.mat[i][j] = mat[i][j] - obj.mat[i][j];
            }
        }
        return res;
    }

    Matrix<T> operator* (Matrix<T>& obj) {
        Matrix<T> res;
        if (size[0] != obj.size[0] || size[1] != obj.size[1]) return *this;
        res.mat = new T * [size[0]];
        res.size[0] = size[0];
        res.size[1] = size[1];
        for (size_t i = 0; i < size[0]; i++)
        {
            res.mat[i] = new T[size[1]];
            for (size_t j = 0; j < size[1]; j++)
            {
                res.mat[i][j] = mat[i][j] * obj.mat[i][j];
            }
        }
        return res;
    }

    Matrix<T> operator/ (Matrix<T>& obj) {
        Matrix<T> res;
        if (size[0] != obj.size[0] || size[1] != obj.size[1]) return *this;
        res.mat = new T * [size[0]];
        res.size[0] = size[0];
        res.size[1] = size[1];
        for (size_t i = 0; i < size[0]; i++)
        {
            res.mat[i] = new T[size[1]];
            for (size_t j = 0; j < size[1]; j++)
            {
                res.mat[i][j] = mat[i][j] / obj.mat[i][j];
            }
        }
        return res;
    }

    T MaxE() {
        T max = mat[0][0];
        for (size_t i = 0; i < size[0]; i++)
        {
            for (size_t j = 0; j < size[1]; j++)
            {
                if (max < mat[i][j]) max = mat[i][j];
            }
        }
        return max;
    }

    T MinE() {
        T min = mat[0][0];
        for (size_t i = 0; i < size[0]; i++)
        {
            for (size_t j = 0; j < size[1]; j++)
            {
                if (min > mat[i][j]) min = mat[i][j];
            }
        }
        return min;
    }
};
