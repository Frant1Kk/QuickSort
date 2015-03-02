/** @file Quick.Sort.cpp */
#include "stdafx.h"
#include <iostream>
#include "locale.h"
using namespace std;

/**
*@function QuickSort(int *mas, int first, int last)
*@param *mas - Ukazatel' na massiv
*@param first - Ukazatel' dlya oboznacheniya nachal'nogo elementa massiva
*@param last - Ukazatel' dlya oboznacheniya konechnogo elementa massiva
*/
void QuickSort(int *mas, int first, int last)
{

	int p, count;
	int f = first, l = last;
	p = mas[(f + l) / 2]; /// Vychislenie opornogo elementa
	do
	{
		while (mas[f] < p) f++;
		while (mas[l] > p) l--;
		if (f <= l) /// Perestanovka elementov massiva
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) QuickSort(mas, first, l);
	if (f < last) QuickSort(mas, f, last);
}

/**
*@function main()
*/
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int first, last;
	int N;
	cout << "¬ведите кол-во элементов массива: N = "; /// Vvod kol-va elementov massiva
	cin >> N;
	int *A = new int[N];
	cout << "¬ведите значени€ элементов массива: \n"; /// Vvod elementov massiva
	for (int i = 0; i < N; i++)/// Cicl vvoda elementov massiva
	{
		cout << "A" << "[" << i + 1 << "]" << " = ";
		cin >> A[i];
	}
	first = 0; last = N - 1;
	QuickSort(A, first, last); /// Funkciya QuickSort
	cout << "\n”пор€доченный массив:\n"; /// Pechat' uporyadochennogo massiva
	for (int j = 0; j < N; j++)/// Cicl pechati uporyadochennogo massiva
	{
		cout << "A" << "[" << j + 1 << "]" << " = " << A[j] << endl;
	}
	delete[]A;
	system("pause");
}

