#include "iostream"
using namespace std;


struct AdvTeacher
{
	char name[32];
	int age ;
};

/** getTeacher01��getTeacher02��������һ����*/

//��ָ������ڴ�ռ�
void getTeacher01(AdvTeacher **p)
{
	AdvTeacher *tmp = (AdvTeacher *)malloc(sizeof(AdvTeacher));
	tmp->age = 30;
	*p = tmp;
}

//����� �ṹ�����ָ������� ָ�������
//p2�� t2 �ı���
void getTeacher02(AdvTeacher * &p2)
{
	p2 = (AdvTeacher *)malloc(sizeof(AdvTeacher));
	p2->age = 30;
}

//����������� ��ô myT3��copy��t3�������ﲻ���޸�age��Ŀ��
void getTeacher03(AdvTeacher &t3)
{
	t3.age = 11;
}

void main()
{
	AdvTeacher *t1 = NULL;
	AdvTeacher *t2 = NULL;
	getTeacher01(&t1);//����ָ�봫�ݽ��룬ûë��
	getTeacher02(t2);

	{
		AdvTeacher  myT3;
		myT3.age = 10;
		getTeacher03(myT3);

	}

	system("pause");
}