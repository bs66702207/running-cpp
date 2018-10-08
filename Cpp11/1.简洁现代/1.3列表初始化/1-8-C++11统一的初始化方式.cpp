//C++98/03
int i_arr[3] = {1, 2, 3};
long l_arr[] = {1, 2, 3, 4};

struct A
{
	int x;
	int y;
} a = {1, 2};

class Foo
{
public:
	Foo(int) {}

private:
	Foo(const Foo &);
};

int main(void)
{
	Foo a1(123);
	Foo a2 = 123; //error: 'Foo::Foo(const Foo &)' is private

	//效果同a1
	Foo a3 = { 123 };
	Foo a4 { 123 };//C++11

	int a5 = { 3 };
	int a6 { 3 };//C++11

	return 0;
}

//C++11
int i_arr[3] {1, 2, 3}//普通数组
struct A
{
	int x;
	struct B
	{
		int i;
		int j;
	} b;
} a { 1, {2, 3} };//POD类型

int* a = new int { 123 };
double b = double { 12.12 };
int* arr = new int[3] {1, 2, 3};

//函数返回值初始化
struct Foo
{
	Foo(int, double) ()
};

Foo func(void)
{
	return ( 123, 321.0 );//Foo(123, 321.0)
}
