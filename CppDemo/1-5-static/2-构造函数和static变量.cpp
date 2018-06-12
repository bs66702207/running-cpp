//构造函数里不能放static变量，static变量还是需要在外部初始化
#include<iostream>
using std::cout;
using namespace std;

class A
{
public:
	A()
	{
		//cout<<&c)<<endl;//build error
		//cout<<&(A::c)<<endl;//build error
		//cout<<&(A::c)<<endl;//build error
	}
	int a;
	static int c;
	
	//void mm() //build successful
	static void mm()//build successful
	{
		cout<<&(A::c)<<endl;
	}
protected:
	int b;
private:

};

class B : public A
{
public:
	B()
	{
		//cout<<&B::c;
//		cout<<c;
	}
	static int c;

	int a;
	static void mm()
	{
		cout<<&(B::c)<<endl;
	}
protected:
	int b;
private:

};

int A::c = 1;
int B::c = 2;

int main()
{ 
	//cout<<sizeof(A)<<endl;
	//cout<<sizeof(B);
	B b;
	b.A::mm();
	b.mm();
	cout<<A::c<<endl;
	cout<<B::c<<endl;
	cout<<b.c<<endl;
	return 0;
}


