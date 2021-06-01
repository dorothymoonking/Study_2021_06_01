#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
	char m_Name[128];
	int  m_kor;
	int  m_Eng;
	int  m_Math;
	int  m_Total;
	float m_Avg;

	//-----정적 멤버 변수
	static float m_BanTotal;	//반의 평균 총점누적시키기 위한 변수(static으로 선언한 변수의 메모리값은 프로그램이 종료될때 초기화가 된다.)
	static float m_BanAvg;
	//-----

public:
	Student();
	Student(const char* a_Name, int a_Kor, int a_Eng, int a_Math);
	~Student();

public:
	void CacJumsu()
	{
		m_Total = m_kor + m_Eng + m_Math;
		m_Avg = m_Total / 3.0f;
	}

	void PrintInfo()
	{
		cout.precision(2);
		cout << fixed;
		cout << "이름(" << m_Name << ") : 국어(" << m_kor << ")" <<
				", 영어(" << m_Eng << ")" << ", 수학(" << m_Math << ")" <<
				", 총점(" << m_Total << ")" << ", 평균(" << m_Avg << ")" << endl;
	}

	//----- 정적 멤버 함수 선언 부분
	static void CacBanJumsu(vector<Student>* a_StdList);
	static void LoadStdList(vector<Student>* a_StdList);
	static void SaveStdList(vector<Student>* a_StdList);
	static void NewStdList(vector<Student>* a_StdList);
	static void PrintStdList(vector<Student>* a_StdList);
	static void DeleteStdList(vector<Student>* a_StdList);
	//-----
};

