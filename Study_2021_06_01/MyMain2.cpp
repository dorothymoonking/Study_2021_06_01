#include <stdio.h>
#include <iostream>
#include "Student.h"

using namespace std;

//class �� static �������, ����Լ�

void main()
{
	vector<Student> m_StdList;

	//�ε�
	Student::LoadStdList(&m_StdList);

	while (true)
	{
		int a_Sel = 0;
		cout << "�л��߰�(1) �л�����Ʈ(2) �л�����(3) ���α׷�����(99) : ";
		cin >> a_Sel;
		cin.get();

		if (a_Sel < 1 || 3 < a_Sel)
		{
			if (a_Sel == 99)
				return;

			system("cls");
			continue;
		}

		if (a_Sel == 1)
		{
			Student::NewStdList(&m_StdList);
		}
		else if (a_Sel == 2)
		{
			Student::PrintStdList(&m_StdList);
		}
		else if (a_Sel == 3)
		{
			Student::DeleteStdList(&m_StdList);
		}

		cin.get();
		system("cls");
	}//while (true)

	m_StdList.clear();
	cin.get();
}