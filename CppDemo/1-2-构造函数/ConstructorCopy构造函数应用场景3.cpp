#include "iostream"
using namespace std;

class Location
{
public:
	Location( int xx = 0 , int yy = 0 )
	{X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;}

    Location( const Location & p ) 	    //复制构造函数
	{X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;  }

	~Location() { cout << X << "," << Y << " Object destroyed." << endl ; }
	int  GetX () { return X ; }
	int GetY () { return Y ; }

private :   int  X , Y ;
} ;
void f ( Location  p )//形参p将调用拷贝构造函数，而且p也要进行析构函数调用
{
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}
void playobjmain()
{
	Location A ( 1, 2 ) ;//执行有参构造函数
	f ( A ) ;//实参A传递进去
}

int main()
{
	playobjmain();
	//system("pause");
	return 0;
}

