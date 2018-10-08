#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> arr = {1, 2, 3, 4, 5};

	for(auto &val : arr) {
		std::cout << val << std::endl;
		//arr.push_back(0);//扩大容器，书中的32位mingw4.8这么使用会有错误
	}

	std::cout << "===============================================" << std::endl;
	//建议的做法，手写一个范围迭代，避免每次都去调用end()，迭代目的达到了，但是这个扩大有些多。。。

	auto && __range = (arr);
	for(auto __begin = __range.begin(), __end = __range.end(); __begin != __end;  ++__begin) {
		auto val = * __begin;
		std::cout << val << std::endl;
		arr.push_back(0);//扩大容器
	}

	std::cout << "===============================================" << std::endl;
	for(auto &val : arr) {
		std::cout << val << std::endl;
	}
	
	return 0;
}
