#include<stdio.h>
#include<iostream>

using namespace std;
#pragma warning(disable:4996)

// Get Set
// 멤버변수를 private 속성으로 해 놓고 public Get변수명(), public Set변수명()으로 접근하게
// 해 주는 방식들이 있다. 이렇게 사용했 을 때의 장점

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