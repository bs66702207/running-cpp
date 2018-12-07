#include <iostream>
#include <type_traits>

class A {};
class B : public A {};
class C {};

int main()
{
	//在编译期判断类型是否相同
	std::cout << std::is_same<int, int>::value <<"\n"; //1
	std::cout << std::is_same<int, unsigned int>::value <<"\n"; //0
	std::cout << std::is_same<int, signed int>::value <<"\n"; //1

	//在编译期判断类型是否为前者是否是后者的基类
	std::cout << std::is_base_of<A, B>::value<<"\n";//1
	std::cout << std::is_base_of<B, A>::value<<"\n";//0
	std::cout << std::is_base_of<C, B>::value<<"\n";//0

	//判断前面的参数类型能否转换为后面的模板参数类型
	bool b2a = std::is_convertible<B*, A*>::value;
	bool a2b = std::is_convertible<A*, B*>::value;
	bool b2c = std::is_convertible<B*, C*>::value;

	std::cout << std::boolalpha;
	std::cout << b2a << '\n';
	std::cout << a2b << '\n';
	std::cout << b2c << '\n';
}
