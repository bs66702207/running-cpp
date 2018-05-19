#include "iostream"
using namespace std;

//案例1 变量和引用接收myf2
int myf1()
{
	int a ;
	a = 10;
	return a;
}

int& myf2()
{
	int a ;
	a = 11;
	printf("a:%d", a);
	return a;
}

int* myf3()//跟myf2差别不大
{
	int a ;
	a = 12;
	return &a;
}

int main01()
{
	int b1 = myf1();	//b1=11, ok
	int b2 = myf2();	//b2=11, b2是基础类型，变量接的*a
	int &b3 = myf2();	//b3=乱码，b3是引用，接的是a地址，但是a会销毁
	printf("b1:%d\n", b1);
	printf("b2:%d\n", b2);
	printf("b3:%d\n", b3); //b3是一个引用类型 c++编译器会帮我们执行 *p 
	system("pause");
	return 0;
}

//案例2，myf的a改成static就好了
int& j()
{
	static int a ;//换成了static就可以了
	a = 10;
	printf("a:%d", a);
	return a;
}

int main02()
{
	int b1 = j(); //ok
	int b2 = j();  //返回了一个值，返回赋给b2
	int &b3 = j(); //b3 返回值的引用
	printf("b1:%d\n", b1);
	printf("b2:%d\n", b2);
	printf("b3:%d\n", b3); //b3是一个引用类型 c++编译器会帮我们执行 *p 
	system("pause");
	return 0;
}

//案例3
//static int a  = 10; 把a变成一个状态变量
//a初始化的时候10 ，只初始化一次
//a = 11 
int& mygg()
{
	static int a  = 10;
	printf("a:%d", a);
	return a;
}

int main03()
{
	mygg() = 11;//打印a=10
	mygg();//打印a=11
	system("pause");
	return 0;
}

//案例4
int& myA(int &a)
{
	a++;
	return a;
}
void main77()
{
	int b = 10;
	int b1 = myA(b); //ok
	int b2 = myA(b);  //返回了一个值，返回赋给b2
	int &b3 = myA(b); //b3 返回值的引用
	printf("b1:%d\n", b1); //11
	printf("b2:%d\n", b2); //12
	printf("b3:%d\n", b3); //13
	system("pause");
}




