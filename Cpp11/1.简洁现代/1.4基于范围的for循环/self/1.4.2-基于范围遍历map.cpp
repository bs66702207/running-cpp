#include <iostream>
#include <map>

int main(void)
{
	std::map<std::string, int> mm =
	{
		{"1", 1}, {"2", 2}, {"3", 3}
	};

	for(auto ite = mm.begin(); ite != mm.end(); ++ite) {
		std::cout << ite->first << "->" << ite->second << std::endl;
	}

	for(auto& val : mm) {//基于范围的for循环
		std::cout << val.first << "->" << val.second << std::endl;
	}

	return 0;
}
