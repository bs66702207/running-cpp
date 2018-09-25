template <typename T>
struct Foo {
	typename T type;
}

template <typename T>
class A {
	//...
};

int main(void)
{
	Foo<A<int>>::type xx;//编译出错
	return 0;
}

//我们需要用括号来写出让人看懂的代码
Foo<(100 >> 2)> xx;
