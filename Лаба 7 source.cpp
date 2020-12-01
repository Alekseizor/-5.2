#include<iostream>
#include <iomanip>
#include"Header.h"
using namespace std;
template <typename T>
void ZapolnenieMasA(T* a, int N)
{
	int i, j;
	for (i = 0; (i < N); i++)
	{
		for (j = 0; (j < N); j++)
		{
			if (i == j)                                    //элементы, располагающиеся на главной диагонали
				a[i][j] = 1;
			else
			{
				if (j > i)                                 //элементы, располагающиеся выше главной диагонали
					a[i][j] = a[i][j - 1] / (j + 1);
				else                                       //элементы, располагающиеся ниже главной диагонали
				{
					if (j == 0)
						a[i][j] = -1;
					else
						a[i][j] = -(a[i][j - 1] / (j + 1));
				}
			}
		}
	}
}
int B[10][10] = 
{
						0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
						10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
						20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
						30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
						40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
						50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
						60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
						70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
						80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
						90, 91, 92, 93, 94, 95, 96, 97, 98, 99
};
int Menu()
{   
	int vibor;
	cout << "Выберете действие" << endl;
	cout << "1- Ввести свою собственную матрицу" << endl;
	cout << "2- Работа с квадратной матрицей, заполненной по определенному закону" << endl;
	cout << "3- Вывод целочисленной статической матрицы размером 10*10" << endl;
	cin >> vibor;
	return vibor;
}
int main()
{   
	system("chcp 1251> nul");
	int nrow, ncol, n, O, i;
	cout << "Выберете формат вывода:" << endl;
	cout << "1- Фиксированный формат" << endl;
	cout << "2- Научный формат" << endl;
	cin >> O;
	cout << "Какое количество знаков выводить после запятой?" << endl;
	cin >> n;
	switch (Menu())
	{ 
	case 1:                     //Ввести свою собственную матрицу
	{
		cout << "Введите количество строк" << endl;
		cin >> nrow;
		cout << "Введите количество столбцов" << endl;
		cin >> ncol;
		double** a = new double* [nrow];	
		for (i = 0; i < nrow; i++)
			a[i] = new double[ncol];
		completion(a, nrow, ncol);  
		con(a, O, n, nrow, ncol);
	}
	break;
	case 2:                     //Работа с квадратной матрицей, заполненной по определенному закону
	{
		int i, N;
		cout << "Введите количество строк" << endl;
		cin >> N;
		double** a = new double* [N];
		for (i = 0; i < N; i++)
			a[i] = new double[N];
		ZapolnenieMasA(a, N);
		con(a, O, n, N, N);
	}
	break;
	case 3:                   //Вывод целочисленной статической матрицы размером 10 * 10
	{
		con(B, O, n, 10,10);
	}
	break;
	}
	system("PAUSE");
}
