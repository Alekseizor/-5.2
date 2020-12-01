#include <iomanip>
#include<algorithm>
#include <cmath>
#include <iostream>
using namespace std;
template <typename T>
int maxdlin(T* a, int nrow, int ncol)    //определение наибольшей длины целой части числа
{
	double maxzn = 0;
	int i, j, size=0;
	for ( i = 0; (i < nrow); i++)
	{
		for ( j = 0; (j < ncol); j++)
		{
			if (abs(a[i][j]) > maxzn)
				maxzn= abs(a[i][j]);
		}
	}
	while (maxzn >= 1)
	{
		size++;
		maxzn = maxzn / 10;
	}
	return size;
}
template <typename T>
void con(T* a, int format, int n, int nrow, int ncol)    //вывод матрицы
{
	int t,l,p,k,i,j,E=1;
	if (format == 1)                          //Вывод в фиксированном формате 
	{
		t = maxdlin(a,nrow,ncol);
		k = 80 / (t + n + 9);
		while (E <= (ncol))
		{
			p = 0;
			for (l = E; ((p < k) && (l <= ncol)); l++)            //Вывод номера столбца
			{
				cout << setw(n + t)<<"№ "<<setw(2)<< l << "       ";
				p++;
			}
			cout << endl;
			for (i = 0; (i < nrow); i++)                          //Вывод элементов матрицы
			{
				p = 0;
				for (j = (E - 1); ((p < k) && (j < ncol)); j++)
				{
					cout << fixed << setprecision(n) << setw(n + t + 2) << a[i][j] << "       ";
					p++;
				}
				cout << endl;
			}
			cout << endl;
			E += k;
		}
	}
	else                      //Вывод в научном формате
	{
		k = 80 / (n + 14);
		while (E <=(ncol))
		{
			p = 0;
			for (l = E; ((p < k) && (l <= ncol)); l++)                //Вывод номера столбца
			{
				cout << setw(n + 5)<< "№ " << setw(2) << l << "       ";
				p++;
			}
			cout << endl;
			for (i = 0; (i < nrow); i++)                             //Вывод элементов матрицы
			{
				p = 0;
				for (j = (E-1); ((p < k)&&(j<ncol)); j++)
				{   
					cout << scientific << setprecision(n) << setw(n + 7) << a[i][j] << "       ";
					p++;
				}
				cout << endl;
			}
			cout << endl;
			E += k;
		}
	}
}
template <typename T>
void completion(T* a,int nrow,int ncol)  //Заполнение собственной матрицы
{
	cout << "Введите элементы матрицы" << endl;
	for (int i = 0; (i < nrow); i++)
	{
		for (int j = 0; (j < ncol); j++)
			cin >> a[i][j];
	}
}
