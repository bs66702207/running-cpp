#include "iostream"
using namespace std;

class Location
{
public:
	Location( int xx = 0 , int yy = 0 )
	{
		X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;
	}
	Location( const Location & p ) 	    //���ƹ��캯��
	{
		X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;  }
	~Location() { cout << X << "," << Y << " Object destroyed." << endl ; }
	int  GetX () { return X ; }		int GetY () { return Y ; }
private :   int  X , Y ;
} ;

void f ( Location  p )
{
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}
// void playobjmain()
// {
// 	Location A ( 1, 2 ) ;
// 	f ( A ) ;
// }
Location g()
{
	Location A(1, 2);//��ӡ Constructor Object.
	return A;//A��һ���ֲ����������ذ�A���Ƶ��������󣬵���copy���캯��
}
void main101()
{
	Location B;//��ӡ Constructor Object.
	B = g();//����������ִ��=������B�����û�ж���=��������ô��ִ��Ĭ�ϵ�=����

}

void main102()
{
	//g()����һ����������
	Location B = g();//�������������Bֱ��ȥ�����������Ծ��ٵ���һ��B�Ĺ��캯��
}

int main()
{
	main101();
	//B������A�������������󴴽�
	//A��������������������B����
	//system("pause");
	return 0;
}

