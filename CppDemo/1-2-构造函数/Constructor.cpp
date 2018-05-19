#include "iostream"
using namespace std;
//隐式 或 显示 构造函数 析构函数
//
class Test
{
public:

	//有参构造函数
	Test(int a)
	{
		m_a = a;
	}
	//无参数构造函数
	Test()
	{
		m_a = 0;
	}
	//四种应用场景
	//赋值构造函数 copy构造函数,如果没有它，系统会默认构造一个copy构造函数，执行浅拷贝，即变量赋值
	Test(const Test &obj)//这个里面什么都没做
	{
		cout<<"nihao"<<endl;
	}

	~Test()
	{
		cout<<"byebye"<<endl;
	}	

public:
	void print()
	{
		cout<<"m_a"<<m_a<<endl;
	}
protected:
private:
	int m_a;
};

class n{};



int main()
{
/***** 有参构造函数的三种方法调用 *****/
	//括号法
/*	Test t1(10); //c++编译器自动调用这个类的有参构造函数
	t1.print();//10
	//等号法
	Test t2 = 20; //c++编译器自动调用这个类的有参构造函数
	t2.print();//20*/
	//手工法
	Test t3 = Test(30);//程序员手工的调用构造函数 进行对象初始化
	t3.print();//30
/***** 有参构造函数的三种方法调用 *****/

//赋值构造函数和=操作是两个不同的概念
//第一个场景
	Test t4 = t3;//t4被创建，并且调用copy构造函数
	t4.print();
//第二个场景
	Test t5(t3);//t5被创建，并且调用copy构造函数
	t5.print();
//第三和第四个场景见其他文件
	


/*	Test *t6 = &t3;
	t6->print();*/
	
//	Test *t7 = new Test();
//	delete t7;

	cout<<"sizeof(Test)="<<sizeof(Test)<<endl;
	cout<<"sizeof(n)="<<sizeof(n)<<endl;

	return 0;

}
