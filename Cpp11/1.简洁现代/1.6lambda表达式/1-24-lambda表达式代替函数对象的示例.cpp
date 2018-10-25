#include <iostream>
#include <algorithm>    // std::for_eac
#include <vector>

//将vector中的偶数个数打印出来

class CountEven
{
	int& count_;

public:
	CountEven(int& count) : count_(count) {}

	void operator() (int val) {
		if(!(val & 1)) { //val % 2 == 0
			++ count_;
		}
	}
};

int main(void)
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	int even_count = 0;

	//C++
	for_each(v.begin(), v.end(), CountEven(even_count));
	std::cout << "The number of even is " << even_count << std::endl;


	even_count = 0;
	//C++11
	for_each(v.begin(), v.end(), [&even_count](int val)
	{
		if(!(val & 1)) { //val % 2 == 0
			++ even_count;
		}
	});
	std::cout << "The number of even is " << even_count << ", by lambda type" << std::endl;

	return 0;
}
