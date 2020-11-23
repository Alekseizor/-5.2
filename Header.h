#pragma once
template <typename T>
void MPV(T* Array, int lenght, bool (*CMP)(T a, T b), int& iter, int& per)      //���������� ������� �� ��������(����� ��������)
{
	T d;
	int i, j;
	for (j = (lenght - 1); (j > 0); j--)
	{
		for (i = 0; (i < j); i++)
		{
			iter++;
			if (CMP(Array[i], Array[i + 1]))          //���������� ��������� �� ������������ �������
			{
				change(Array[i], Array[i + 1]);      //�������� ������� �������� �������
				per++;
			}
		}
	}
}
template <typename T>
void MVV(T* Array, int lenght, bool (*CMP)(T a, T b), int& iter, int& per)   //���������� ������� �� �����������(����� ������)
{
	int i, j;
	for (i = 0; (i < (lenght - 1)); i++)
	{
		int iMin = i;
		for (j = (i + 1); (j < (lenght)); j++)
		{
			iter++;
			if (CMP(Array[iMin], Array[j]))               //������� ������ �����������(�����������) ��������
			{
				iMin = j;
			}
		}
		if (i != iMin)
		{
			change(Array[i], Array[iMin]);               //������ �������� ������� �������
			per++;
		}
	}
}