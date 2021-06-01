#include "Student.h"
#include<string.h>
#include <windows.h>
#include <conio.h>
#pragma warning(disable:4996)

float Student::m_BanAvg = 0.0f;
float Student::m_BanTotal = 0.0f;

Student::Student()
{
}

Student::Student(const char* a_Name, int a_Kor, int a_Eng, int a_Math)
{
	strcpy(m_Name, a_Name);
	m_kor = a_Kor;
	m_Eng = a_Eng;
	m_Math = a_Math;
}

Student::~Student()
{
}

void Student::CacBanJumsu(vector<Student>* a_StdList)
{
	m_BanTotal = 0.0f;
	m_BanAvg = 0.0f;
	int TotalStd = (int)a_StdList->size();
	for (int ii = 0; ii < TotalStd; ii++)
	{
		m_BanTotal += (*a_StdList)[ii].m_Total;
	}
	m_BanAvg = (m_BanTotal / TotalStd) / 3.0f;
}

void Student::LoadStdList(vector<Student>* a_StdList)
{

}

void Student::SaveStdList(vector<Student>* a_StdList)
{

}

void Student::NewStdList(vector<Student>* a_StdList)
{
	char _Name[128] = { '\0' };
	int _kor = 0;
	int _eng = 0;
	int _math = 0;
	
	cout << "학생의 이름을 입력해주세요 : ";
	cin >> _Name;
	cin.get();
	
	cout << "국어점수를 입력해주세요 : ";
	cin >> _kor;
	cin.get();
	
	cout << "영어점수를 입력해주세요 : ";
	cin >> _eng;
	cin.get();
	
	cout << "수학점수를 입력해주세요 : ";
	cin >> _math;
	cin.get();

	Student newStd(_Name, _kor, _eng, _math);
	newStd.CacJumsu();
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	newStd.PrintInfo();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	a_StdList->push_back(newStd);
	CacBanJumsu(a_StdList);
}

void Student::PrintStdList(vector<Student>* a_StdList)
{
	cout << endl << "<학생리스트>" << endl;
	for (int ii = 0; ii < a_StdList->size(); ii++)
	{
		cout << ii + 11 << "번 : ";
		(*a_StdList)[ii].PrintInfo();
	}
	cout << "반총점(" << m_BanTotal << ")" << ", 반평균(" << m_BanAvg << ")" << endl;
}

void Student::DeleteStdList(vector<Student>* a_StdList)
{
	PrintStdList(a_StdList);
	int a_Sel = 0;
	cout << "삭제하실 학생을 선택해주세요 : ";
	cin >> a_Sel;
	cin.get();

	if (a_Sel < 1 || (int)a_StdList->size() < a_Sel)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "잘못된 값을 입력했습니다 메뉴로 돌아갑니다.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}

	else
	{
		a_Sel--;
		a_StdList->erase(a_StdList->begin() + a_Sel);
		PrintStdList(a_StdList);
	}
}

