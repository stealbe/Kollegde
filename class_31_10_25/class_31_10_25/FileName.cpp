#include <iostream>
using namespace std;

template<class T>
void Fill_arr(T*& arr, int size)
{
    if (size <= 0) {
        throw "Size must be > 0";
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50;
    }
}

template<class T>
void Print(const T* arr, int size)
{
    if (size <= 0) {
        throw "Size must be > 0";
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
void Add_l_elem(T*& arr, int& size, const T& n)
{
    T* temp = new T[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    temp[size] = n;
    delete[] arr;
    arr = temp;
    size++;
}

template<class T>
void Add_f_elem(T*& arr, int& size, const T& n)
{
    T* temp = new T[size + 1];
    temp[0] = n;

    for (int i = 0; i < size; i++) {
        temp[i + 1] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size++;
}

template<class T>
void Init_elem(T*& arr, int id, const T& n)
{
    if (id < 0) {
        throw "Invalid index";
    }

    arr[id] = n;
}

template<class T>
void Add_arr(T*& arr1, int& size1, const T* arr2, int size2)
{
    if (size2 <= 0) {
        return;
    }

    T* res = new T[size1 + size2];

    for (int i = 0; i < size1; i++) {
        res[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        res[size1 + i] = arr2[i];
    }

    delete[] arr1;
    arr1 = res;
    size1 += size2;
}

template<class T>
void Del_l_elem(T*& arr, int& size)
{
    if (size <= 0) {
        throw "Array empty";
    }

    if (size == 1) {
        delete[] arr;
        arr = nullptr;
        size = 0;
        return;
    }

    T* temp = new T[size - 1];

    for (int i = 0; i < size - 1; i++) {
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size--;
}

template<class T>
void Del_f_elem(T*& arr, int& size)
{
    if (size <= 0) {
        throw "Array empty";
    }

    if (size == 1) {
        delete[] arr;
        arr = nullptr;
        size = 0;
        return;
    }

    T* temp = new T[size - 1];

    for (int i = 1; i < size; i++) {
        temp[i - 1] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size--;
}

template<class T>
void Del_arr(T*& arrM, int& sizeM, const T* arrS, int sizeS)
{
    if (sizeS <= 0 || sizeM <= 0) {
        throw "Invalid sizes";
    }

    if (sizeS > sizeM) {
        throw "arrS longer than arrM";
    }

    for (int i = 0; i <= sizeM - sizeS; i++) {
        bool match = true;

        for (int j = 0; j < sizeS; j++) {
            if (arrM[i + j] != arrS[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            int newSize = sizeM - sizeS;
            T* temp = new T[newSize];

            for (int k = 0; k < i; k++) {
                temp[k] = arrM[k];
            }

            for (int k = i + sizeS; k < sizeM; k++) {
                temp[k - sizeS] = arrM[k];
            }

            delete[] arrM;
            arrM = temp;
            sizeM = newSize;
            return;
        }
    }

    throw "arrS sequence not found in arrM";
}

int main()
{
    srand(time(NULL));

    int size1;
    int size2;

    cout << "Enter size for arr1: ";
    cin >> size1;
    cout << "Enter size for arr2: ";
    cin >> size2;

    try {
        if (size1 <= 0 || size2 <= 0) {
            throw "Sizes can't be <= 0";
        }

        int* arr = new int[size1];
        int* arr2 = new int[size2];

        Fill_arr(arr, size1);
        Fill_arr(arr2, size2);

        cout << "arr 1: ";
        Print(arr, size1);

        cout << "arr 2: ";
        Print(arr2, size2);

        Add_l_elem(arr, size1, 99);
        Add_f_elem(arr2, size2, 77);

        cout << "\nAfter adding:" << endl;
        Print(arr, size1);
        Print(arr2, size2);

        Init_elem(arr, 4, 123);

        Add_arr(arr, size1, arr2, size2);
        cout << "\nAfter merge:" << endl;
        Print(arr, size1);

        try {
            Del_arr(arr, size1, arr2, size2);
            cout << "\nAfter Del_arr:" << endl;
            Print(arr, size1);
        }
        catch (const char* e) {
            cout << "Warning: " << e << endl;
        }

        if (size1 > 0) {
            Del_l_elem(arr, size1);
        }

        if (size1 > 0) {
            Del_f_elem(arr, size1);
        }

        cout << "\nAfter delete first & last:" << endl;
        if (size1 > 0) {
            Print(arr, size1);
        }
        else {
            cout << "(empty)" << endl;
        }

        delete[] arr;
        delete[] arr2;
    }
    catch (const char* err) {
        cout << "Error: " << err << endl;
    }

    return 0;
}
