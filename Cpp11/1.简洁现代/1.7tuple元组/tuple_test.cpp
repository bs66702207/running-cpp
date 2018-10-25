#include <iostream>
#include <functional>
#include <vector>
#include <algorithm> //std::count_if

using namespace std;

int main(void)
{
	int index, index_;
	std::string name, name_;
	int age, age_;

	std::tuple<int, std::string, int> mytp = std::make_tuple(0, "zhangsan", 20);//构造一个tuple
	std::tie(index, name, age) = mytp;//unpack
	std::cout << "index contains: " << index << std::endl;
	std::cout << "name contains: " << name << std::endl;
	std::cout << "age contains: "<< age <<std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	index_ = std::get<0>(mytp);
	name_ = std::get<1>(mytp);
	age_ = std::get<2>(mytp);
	std::cout << "index_ contains: " << index_ << std::endl;
	std::cout << "name_ contains: " << name_ << std::endl;
	std::cout << "age_ contains: "<< age_ <<std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	std::tuple<int, std::string, float> t1(10, "Test", 3.14);
	int n = 7;
	auto t2 = std::tuple_cat(t1, std::make_pair("Foo", "bar"), t1, std::tie(n));
	n = 10;

	cout << std::get<0>(t2)<< " ";
	cout << std::get<1>(t2)<< " ";
	cout << std::get<2>(t2)<< " ";
	cout << std::get<3>(t2)<< " ";
	cout << std::get<4>(t2)<< " ";
	cout << std::get<5>(t2)<< " ";
	cout << std::get<6>(t2)<< " ";
	cout << std::get<7>(t2)<< " ";
	cout << std::get<8>(t2) << endl;

	return 0;
}
