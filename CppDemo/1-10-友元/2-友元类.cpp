/**A的友元类，可以修改A中私有变量*/

#include "iostream"                                                                                           
#include "stdio.h"
using namespace std;

class A
{ 
	friend class B;
public:
	void Display() {cout << x << endl;} ;
private:
	int x ;
};

class  B
{ 
public:
	void Set (int i) {Aobject.x = i;} 
	void Display() {Aobject.Display();} 
private:
	A Aobject;
};
int main()
{
	B Bobject;
	Bobject.Set(100);
	Bobject.Display();
	return 0;
}
