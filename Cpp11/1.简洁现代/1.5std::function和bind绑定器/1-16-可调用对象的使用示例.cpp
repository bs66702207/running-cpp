/**
在C++中，存在“可调用对象(Callable Objects)”这么一个概念。准确来说，可调用对象有如下几种定义
1) 是一个函数指针。
2) 是一个具有operator()成员函数的类对象(仿函数)。
3) 是一个可被转换为函数指针的类对象。
4) 是一个类成员(函数)指针。
*/

#include <iostream>

void func(void) {
	std::cout<<"函数指针"<<std::endl;
}

struct Foo
{
	void operator()(void) {
		std::cout<<"仿函数"<<std::endl;
	}
};

struct Bar
{
	using fr_t = void(*) (void);

	static void func(void) {
		std::cout<<"可被转换为函数指针的类对象"<<std::endl;
	}

	operator fr_t(void) {
		return func;
	}
};

struct A
{
	int a_;
	void mem_func(void) {
		std::cout<<"类成员函数指针"<<std::endl;
	}
};

int main(void)
{
	void(*func_ptr)(void) = &func;//1. 函数指针
	func_ptr();

	Foo foo;//2.仿函数
	foo();

	Bar bar;//3.可被转换为函数指针的类对象
	bar();

	void (A::*mem_func_ptr)(void) = &A::mem_func;//4.类成员函数指针
	int A::*mem_obj_ptr = &A::a_;//类成员指针

	A aa;
	(aa.*mem_func_ptr)();
	aa.*mem_obj_ptr = 123;

	return 0;
}
