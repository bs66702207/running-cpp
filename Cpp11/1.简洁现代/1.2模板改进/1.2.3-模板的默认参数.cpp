//C++
template <typename T, typename U = int, U n = 11>
struct Foo
{
	//...
};

//C++却不支持函数的默认模板参数，但是C++11中支持这个功能了
template <typename T = int>
void func(void)//c++ error，c++11 yes
{
	//...
};

//模板参数的填充顺序是从左往右
template <typename R = int, typename U>
R func(U val)
{
	val
}

int main(void)
{
	func<long>(123);//返回值是long
	return 0;
}
