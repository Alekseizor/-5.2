#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
Date birthDay[10];
struct Student
{
	string name;
	Date birthDay;
	char id[6];//номер зачётной книжки
};
Student group[10] =
{ "Алексей",4,8,2002,"00034",
  "Иван",5,2,2002,"00008",
  "Павел",9,10,2001,"00001",
  "Рома",12,12,2003,"00235",
  "Серёжа",23,11,2005,"00095",
  "Василий",12,10,2003,"00036",
  "Лев",19,12,2000,"00045",
  "Пётр",23,5,2001,"00005",
  "Ксюша",9,7,2000,"10983",
  "Вова",12,11,2008,"00010",
};

ostream& operator<< (ostream& out, Student& person)            //перегрузка для вывода
{
	out << setw(8)<<person.name << setw(7)<< person.birthDay.day << "." << setw(2) <<person.birthDay.month << "."  << setw(4)<< person.birthDay.year << setw(10)<< person.id;
	return out;
}
bool cmp1(Student a, Student b)   //функция для сравнения даты рождения студентов
{
	if (a.birthDay.year > b.birthDay.year)
		return 1;
	else
	{
		if (a.birthDay.year < b.birthDay.year)
			return 0;
		else
		{
			if (a.birthDay.month > b.birthDay.month)
				return 1;
			else
			{
				if (a.birthDay.month < b.birthDay.month)
					return 0;
				else
				{
					if (a.birthDay.day > b.birthDay.day)
						return 1;
					else
						return 0;
				}
			}
		}
	}
}
bool cmp2(Student a, Student b) { return (strcmp(a.id, b.id) == 1); }  //функция для сравнения номера зачётной книжки студентов
bool cmp3(Student a, Student b) { return (a.name > b.name); }        //функция для сортировки группы по алфавиту 
template <typename T>
void change(T& a, T& b)          //меняем элементы массива местами
{
	T d = a;
	a = b;
	b = d;
}
int Menu()
{
	int act;
	cout << "1- Вывод группы" << endl;
	cout << "2- Сортировка группы от старшего к младшему" << endl;
	cout << "3- Сортировка по возрастанию номера зачётной книжки студента" << endl;
	cout << "4- Сортировка по алфавиту, начиная с А" << endl;
	cout << "5- Закончить работу" << endl;
	cout << "Выберите действие" << endl;
	cin >> act;
	while (cin.fail()) {//исключение зацикливания в случае ввода недопустимых символов
		cout << "Ошибка ввода. Повторите ввод\n";
		cin.clear();//сброс в потоке флага ошибки
		cin.ignore(10, '\n');//извлечение из буфера потока введенных символов
		cin >> act;//повторный ввод
	}
	return act;

}
int main()
{
	while (true)
	{
		int O;
		int iter = 0;
		int per = 0;
		int l = 10;   //количество человек в группе
		system("chcp 1251> nul");
		switch (Menu())
		{
		case 1:
		{
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
		}
		break;
		case 2:
		{
			cout << "Каким способом выполнить сортировку?" << endl << "1. Метод пузырька" << endl << "2. Метод выбора" << endl;
			cin >> O;
			if (O == 1)
				MPV(group, l, cmp1, iter, per);
			else
				MVV(group, l, cmp1, iter, per);
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
			cout << "Количество итераций " << iter << " Количество перестановок " << per << endl;
		}
		break;
		case 3:
		{
			cout << "Каким способом выполнить сортировку?" << endl << "1. Метод пузырька" << endl << "2. Метод выбора" << endl;
			cin >> O;
			if (O == 1)
				MPV(group, l, cmp2, iter, per);
			else
				MVV(group, l, cmp2, iter, per);
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
			cout << "Количество итераций " << iter << " Количество перестановок " << per << endl;
		}
		break;
		case 4:
		{
			cout << "Каким способом выполнить сортировку?" << endl << "1. Метод пузырька" << endl << "2. Метод выбора" << endl;
			cin >> O;
			if (O == 1)
				MPV(group, l, cmp3, iter, per);
			else
				MVV(group, l, cmp3, iter, per);
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
			cout << "Количество итераций " << iter << " Количество перестановок " << per << endl;
		}
		break;
		case 5:
		{
			return 0;
		}
		break;
		}
		system("PAUSE");
	}
}