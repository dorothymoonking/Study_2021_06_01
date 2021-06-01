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
			Student::SaveStdList(&m_StdList);
		}
		else if (a_Sel == 2)
		{
			if (m_StdList.size() <= 0)
			{
				cout << "����� �л��� �����ϴ�.";
				cin.get();
				system("cls");
				continue;
			}

			int a_MenuSel = 0;
			cout << "����������(1) ����������(2) ����������(3) ��ռ�(4) �׿��Ϲ���� : ";
			cin >> a_MenuSel;
			cin.get();
			if (0 < a_MenuSel && a_MenuSel < 5)
			{
				Student::SortStdList(&m_StdList, a_MenuSel);
			}
			else
			{
				Student::PrintStdList(&m_StdList);
			}
		}
		else if (a_Sel == 3)
		{
			if (m_StdList.size() <= 0)
			{
				cout << "���� �� �л��� �����ϴ�.";
				cin.get();
				system("cls");
				continue;
			}

			Student::DeleteStdList(&m_StdList);
			Student::SaveStdList(&m_StdList);
		}

		cin.get();
		system("cls");
	}//while (true)

	m_StdList.clear();
	cin.get();
}