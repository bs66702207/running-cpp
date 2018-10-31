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
	A a = GetA();
	return 0;
}

/**
-fno-elide-constructors 关闭返回值优化效果
construct: 1
copy construct: 1 GetA()函数内部创建的对象返回后构造一个临时对象调用的第一次拷贝构造函数
destruct: 1
copy construct: 2 构造main中的a调用的第二次拷贝构造函数
destruct: 2
destruct: 3

无编译选项，编译器会将临时对象优化掉，但这个不是C++标准
construct: 1
destruct: 1
*/
