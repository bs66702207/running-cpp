#include "iostream"
using namespace std;
class DD
{
public:
	DD(int d) //DD�ж������вι��캯��
	{
		cout<<d<<endl;
		m_d = d;
	}
private:
	int m_d;
};

class EE
{
public:
	//���캯���ĳ�ʼ���б�
	//EE(int _a):d1(1),d2(2)
	EE(int _a):d2(1),d1(2)
	{
		a = _a;
		cout<<_a<<endl;
	}

protected:
private:
	int a;
	DD d1;   //���ձ��������˳��
	DD d2;
};
void main()
{
	EE e1(3);
	system("pause");
}