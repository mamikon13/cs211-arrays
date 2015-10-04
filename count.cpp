#include <iostream>
#include <string>
#include <cstdio>
#include "arrays.h"

using namespace std;

/* count digits, white space, others */

/* TODO: (1) fix all errors; 
 *       (2) add code for painting histogram in console,
 *           cf. picture in https://en.wikipedia.org/wiki/Histogram
 * 
 */

int main()
{
	string src("12 plus 45 minus 39 is 18\n");
	int i, nwhite, nother;
	const int size = 10;
	int ndigit[size]{ 0 };
	nwhite = nother = 0;

	char c;
	i = 0;
	while ((c = src[i++]) != '\0')
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	
	cout << "source string: " << src << endl << "digits =";
	for (int i = 0; i < size; ++i)
		cout << " " << ndigit[i];
	
	cout << ", white space = " << nwhite 
		 << ", other = " << nother << endl;

	// Ниже реализация рисования столбиковой диаграммы
	cout << '\n' << '\n';

	int maxCount = 0; // Наиболее часто встретившийся элемент
	for (i = 0; i < size; i++)
	{
		if (ndigit[i] > maxCount)
			maxCount = ndigit[i];
	}
	if (nwhite > maxCount)
		maxCount = nwhite;
	if (nother > maxCount)
		maxCount = nother;

	for (i = maxCount; i > 0; i--) // Цикл по пробегу частот встреч
	{
		if (i < 10) // Пробелы после значения частоты
		    cout << i << "  ";
		else
			cout << i << " ";
		for (int j = 0; j < size + 2; j++) // Цикл по пробегу всех встретившихся символов
		{
			if (ndigit[j] >= i || (nwhite >= i && j == size) || (nother >= i && j == size + 1))
				cout << "+ "; // "+" - закрашено
			else cout << "  "; // " " - не закрашено
		}
		cout << endl;
	}
	cout << "   0 1 2 3 4 5 6 7 8 9 _ c";
	
	cout << '\n' << '\n';

	system("pause");
}
