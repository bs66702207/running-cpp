#include <vector>

template <class ContainerT>
class Foo
{
	typename ContainerT::iterator it_; //类型定义可能右问题
public:
	void func(ContainerT& container) {
		it_ = container.begin();
	}
	//...
};

int main(void)
{
	typedef const std::vector<int> container_t;
	container_t arr;

	Foo<container_t> foo;//const 应该是用const_iterator
	foo.func(arr);

	return 0;
}

//C++98/03解决方式
template <class ContainerT>
class Foo
{
	typename ContainerT::const_iterator it_;
public:
	void func(const ContainerT& container) {
		it_ = container.begin();
	}
	//...
}

//dectype方式
template <class ContainerT>
class Foo
{
	decltype(ContainerT().begin()) it_;
public:
	void func(COntainerT& container) {
		it_ = container.begin();
	}
	//...
};

//value_type
vector<int> v;
//...
decltype(v)::value_type i = 0;

//标准库举例
typedef decltype(nullptr) nullptr_t;
typedef decltype(sizeof(0)) size_t;
