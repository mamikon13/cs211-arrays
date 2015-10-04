#include <iostream>
#include <cassert>
#include "arrays.h"

using namespace std;

int main()
{
	// Task 1
	task_1();

	// Task 2
	task_2(); // assert inside

	// Task 3
	// returns zero
	assert(task_3_zero() == 0);

	// Task 4
	task_4(); // assert inside

	// Task 5
	int a[3]{ 23,4,-35 };
	int b[3] = { 0 };
	task_5_copy(a, b, 3);
	assert(a[0] == b[0]);
	assert(a[1] == b[1]);
	assert(a[2] == b[2]);

	// Task 7
	task_7_print(b, 3);

	cout << '\n' << "Tests successfully!" << endl;
	system("pause");
}