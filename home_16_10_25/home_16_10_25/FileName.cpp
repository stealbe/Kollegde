#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type, class Int>
void Fill(Type** mat, Int size[])
{
	for (size_t i = 0; i < size[0]; i++)
	{
		for (size_t j = 0; j < size[1]; j++)
		{
			mat[i][j] = rand() % 9;
		}
	}
}

template <typename Type, typename Int>
void Print(Type** mat, Int size[])
{
	for (size_t i = 0; i < size[0]; i++)
	{
		for (size_t j = 0; j < size[1]; j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

template <typename Type, typename Int>
Type MinOnDiag(Type** mat, Int size[])
{
	if (size[0] != size[1]) return;
	Type min = mat[0][0];
	for (size_t i = 0; i < size[0]; i++)
	{
		if (mat[i][i] < min) min = mat[i][i];
	}
	return min;
}

template <typename Type, typename Int>
Type MaxOnDiag(Type** mat, Int size[])
{
	if (size[0] != size[1]) return;
	Type max = mat[0][0];
	for (size_t i = 0; i < size[0]; i++)
	{
		if (mat[i][i] > max) max = mat[i][i];
	}
	return max;
}

template <typename Type>
void quickSortR(Type* a, const int B, const int E)
{
	long i = B, j = E;
	Type temp, p;
	p = a[(B + E) / 2];
	do
	{
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (B < j)quickSortR(a, B, j);
	if (i < E)quickSortR(a, i, E);
}

template <typename Type, typename Int>
void SortMat(Type** mat, Int size[])
{
	for (size_t e = 0; e < size[0]; e++)
	{
		quickSortR(mat[e], 0, size[1] - 1);
	}
}


int main() {
	srand(time(NULL));

	int size[2]{ 5, 5 };
	int** arr1 = new int*[size[0]];

	for (size_t i = 0; i < size[0]; i++)
	{
		arr1[i] = new int[size[1]];
	}
	Fill(arr1, size);
	Print(arr1, size);
	SortMat(arr1, size);
	cout << "After: " << endl;
	Print(arr1, size);

	for (int i = 0; i < size[0]; i++) {
		delete[] arr1[i];
	}
	delete[] arr1;
    return 0;
}