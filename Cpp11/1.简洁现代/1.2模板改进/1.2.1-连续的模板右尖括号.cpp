template <typename T>
struct Foo {
	typedef T type;
};

template <typename T>
class A {
	//...
};

int main(void)
{
	Foo<A<int>>::type xx;//g++编译出错，使用g++ -std=c++11可以编译过去
	return 0;
}

//我们需要用括号来写出让人看懂的代码
//Foo<(100 >> 2)> xx; //注意括号
