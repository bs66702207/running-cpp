/**
编译器会将已命名的右值引用视为左值，而将未命名的右值引用视为右值，请看下面例子
*/
#include <iostream>
void PrintValue(int& i) {
	std::cout << "lvalue : " << i << std::endl;
}

void PrintValue(int&& i) {
	std::cout << "rvalue : " << i << std::endl;
}

void Forward(int&& i) {
	PrintValue(i);
}

int main()
{
	int i = 0;
	PrintValue(i);
	PrintValue(1);
	Forward(2);
	return 0;
}

/*
lvalue : 0
rvalue : 1
lvalue : 2 Forware接收的是一个右值，但是传递给PrintValue时，i又变成了左值
*/
