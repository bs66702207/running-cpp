class Foo
{
public:
	static const int Number = 0;
	int x;
};

int n = 0;
volatile const int & x = n;

decltype(n) a = n;				// a -> int
decltype(x) b = n;				// b -> volatile const int &

decltype(Foo::Number) c = 0;	// c -> const int

Foo foo;
decltype(foo.x) d = 0;			// d -> int，类访问表达式

//带括号的表达式和加法运算表达式
struct Foo { int x; };
const Foo foo = Foo();

decltype(foo.x)		a = 0;		//a -> int
decltype((foo.x))	b = a;		//b -> const int &，括号表达式返回的一个左值

int n = 0, m = 0;
decltype(n + m)  c = 0;			//c -> int
decltype(n += m) d = c;			//d -> int &，+=返回的是一个左值
