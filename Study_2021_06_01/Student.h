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

	//-----���� ��� ����
	static float m_BanTotal;	//���� ��� ����������Ű�� ���� ����(static���� ������ ������ �޸𸮰��� ���α׷��� ����ɶ� �ʱ�ȭ�� �ȴ�.)
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
		cout << "�̸�(" << m_Name << ") : ����(" << m_kor << ")" <<
				", ����(" << m_Eng << ")" << ", ����(" << m_Math << ")" <<
				", ����(" << m_Total << ")" << ", ���(" << m_Avg << ")" << endl;
	}

	//----- ���� ��� �Լ� ���� �κ�
	static void CacBanJumsu(vector<Student>* a_StdList);
	static void LoadStdList(vector<Student>* a_StdList);
	static void SaveStdList(vector<Student>* a_StdList);
	static void NewStdList(vector<Student>* a_StdList);
	static void PrintStdList(vector<Student>* a_StdList);
	static void DeleteStdList(vector<Student>* a_StdList);
	//-----
};

