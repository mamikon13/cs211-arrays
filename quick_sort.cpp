#include <iostream>
#include <cassert>
#include <cstdlib>
 
using std::rand;
using std::swap;
 
// pivot - "опорный" элемент
// partition - переупорядочивает элементы части массива,
// заданной отрезком [left, right), так что в начале
// следуют элементы меньшие pivot, а в конце - большие;
// возвращает место начала блока элементов, больших pivot;
int * partition(int * left, int * right, int pivot) {
	int * store = left; // место для вставки элементов, меньших pivot
	for (int * p = left; p != right; ++p)
		if (*p <= pivot)
			swap(*p, *store++);
	return store;
}
 
void my_qsort(int * arr, int n) {
	if (n <= 1)
		return; // массив в 1 или 0 элементов уже упорядочен
	int pivotPtr = *(arr + rand() % n); // случайный выбор опорного элемента
	int newPivotIdx = partition(arr, arr + n, pivotPtr) - arr;
	my_qsort(arr, newPivotIdx);
	my_qsort(arr + newPivotIdx, n - newPivotIdx);
}

template <typename T>
bool Arrays_Are_Equal(const T*arr1, const T*arr2, int size)
{
	for (int j = 0; j < size; j++)
		if (arr1[j] != arr2[j])
			return false;
	return true;
}

int main()
{
	int arr[]{ 1,3,2,-53,23,0,-4 };
	int sortArr[]{ -53,-4,0,1,2,3,23 };
	my_qsort(arr, 7);
	assert(Arrays_Are_Equal(arr, sortArr, 7));

	std::cout << "Tests successfully!" << std::endl;
	system("pause");
}