#include <iostream> //std::cout
#include <functional> //std::bind

void call_when_even(int x, const std::function<void(int)>& f) { //void f(int)
	if(!(x & 1)) { //x % 2 == 0
		f(x);
	}
}

void output(int x) {
	std::cout << x << " ";
}

void output_add_2(int x) {
	std::cout << x + 2 << " ";
}

int main(void)
{
	{
		auto fr = std::bind(output, std::placeholders::_1);//std::placeholders::_1占位符，被传入的第一个参数所替代int x
		for(int i = 0; i < 10; ++i) {
			call_when_even(i ,fr);
		}
		std::cout << std::endl;
	}

	{
		auto fr = std::bind(output_add_2, std::placeholders::_1);
		for(int i = 0; i < 10; ++i) {
			call_when_even(i, fr);
		}
		std::cout << std::endl;
	}
	return 0;
}
