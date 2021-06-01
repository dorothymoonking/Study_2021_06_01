#include<stdio.h>
#include<iostream>

using namespace std;
#pragma warning(disable:4996)

// Get Set
// 멤버변수를 private 속성으로 해 놓고 public Get변수명(), public Set변수명()으로 접근하게
// 해 주는 방식들이 있다. 이렇게 사용했 을 때의 장점

// 1, 변수를 보호하고 소스의 유지보수, 확장성이 좋아진다.
// 2, m_Gold 멤버변수를 읽기전용이나 쓰기전용으로 만들 수 있다.

class MyUint
{
private:
	int m_Gold = 100;

public:
	int GetGold()
	{
		//복호화
		return m_Gold;
	}

	void SetGold(int a_Gold)
	{
		//암호화
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