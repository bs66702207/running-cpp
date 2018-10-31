#include <iostream>
using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A
{
	A() {
		cout << "construct: " << ++g_constructCount << endl;
	}

	A(const A& a) {
		cout << "copy construct: " << ++g_copyConstructCount << endl;
	}

	~A() {
		cout << "destruct: " << ++g_destructCount << endl;
	}
};

A GetA() {
	return A();
}

int main()
{
	A&& a = GetA();
	return 0;
}

/**
-fno-elide-constructors 关闭返回值优化效果
construct: 1
copy construct: 1 少了一次拷贝构造函数的调用，原因在于右值引用延长临时右值的生命周期
destruct: 1
destruct: 2

无编译选项
construct: 1
destruct: 1
*/
