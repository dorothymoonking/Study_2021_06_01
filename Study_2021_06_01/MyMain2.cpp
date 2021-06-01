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