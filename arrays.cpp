#include <iostream>
#include <cassert>

void task_1()
{
    const int n = 10;
    int a[n];
}

// Task 2
void task_2()
{
    int a[5] = {0};
	assert(!a[4]); // “. к. 0 считаетс€ за false, а массив a инициализирован нул€ми
}

// returns zero
int task_3_zero()
{
	int a[5] = { 0 };
    assert(!a[4]);
    return a[4]; // don't touch this!
}

void task_4()
{
	int a[5] = { 1,2,3,4,5 };
    
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    assert(a[3] == 4);
    assert(a[4] == 5);    
}

// Task 5
// copy arr1 to arr2
void task_5_copy(const int * arr1, int * arr2, int size)
{
	for (int i = 0; i < size; i++)
		arr2[i] = arr1[i];
}

// Task 6
// copy array `arr1` to array `arr2` of the same size
void task_6_poor_copy(const int * arr1, int * arr2, int size)
{
    for(int i = 0; i < size; i++)
        arr2[i] = arr1[i];
}

// Task 7
// print array `arr`
void task_7_print(const int * arr, int size, char delim = ' ')
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << delim;
}