#include "iostream"
using namespace std;

//����1 ���������ý���myf2
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

int* myf3()//��myf2��𲻴�
{
	int a ;
	a = 12;
	return &a;
}

int main01()
{
	int b1 = myf1();	//b1=11, ok
	int b2 = myf2();	//b2=11, b2�ǻ������ͣ������ӵ�*a
	int &b3 = myf2();	//b3=���룬b3�����ã��ӵ���a��ַ������a������
	printf("b1:%d\n", b1);
	printf("b2:%d\n", b2);
	printf("b3:%d\n", b3); //b3��һ���������� c++�������������ִ�� *p 
	system("pause");
	return 0;
}

//����2��myf��a�ĳ�static�ͺ���
int& j()
{
	static int a ;//������static�Ϳ�����
	a = 10;
	printf("a:%d", a);
	return a;
}

int main02()
{
	int b1 = j(); //ok
	int b2 = j();  //������һ��ֵ�����ظ���b2
	int &b3 = j(); //b3 ����ֵ������
	printf("b1:%d\n", b1);
	printf("b2:%d\n", b2);
	printf("b3:%d\n", b3); //b3��һ���������� c++�������������ִ�� *p 
	system("pause");
	return 0;
}

//����3
//static int a  = 10; ��a���һ��״̬����
//a��ʼ����ʱ��10 ��ֻ��ʼ��һ��
//a = 11 
int& mygg()
{
	static int a  = 10;
	printf("a:%d", a);
	return a;
}

int main03()
{
	mygg() = 11;//��ӡa=10
	mygg();//��ӡa=11
	system("pause");
	return 0;
}

//����4
int& myA(int &a)
{
	a++;
	return a;
}
void main77()
{
	int b = 10;
	int b1 = myA(b); //ok
	int b2 = myA(b);  //������һ��ֵ�����ظ���b2
	int &b3 = myA(b); //b3 ����ֵ������
	printf("b1:%d\n", b1); //11
	printf("b2:%d\n", b2); //12
	printf("b3:%d\n", b3); //13
	system("pause");
}




