

#include "iostream"
using namespace std;
int func(int x) // int(int a)
{
	return x;
}

int func(int a, int b)
{
	return a + b;
}

int func(const char* s)
{
	return strlen(s);
}
//�������������
typedef int (Array)[10];

//����һ�� ��ָ����������ͣ�ָ������
typedef int (*pArray)[10];

//������һ��  ָ��  ���� ��ָ������ָ�����ͣ�
typedef int(*PFUNC)(int a); // int(int a)

class  AA
{
public:
	int m_a;
	int m_b;
public:

	int setVar(int a = 0, int b = 0)
	{
		m_a = a;
		m_b = b;
	}
	int setVar(int a)
	{
		m_a = a;
	}
	
};


int main()
{
	int c = 0;
	//�����Ͷ������
	PFUNC p = func;

	//Array my; //int my[10];
	//pArray pmy = NULL; //  Array *pMy;

	c = p(1);

	printf("c = %d\n", c);

	printf("Press enter to continue ...");
	getchar();	
	return 0;
}
