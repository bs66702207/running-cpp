class FooVector
{
	std::vector<int> content_;
public:
	FooVector(std::initializer_list<int> list)
	{
		for(auto it = list.begin(); it != list.end(); ++it) {
			content_.push_back(*it);
		}
	}
};

class FooMap
{
	std::map<int, int> content_;
	using pair_t = std::map<int, int>::value_type;
public:
	FooMap(std::initializer_list<pair_t> list)
	{
		for(auto it = list.begin(); it != list.end(); ++it) {
			content_.insert(*it);
		}
	}
};

FooVector foo_1 = { 1, 2, 3, 4, 5 };
FooMap foo_2 = { { 1, 2 }, { 3, 4 }, {5, 6 } };

//std::initializer_list不仅可以进行自定义容器类型初始化，还可以用来传递同类型的数据集合
void func(std::initializer_list<int> l) {
	for(auto it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

int main(void)
{
	func({});//一个空集合
	func({ 1, 2, 3 });//传递{ 1, 2, 3 }
	return 0;
}
