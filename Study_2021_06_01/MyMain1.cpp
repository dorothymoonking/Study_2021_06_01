#include<stdio.h>
#include<iostream>

using namespace std;
#pragma warning(disable:4996)

// Get Set
// ��������� private �Ӽ����� �� ���� public Get������(), public Set������()���� �����ϰ�
// �� �ִ� ��ĵ��� �ִ�. �̷��� ����� �� ���� ����

class MyUint
{
private:
	int m_Gold = 100;

public:
	int GetGold()
	{
		return m_Gold;
	}

	void SetGold(int a_Gold)
	{
		m_Gold = a_Gold;
	}
};

void main()
{
	MyUint a_Test;
	a_Test.SetGold(2500);
	cout << a_Test.GetGold() << endl;

	cin.get();
}