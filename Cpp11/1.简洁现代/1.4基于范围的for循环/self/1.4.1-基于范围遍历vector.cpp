#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> arr = {1, 2, 3};
	//...

	for(auto &n : arr) {//用引用遍历，可以同时修改数据
		std::cout << n++ << std::endl;
	}

	for(auto n : arr) {
		std::cout << n++ << std::endl;
	}
	return 0;
}
