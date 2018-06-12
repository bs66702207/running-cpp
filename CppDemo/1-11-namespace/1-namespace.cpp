/**
namespace概念
在C语言中只有一个全局作用域
在C语言中只有一个全局作用域
std是c++标准命名空间，c++标准程序库中的所有标识符都被定义在std中，比如标准库中的类iostream、vector
可以更好地控制标识符的作用域
1）当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std；这样才能正确使用cout。若不引入using namespace std ,需要这样做。std::cout。
2）c++标准为了和C区别开，也为了正确使用命名空间，规定头文件不使用后缀.h。
3）C++命名空间的定义：	namespace name {  …  }
4）using namespace NameSpaceA;
5）namespce定义可嵌套。
*/

namespace NameSpaceA
{
	int a = 0;
}

namespace NameSpaceB
{
	int a = 1;

	namespace NameSpaceC
	{
		struct Teacher
		{
			char name[10];
			int age;
		};
	}
}

int main()
{
	using namespace NameSpaceA;
	using NameSpaceB::NameSpaceC::Teacher;

	printf("a = %d\n", a);
	printf("a = %d\n", NameSpaceB::a);

	Teacher t1 = {"aaa", 3};

	printf("t1.name = %s\n", t1.name);
	printf("t1.age = %d\n", t1.age);

	system("pause");
	return 0;
}
