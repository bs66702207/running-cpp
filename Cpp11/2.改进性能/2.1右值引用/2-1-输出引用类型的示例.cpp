#include <type_traits>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <iostream>

template <class T>
std::string type_name() {
	typedef typename std::remove_reference<T>::type TR;
	std::unique_ptr<char, void(*)(void*)> own
		(
#ifndef __GUNC__
nullptr,
#else
abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
#endif
		std::free
		);
	std::string r = own != nullptr ? own.get() : typeid(TR).name();
	if(std::is_const<TR>::value)
		r += " const";
	if(std::is_volatile<TR>::value)
		r += " volatile";
	if(std::is_lvalue_reference<T>::value)
		r += "&";
	else if(std::is_rvalue_reference<T>::value)
		r += "&&";
	return r;
}

template<typename T>
void Func(T&& t) {
	std::cout << type_name<T>() << std::endl;
}

void TestReference()
{
	std::string str = "test";
	Func(str);//l
	Func(std::move(str));//r，将一个左值转换成右值
}

int main()
{
	TestReference();
	return 0;
}
