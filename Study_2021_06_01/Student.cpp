#include "Student.h"
#include<string.h>
#include <windows.h>
#include <conio.h>
#include <algorithm>
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

bool Student::KorSort(const Student& a, const Student& b)
{
	return a.m_kor > b.m_kor;
}

bool Student::EngSort(const Student& a, const Student& b)
{
	return a.m_Eng > b.m_Eng;
}

bool Student::MathSort(const Student& a, const Student& b)
{
	return a.m_Math > b.m_Math;
}

bool Student::AvgSort(const Student& a, const Student& b)
{
	return a.m_Avg > b.m_Avg;
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
	if(0 < TotalStd)
		m_BanAvg = (m_BanTotal / TotalStd) / 3.0f;
}

void Student::LoadStdList(vector<Student>* a_StdList)
{
	FILE* a_rFP = fopen("MySave.abc", "rb");
	if (a_rFP != NULL)
	{
		int a_strCount = 0;

		int a_UserCount = 0;
		fread(&a_UserCount, sizeof(int), 1, a_rFP);

		//fread(&m_BanTotal, sizeof(int), 1, a_rFP);
		//fread(&m_BanAvg, sizeof(int), 1, a_rFP);

		Student StdNode;
		for (int ii = 0; ii < a_UserCount; ii++)
		{
			a_strCount = 0;
			fread(&a_strCount, sizeof(int), 1, a_rFP);
			if (0 < a_strCount)
				fread(StdNode.m_Name, a_strCount, 1, a_rFP);

			fread(&StdNode.m_kor, sizeof(int), 1, a_rFP);
			fread(&StdNode.m_Eng, sizeof(int), 1, a_rFP);
			fread(&StdNode.m_Math, sizeof(int), 1, a_rFP);
			StdNode.CacJumsu();
			a_StdList->push_back(StdNode);
		}//for (int ii = 0; ii < a_ItemCount; ii++)

		fclose(a_rFP);
	}//if (a_rFP != NULL)
	CacBanJumsu(a_StdList);
}

void Student::SaveStdList(vector<Student>* a_StdList)
{
	FILE* a_wFP = fopen("MySave.abc", "wb");

	if (a_wFP != NULL)
	{
		int a_StrCount = 0;

		int a_UserCount = (int)a_StdList->size();
		fwrite(&a_UserCount, sizeof(int), 1, a_wFP);

		//float a_BanTotal = m_BanTotal;
		//fwrite(&a_BanTotal, sizeof(float), 1, a_wFP);
		//float a_BanAvg = m_BanAvg;
		//fwrite(&a_BanAvg, sizeof(float), 1, a_wFP);

		for (int ii = 0; ii < (int)a_StdList->size(); ii++)
		{
			a_StrCount = 0;
			a_StrCount = strlen((*a_StdList)[ii].m_Name) + 1;
			fwrite(&a_StrCount, sizeof(int), 1, a_wFP);
			fwrite((*a_StdList)[ii].m_Name, a_StrCount, 1, a_wFP);

			fwrite(&(*a_StdList)[ii].m_kor, sizeof(int), 1, a_wFP);
			fwrite(&(*a_StdList)[ii].m_Eng, sizeof(int), 1, a_wFP);
			fwrite(&(*a_StdList)[ii].m_Math, sizeof(int), 1, a_wFP);
		}

		fclose(a_wFP);

	}//if (a_wFP != NULL)
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
}

void Student::PrintStdList(vector<Student>* a_StdList, bool DeleteMode)
{
	CacBanJumsu(a_StdList);
	cout << endl << "<학생리스트>" << endl;
	for (int ii = 0; ii < a_StdList->size(); ii++)
	{
		cout << ii + 1 << "번 : ";
		(*a_StdList)[ii].PrintInfo();
	}

	if(DeleteMode == false)
		cout << "반총점(" << m_BanTotal << ")" << ", 반평균(" << m_BanAvg << ")" << endl;
}

void Student::DeleteStdList(vector<Student>* a_StdList)
{
	PrintStdList(a_StdList, true);
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
		PrintStdList(a_StdList, true);
	}
}

void Student::SortStdList(vector<Student>* a_StdList, int a_MenuSel)
{
	vector<Student> a_TempList;
	a_TempList.assign(a_StdList->begin(), a_StdList->end());

	if (a_MenuSel == 1)
	{
		sort(a_TempList.begin(), a_TempList.end(), KorSort);
	}
	else if (a_MenuSel == 2)
	{
		sort(a_TempList.begin(), a_TempList.end(), EngSort);
	}
	else if (a_MenuSel == 3)
	{
		sort(a_TempList.begin(), a_TempList.end(), MathSort);
	}
	else if (a_MenuSel == 4)
	{
		sort(a_TempList.begin(), a_TempList.end(), AvgSort);
	}

	PrintStdList(&a_TempList);
}

