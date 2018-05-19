#include "iostream"
using namespace std;

/**1 */
//inline请求关键字， 内联编译，c++编译器不一定允许这种请求
//内联函数的函数体，需要和实现写在一块
//内联函数没有普通函数调用的开销比如压栈、跳转、返回，直接将函数体插入函数调用的地方

#define MYFUNC(a, b) ((a) < (b) ? (a) : (b))

//a 2  b 3
inline int myfunc(int a, int b)
{ 
	return a < b ? a : b;
}

int main101()
{
	int a = 1;
	int b = 3;
	//int c = myfunc(++a, b); //头疼兄弟 a=2、b=3、c=2
	int c = MYFUNC(++a, b);//===> ((++a) < (b) ? (++a) : (b));

	printf("a = %d\n", a); //3
	printf("b = %d\n", b);//3
	printf("c = %d\n", c); //3

	printf("Press enter to continue ...");
	system("pause");
	return 0;
}

/**2 */
void myPrint(int x = 3)//默认参数
{
	printf("x:%d \n", x);
}

void myPrint2( int z, int x = 3, int y = 4)//x配置了默认值，x后面的参数必须带默认值
{
	printf("x:%d \n", x);
}
void main_默认参数()
{
	myPrint(5);
	myPrint();
	system("pause");
}

/**3 */
//函数占位参数，占位参数还不用
int func(int a, int b, int )
{
	return a + b;
}

//默认参数和占位参数
int func2(int a, int b, int  = 0)
{
	printf("func2 ....begin\n");
	return a + b;
}

void main_默认参数和占位参数混搭()
{
	//func(1, 2, 3);
	func2(1, 2);
	func2(1, 2, 3);
	system("pause");
}