/**
多继承的二义性，B里有一个int k，base1和base2继承B，C继承base1和base2，会编译错误，
此时base1和base2必须class base1 : virtual public base；但是这种方式得出的是一个复杂的继承图，不推荐
  B
b1 b2
  C
*/

#include "iostream"
using namespace std;

class base
{
public:
	int k;

	void printI()
	{
		//cout<<i<<endl;
	}
protected:
private:

};

//class base1 : public base //build error
class base1 : virtual public base //build successful
{
public:
	int i;
	void printI()
	{
		cout<<i<<endl;
	}
protected:
private:

};

//class base2 : public base
class base2 : virtual public base
{
public:
	int j;
	void printJ()
	{
		cout<<j<<endl;
	}
protected:
private:
};

class  C : public base1, public base2
{
public:
protected:
private:
};

int main()
{

	C c1;
	c1.k = 100;//如果不加virtual，build error
	//c1.i = 10;
	//c1.j = 20;
	//c1.printI();
	//c1.printJ();
	return 0;
}
