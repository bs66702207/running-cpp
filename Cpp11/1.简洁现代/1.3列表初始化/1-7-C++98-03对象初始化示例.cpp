// initializer list
int  i_arr[3] = {1, 2, 3};//普通数组

struct A
{
	int x;
	struct B
	{
		int i;
		int j;
	} b;
} a  { 1, {2, 3} };//POD类型

//拷贝初始化(copy-initialization)
int i = 0;

class Foo
{
public:
	Foo(int) {}
} foo = 123;//需要拷贝构造函数

//直接初始化(direct-initialization)
int j(0);
Foo bar(123);

//存在的问题：C++98/03种类繁多，没有统一的初始化方式
