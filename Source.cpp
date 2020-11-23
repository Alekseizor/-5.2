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
	char id[6];//����� �������� ������
};
Student group[10] =
{ "�������",4,8,2002,"00034",
  "����",5,2,2002,"00008",
  "�����",9,10,2001,"00001",
  "����",12,12,2003,"00235",
  "�����",23,11,2005,"00095",
  "�������",12,10,2003,"00036",
  "���",19,12,2000,"00045",
  "ϸ��",23,5,2001,"00005",
  "�����",9,7,2000,"10983",
  "����",12,11,2008,"00010",
};

ostream& operator<< (ostream& out, Student& person)            //���������� ��� ������
{
	out << setw(8)<<person.name << setw(7)<< person.birthDay.day << "." << setw(2) <<person.birthDay.month << "."  << setw(4)<< person.birthDay.year << setw(10)<< person.id;
	return out;
}
bool cmp1(Student a, Student b)   //������� ��� ��������� ���� �������� ���������
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
bool cmp2(Student a, Student b) { return (strcmp(a.id, b.id) == 1); }  //������� ��� ��������� ������ �������� ������ ���������
bool cmp3(Student a, Student b) { return (a.name > b.name); }        //������� ��� ���������� ������ �� �������� 
template <typename T>
void change(T& a, T& b)          //������ �������� ������� �������
{
	T d = a;
	a = b;
	b = d;
}
int Menu()
{
	int act;
	cout << "1- ����� ������" << endl;
	cout << "2- ���������� ������ �� �������� � ��������" << endl;
	cout << "3- ���������� �� ����������� ������ �������� ������ ��������" << endl;
	cout << "4- ���������� �� ��������, ������� � �" << endl;
	cout << "5- ��������� ������" << endl;
	cout << "�������� ��������" << endl;
	cin >> act;
	while (cin.fail()) {//���������� ������������ � ������ ����� ������������ ��������
		cout << "������ �����. ��������� ����\n";
		cin.clear();//����� � ������ ����� ������
		cin.ignore(10, '\n');//���������� �� ������ ������ ��������� ��������
		cin >> act;//��������� ����
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
		int l = 10;   //���������� ������� � ������
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
			cout << "����� �������� ��������� ����������?" << endl << "1. ����� ��������" << endl << "2. ����� ������" << endl;
			cin >> O;
			if (O == 1)
				MPV(group, l, cmp1, iter, per);
			else
				MVV(group, l, cmp1, iter, per);
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
			cout << "���������� �������� " << iter << " ���������� ������������ " << per << endl;
		}
		break;
		case 3:
		{
			cout << "����� �������� ��������� ����������?" << endl << "1. ����� ��������" << endl << "2. ����� ������" << endl;
			cin >> O;
			if (O == 1)
				MPV(group, l, cmp2, iter, per);
			else
				MVV(group, l, cmp2, iter, per);
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
			cout << "���������� �������� " << iter << " ���������� ������������ " << per << endl;
		}
		break;
		case 4:
		{
			cout << "����� �������� ��������� ����������?" << endl << "1. ����� ��������" << endl << "2. ����� ������" << endl;
			cin >> O;
			if (O == 1)
				MPV(group, l, cmp3, iter, per);
			else
				MVV(group, l, cmp3, iter, per);
			for (int i = 0; (i < l); i++)
				cout << group[i] << endl;
			cout << "���������� �������� " << iter << " ���������� ������������ " << per << endl;
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