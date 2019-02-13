#include <iostream>

//c11模板定义
#if 0
template<typename T, typename... Args>
T* Instance(Args... args) {
	return new T(args...);
}
#endif
//利用forward进行完美转发，提升性能
template<typename T, typename... Args>
T* Instance(Args... args) {
	return new T(std::forward<Args>(args)...);
}

struct A
{
	A(int){}
};

struct B
{
	B(int, double){}
};

int main(void)
{
	A* pa = Instance<A>(1);
	B* pb = Instance<B>(1, 2);

	return 0;
}
