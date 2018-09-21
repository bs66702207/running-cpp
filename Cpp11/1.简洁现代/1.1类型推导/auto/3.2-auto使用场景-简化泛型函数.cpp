//利用泛型函数对所有静态get方法集中处理
class Foo
{
public:
	static int get(void) {
		return 0;
	}
};

class Bar
{
public:
	static const char* get(void) {
		return "0";
	}
};


//只是用模板的方法
template <class A, class T>
void func() {
    T val = A::get();
    cout<<val<<endl;
}

int main(void)
{
    func<Foo, int>();
    func<Bar, const char*>();
    return 0;
}

//使用auto，少了一个get返回类型判断的模板参数
template <class A>
void func(void) {
	auto val = A::get();

	//...
}

int main(void)
{
	func<Foo>();
	func<Bar>();
	return 0;
}
