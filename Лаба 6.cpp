#include<iostream>
#include"погрешность.h"
#include"Header.h"
#include <math.h>
using namespace std;
double f1(double x) 
{
	return x;
}
double f2(double x) 
{
	return sin(22 * x);
}
double f3(double x)
{
	return pow(x, 4);
}
double f4(double x) 
{
	return atan(x);
}
double In1(double a, double b)   // получение точного значения интеграла для f1
{return (b * b - a * a) / 2.0;}
double In2(double a, double b)      // получение точного значения интеграла для f2
{return (cos(a * 22.0) - cos(b * 22.0)) / 22.0;}     
double In3(double a, double b)               // получение точного значения интеграла для f3
{return ((b * b * b * b * b - a * a * a * a * a) / 5.0);}      
double In4(double a, double b)                   // получение точного значения интеграла для f4
{return (b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0);}
I_print table[4] =
{
	{"y=x",2.0,1.0,1},
	{"y=sin(22x)",1.0,6.0,5},
	{"y=x^4",5.0,3.0,9},
	{"y=arctg(x)",8.0,4.0,25}
};
double (*In[4])(double a, double b) = { In1,In2,In3,In4 };   //массив указателей на функцию точного значения интеграла 
double (*f[4])(double x) = { f1,f2,f3,f4 };                  //массив указателей указателей на функцию
int Menu()
{
	int M;
	cout << "Выберете метод" << endl;
	cout << "1- Метод прямоугольников" << endl;
	cout<< "2- Метод трапеции" << endl;
	cin >> M;
	return M;
}

int main()
{   
	system("chcp 1251> nul");
	int i, n=1;
	double a,b,eps;
	cout << "Введите начало интервала" << endl;
	cin >> a;
	cout << "Введите конец интервала" << endl;
	cin >> b;
	cout << "Введите точность" << endl;
	cin >> eps;
	switch (Menu())
	{
	case 1:
	{   
		for (i = 0; (i < 4); i++)
	   {
		table[i].i_toch = In[i](a, b);       
		table[i].i_sum = IntRect(f[i], a, b, eps, n);     //вызов функции для вычисления интеграла методом прямоугольников
		table[i].n = n;
	   }
	}
	break;
	case 2:
	{

		for (i = 0; (i < 4); i++)
		{
			table[i].i_toch = In[i](a, b);
			table[i].i_sum = IntTrap(f[i], a, b, eps, n);      //вызов функции для вычисления интеграла методом трапеций
			table[i].n = n;
		}
	}
	break;
	}
	PrintTabl(table, 4);           //вывод таблицы
}
