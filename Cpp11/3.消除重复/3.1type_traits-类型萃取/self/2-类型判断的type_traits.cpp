#include <iostream>
#include <type_traits>

//2.类型判断的type_traits
int main() {
	std::cout << "is_const:" << std::endl;
	std::cout << "int: " << std::is_const<int>::value << std::endl;//0
	std::cout << "const int: " << std::is_const<const int>::value  << std::endl;//1
	std::cout << "const int&: " << std::is_const<const int&>::value  << std::endl;//0
	std::cout << "const int*: " << std::is_const<const int*>::value  << std::endl;//0
	std::cout << "int* const: " << std::is_const<int* const>::value  << std::endl;//1
	return 0;
}
