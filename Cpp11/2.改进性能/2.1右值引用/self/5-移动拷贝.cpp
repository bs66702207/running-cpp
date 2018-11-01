/**
	在C++中，有拷贝构造函数的概念，是为了处理堆内存上的数据而实现的"深拷贝"，但是有些场景使用移动拷贝就够了，C++11提供了这个特性
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
class A
{
public:
	A(int i):m_ptr(new int(i))
	{
		n = rand();
		cout << "construct: " << this << ", " << this->m_ptr << ", " << this->n << endl;
	}

	A(const A& a):m_ptr(new int(*a.m_ptr)) //深拷贝
	{
		cout << "copy construct" << endl;
	}

	A(A&& a):m_ptr(a.m_ptr)
	{
		cout << "move construct:" << this->m_ptr << endl;
	}

	~A()
	{
		cout << "destruct:" << this << ", " << this->m_ptr << ", " << this->n << endl;
		m_ptr = nullptr;
		delete m_ptr;
	}

	int *m_ptr;
	int n;
};


A Get(bool flag) {
	A a(1);
	A b(2);
	if(flag)
		return a;
	else
		return b;
}

int main()
{
	A a = Get(false);
	cout << "*a.mptr = " << *(a.m_ptr) << " , a.mptr = " << a.m_ptr << endl;
}
