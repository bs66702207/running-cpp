//decltype不但可以获得准确的类型(不丢弃cv限定符)，而且不会跟原来变量有相同的表达式的值
int x = 0;
decltype(x) y = 1;			//y -> int
decltype(x + y) z = 0;		//z -> int

const int& i = x;
decltype(i) j = y;			//j -> const int &

const decltype(z) * p = &z;	//*p  -> const int, p  -> const int *
decltype(z) * pi = &z;		//*pi -> int,       pi -> int *
decltype(pi) * pp = &pi;	//*pp -> int *,		pp -> int * *
