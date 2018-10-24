#include <iostream>
#include <functional>
#include <vector>
#include <algorithm> //std::count_if

std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

using std::placeholders::_1;
//找出集合中大于5小于10的元素个数
//std::bind(std::greater<int>(), std::placeholders::_1, 5);
//std::bind(std::less_equal<int>(), std::placeholders::_1, 10);
int main(void)
{
	//std::bind(std::logical_and<bool>(), std::bind(std::greater<int>(), _1, 5), std::bind(std::less_equal<int>(), _1, 10));

	auto f1 = std::bind(std::logical_and<bool>(), std::bind(std::greater<int>(), _1, 5), std::bind(std::less_equal<int>(), _1, 10));
	int count1 = std::count_if(coll.begin(), coll.end(), f1);//6, 7, 8, 9, 10
	std::cout << count1 << std::endl;

	auto f2 = std::bind(std::logical_and<bool>(), std::bind(std::greater<int>(), _1, 5), std::bind(std::less<int>(), _1, 10));
	int count2 = std::count_if(coll.begin(), coll.end(), f2);//6, 7, 8, 9
	std::cout << count2 << std::endl;
	return 0;
}
