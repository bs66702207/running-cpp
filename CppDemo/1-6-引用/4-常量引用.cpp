#include "iostream"
using namespace std;


struct Adv2Teacher
{
	char name[32];
	int age ;
};

//����������� ��ô myT3��copy��t3 
//  const Adv2Teacher * const t3
void getTeacher03(const Adv2Teacher &  t3)
{
	//ֻ�ܶ� ����д�൱�� const Adv2Teacher * const t3
	//t3.age = 100; //err
	printf("age:%d", t3.age);
}

//1 const���õ����ã��ñ�����ָ����ڴ�ռ�ֻ��
//2 ��const���ó�ʼ���������ַ���
//�ñ�����ʼ��const����
//

void main()
{
	//1 �ñ�����ʼ��const����
	int b = 10;
	const int &a = b;

	//a = 11; ����ͨ��aȥ����޸�b
	b = 12;

	//2 const���õĵڶ��ֳ�ʼ������
	//int &c = 10;//error
	const int &c = 10;
	printf("&c:%d\n", &c);
	system("pause");
}