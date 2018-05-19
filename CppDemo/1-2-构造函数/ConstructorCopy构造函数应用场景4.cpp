#include "iostream"
using namespace std;

class Location
{
public:
	Location( int xx = 0 , int yy = 0 )
	{
		X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;
	}
	Location( const Location & p ) 	    //复制构造函数
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
	Location A(1, 2);//打印 Constructor Object.
	return A;//A是一个局部变量，返回把A复制到匿名对象，调用copy构造函数
}
void main101()
{
	Location B;//打印 Constructor Object.
	B = g();//将匿名对象执行=操作给B，如果没有定义=操作，那么就执行默认的=操作

}

void main102()
{
	//g()返回一个匿名对象
	Location B = g();//这个匿名对象有B直接去接收它，所以就少调用一个B的构造函数
}

int main()
{
	main101();
	//B创建，A创建，匿名对象创建
	//A析构，匿名对象析构，B析构
	//system("pause");
	return 0;
}

