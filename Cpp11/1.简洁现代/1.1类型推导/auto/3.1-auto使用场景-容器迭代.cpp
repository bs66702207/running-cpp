//C++11之前，定义了一个stl容器以后，在遍历的时候常常会这样写代码:
#include <map>
int main(void)
{
	std::map<double, double> resultMap;

	//...

	std::map<double,double>::iterator it = resultMap.begin();//太长了
	for(; it != resultMap.end(); ++it) {
		//do something
	}

	return 0;
}

//使用auto后的写法
int main(void)
{
	std::map<double, double> resultMap;

	//...

	for(auto it = resultMap.begin(); it != resultMap.end(); ++it) {
		//do something
	}

	return 0;
}

//再看一个例子，在一个unodered_multimap中查找一个范围，代码如下:
#include <map>

int main(void)
{
	std::unordered_multimap<int, int>resultMap;

	//...

	std::pair<std::unordered_multimap<int, int>::iterator, std::unordered_multimap<int, int>::iterator> range = resultMap.equal_range(key);//大概知道std::pair其实就够了

	return 0;
}

//使用auto后的写法
int main(void)
{
	std::unordered_multimap<int, int> resultMap;

	//...

	auto range = resultMap.equal_range(key);

	return 0;
}
