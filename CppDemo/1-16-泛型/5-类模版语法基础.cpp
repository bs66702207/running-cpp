#include <iostream>
using namespace std;

/**
定义类的实例时，必须要指明具体类型；
在继承时，必须要指明类型
*/
//定义一个类模板

template<typename T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void setA(T a)
	{
		this->a = a;
	}
	T getA()
	{
		return this->a;
	}
protected:
private:
	T a;
};

class BB : public AA<int>//继承时要把类模版指明具体类型
{
public:
	//BB(int a, int b) : AA(a) 
	BB(int a, int b) : AA<int>(a) 
	{
		this->b = b;
	}

private:
	int b;
};

int main()
{
	//要把类模板具体成类型后，才能定义变量
	AA<int> a(10);
	//AA b(10);//err

	BB b1(1, 2);
	return 0;
}
