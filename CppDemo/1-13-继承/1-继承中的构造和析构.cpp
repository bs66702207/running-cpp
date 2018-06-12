/**
1.类的public、private、protected是否可以使用表
			类的内部	类的外部	子类
public		可以		可以		可以
private		可以		不可以		不可以
protected	可以		不可以		可以

2.类继承方式
子类public继承父类，父类中protected在类的外部不能使用，子类内部可以使用，private都不能使用，其他说明见如下表格
不能的继承方式，让父类的成员变量和函数的控制属性发生变化
					public		protected	private
public方式继承		public		protected	private
protected方式继承	protected	protected	private
private方式继承		private		private		private
*/
#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;
class A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	
	virtual void pp()
	{
		cout<<"baba"<<endl;
	}
};

class B : public A
{
public:
	void print()
	{
//		cout<<"a = "<<a; //err
		cout<<"b = "<<b;
		cout<<"c = "<<endl;
	}
	
	void pp()
	{
		cout<<"erzi"<<endl;
	}
};

class C : protected A
{
public:
	void print()
	{
//		cout<<"a = "<<a; //err
		cout<<"b = "<<b;
		cout<<"c = "<<endl;
	}
};

class D : private A
{
public:
	void print()
	{
//		cout<<"a = "<<a; //err
		cout<<"b = "<<b<<endl; 
		cout<<"c = "<<c<<endl; 
	}
};

int main(int argc, char *argv[])
{
	A aa;
	B bb;
	C cc;
//	D dd;

	aa.c = 100; //ok
	bb.c = 100; //ok
//	cc.c = 100; //err 类的外部是什么含义
//	dd.c = 100; //err

	aa.set(1, 2, 3);
	bb.set(10, 20, 30);
//	cc.set(40, 50, 60); //ee protected
//	dd.set(70, 80, 90); //ee

	bb.print();
//	cc.print();
//	dd.print();

	cout<<"--------------------"<<endl;
	A *baba = new B();
	baba->pp();

	return 0;
}
