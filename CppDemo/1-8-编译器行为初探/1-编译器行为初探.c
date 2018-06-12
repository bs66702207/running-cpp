#include "iostream"

using namespace std;

class C1
{
public:
	int i; //4 
	int j; //4
	int k; //4
protected:
private:
}; //12

class C2
{
public:
	int i; //4
	int j; //4
	int k; //4
	
	static int m; //4
public:
	int getK() const { return k; } //4
	void setK(int val) { k = val; } //4

protected:
private:
}; //24  16 

struct S1
{
	int i;
	int j;
	int k;
}; //12

struct S2
{
	int i;
	int j;
	int k;
	static int m;
}; //16

int main()
{
	printf("c1:%d \n", sizeof(C1));//12
	printf("c2:%d \n", sizeof(C2));//12
	printf("s1:%d \n", sizeof(S1));
	printf("s2:%d \n", sizeof(S2));
	
	system("pause");
}

/**
C++类对象中的成员变量和成员函数是分开存储的
成员变量：
普通成员变量：存储于对象中，与struct变量有相同的内存布局和字节对齐方式
静态成员变量：存储于全局数据区中
成员函数：存储于代码段中。
问题出来了：很多对象公用一块代码？代码是如何区分具体对象的那？

换句话说：int getK() const { return k; }，代码是如何区分，具体obj1、obj2、obj3对象的k值？

1、C++类对象中的成员变量和成员函数是分开存储的。C语言中的内存四区模型仍然有效！
2、C++中类的普通成员函数都隐式包含一个指向当前对象的this指针。
3、静态成员函数、成员变量属于类
静态成员函数与普通成员函数的区别
静态成员函数不包含指向具体对象的指针
普通成员函数包含一个指向具体对象的指针
*/