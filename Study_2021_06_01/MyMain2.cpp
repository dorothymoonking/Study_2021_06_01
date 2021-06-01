#include <stdio.h>
#include <iostream>
#include "Student.h"

using namespace std;

//class 의 static 멤버변수, 멤버함수

void main()
{
	vector<Student> m_StdList;

	//로딩
	Student::LoadStdList(&m_StdList);

	while (true)
	{
		int a_Sel = 0;
		cout << "학생추가(1) 학생리스트(2) 학생삭제(3) 프로그램종료(99) : ";
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
				cout << "출력할 학생이 없습니다.";
				cin.get();
				system("cls");
				continue;
			}

			int a_MenuSel = 0;
			cout << "국어점수순(1) 영어점수순(2) 수학점수순(3) 평균순(4) 그외일반출력 : ";
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
				cout << "삭제 할 학생이 없습니다.";
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