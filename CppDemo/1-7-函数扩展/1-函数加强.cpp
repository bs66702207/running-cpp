#include "iostream"
using namespace std;

/**1 */
//inline����ؼ��֣� �������룬c++��������һ��������������
//���������ĺ����壬��Ҫ��ʵ��д��һ��
//��������û����ͨ�������õĿ�������ѹջ����ת�����أ�ֱ�ӽ���������뺯�����õĵط�

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
	//int c = myfunc(++a, b); //ͷ���ֵ� a=2��b=3��c=2
	int c = MYFUNC(++a, b);//===> ((++a) < (b) ? (++a) : (b));

	printf("a = %d\n", a); //3
	printf("b = %d\n", b);//3
	printf("c = %d\n", c); //3

	printf("Press enter to continue ...");
	system("pause");
	return 0;
}

/**2 */
void myPrint(int x = 3)//Ĭ�ϲ���
{
	printf("x:%d \n", x);
}

void myPrint2( int z, int x = 3, int y = 4)//x������Ĭ��ֵ��x����Ĳ��������Ĭ��ֵ
{
	printf("x:%d \n", x);
}
void main_Ĭ�ϲ���()
{
	myPrint(5);
	myPrint();
	system("pause");
}

/**3 */
//����ռλ������ռλ����������
int func(int a, int b, int )
{
	return a + b;
}

//Ĭ�ϲ�����ռλ����
int func2(int a, int b, int  = 0)
{
	printf("func2 ....begin\n");
	return a + b;
}

void main_Ĭ�ϲ�����ռλ�������()
{
	//func(1, 2, 3);
	func2(1, 2);
	func2(1, 2, 3);
	system("pause");
}