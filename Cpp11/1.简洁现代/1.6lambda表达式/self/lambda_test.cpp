#include <iostream>
#include <functional>
#include <vector>
#include <algorithm> //std::count_if

int main(void)
{
	int a = 0;
	auto f = [=]{ return a; };	//按值捕获外部变量
	auto g = [&]{ return a; };	//按引用捕获外部变量
	a += 1;
	std::cout << f() << std::endl;	//0
	std::cout << g() << std::endl;	//1

	a = 0;
//	auto f1 = [=]{ return a++; };	//error, 修改按值捕获的外部变量
	auto f2 = [=]() mutable { return a++; };	//OK, mutable
	std::cout << f2() << std::endl;	//0
	std::cout << f2() << std::endl;	//1

//在1.5.3的1-24-使用组合bind函数.cpp中，使用std::bind实现了计算vector中大于5小于等于10元素个数的功能，代码非常的长
//lamdba可以轻松实现此功能, 闭包
	std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int count = std::count_if(coll.begin(), coll.end(), [](int x){return x > 5 && x <= 10;});
	std::cout << "the count of vector in (5, 10] = " << count << std::endl;
//查找大于10的个数
	count = std::count_if(coll.begin(), coll.end(), [](int x){return x > 10;});
	std::cout << "the count of vector in (10, .) = " << count << std::endl;

//查找小于10的个数
	count = std::count_if(coll.begin(), coll.end(), [](int x){return x < 10;});
	std::cout << "the count of vector in (., 10) = " << count << std::endl;

	return 0;
}
