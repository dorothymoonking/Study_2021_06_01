#include<stdio.h>
#include<iostream>

using namespace std;
#pragma warning(disable:4996)

// Get Set
// ��������� private �Ӽ����� �� ���� public Get������(), public Set������()���� �����ϰ�
// �� �ִ� ��ĵ��� �ִ�. �̷��� ����� �� ���� ����

// 1, ������ ��ȣ�ϰ� �ҽ��� ��������, Ȯ�强�� ��������.
// 2, m_Gold ��������� �б������̳� ������������ ���� �� �ִ�.

class MyUint
{
private:
	int m_Gold = 100;

public:
	int GetGold()
	{
		//��ȣȭ
		return m_Gold;
	}

	void SetGold(int a_Gold)
	{
		//��ȣȭ
		if (a_Gold < 0 || 99999999 < a_Gold)
			return;
		m_Gold = a_Gold;
	}
};

void main()
{
	MyUint a_Test;
	a_Test.SetGold(2500);
	cout << a_Test.GetGold() << endl;

	MyUint AAA;
	AAA.SetGold(3000);
	cout << AAA.GetGold() << endl;

	MyUint BBB;
	BBB.SetGold(100000000);
	cout << BBB.GetGold() << endl;

	cin.get();
}