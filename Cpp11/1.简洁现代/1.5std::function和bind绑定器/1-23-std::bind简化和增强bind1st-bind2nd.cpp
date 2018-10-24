#include <iostream>
#include <functional>
#include <vector>
#include <algorithm> //std::count_if

std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int main(void)
{
	//查找元素值大于10的元素的个数
	int count_1 = std::count_if(coll.begin(), coll.end(), bind1st(std::less<int>(), 10));
	std::cout << count_1 << std::endl;

	//查找元素值小于10的元素的个数
	int count_2 = std::count_if(coll.begin(), coll.end(), bind2nd(std::less<int>(), 10));
	std::cout << count_2 << std::endl;

	/**bind方法实现*/
	using std::placeholders::_1;

	//查找元素值大于10的元素的个数
	count_1 = std::count_if(coll.begin(), coll.end(), bind(std::less<int>(), 10, _1));
	std::cout << count_1 << std::endl;

	//查找元素值小于10的元素的个数
	count_2 = std::count_if(coll.begin(), coll.end(), bind(std::less<int>(), _1, 10));
	std::cout << count_2 << std::endl;

	return 0;
}
