#include "iostream"
using namespace std;


void myprintf(int a)
{
	printf("a:%d\n ", a );
}
void myprintf(double a)
{
	printf("a:%f\n ", a );
}

void myprintf(char *p, int b)
{
	printf("p:%s, b:%d", p, b);
}

void myprintf(int b, char *p)
{
	printf("b:%d, p:%s", b, p);
}

//�����������Ͳ��Ǻ������ص��жϱ�׼
void myprintf(int a, int b)
{
	printf("a:%d, b:%d\n", a, b);
}

//�����������Ͳ��Ǻ������ص��жϱ�׼
//�������������� ����Ĭ�ϲ���
//��һ��
int  myprintf(int a, int b, int c=0)
{
	printf("a:%d, b:%d c:%d \n", a, b, c);
	return a;
}


void main121()
{
	int a = 1;
	//myprintf(a);
	//myprintf(1, 2); //������
	system("pause");
}