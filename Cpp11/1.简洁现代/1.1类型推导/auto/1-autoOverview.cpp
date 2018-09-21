//使用auto声明的变量必须马上初始化，以让编译器推断出它的实际类型，并在编译时将auto占位符替换为真正的类型

//1.auto初探
auto x = 5;					//OK: x是int类型
auto pi = new auto(1);		//OK: pi被推导为int*，auto(1)被推导为int(1)
const auto *v = &x, u = 6;	//OK: v是const int* 类型，u是const int类型
static auto y = 0.0;		//OK: y是double类型
auto int r;					//error: auto不再表示存储类型指示符
auto s;						//error: auto无法推导出s的类型

//2.auto推导规则
//cv限定符：const、volatile
int x = 0;
auto* a = &x;	//a -> int*, auto被推导为int
auto  b = &x;	//b -> int*，auto被推导为int*
auto& c = x;	//c -> int&，auto被推导为int
auto  d = c;	//d -> int， auto被推导为int

const auto e = x;	//e -> const int
const f = e;		//f -> int

const auto& g = x;	//g -> const int&
auto& h = g;		//h -> const int& auto+引用时将保留const

const auto *m = &x; //m -> const int*
auto* n = m;		//n -> const int*

//小结：
//2.1 当不声明为指针或引用时，auto的推导结果和初始化表达式摒弃引用和cv限定符后类型一致，即就是源类型
//2.2 当声明为指针或引用时，auto的推导结果将保持初始化表达式的cv属性

//函数模板跟auto很相似，注意的是auto并不能用于函数参数，下面的代码用于加强下理解
template <typename T> void func(T  x) {}	//T -> auto
template <typename T> void func(T* x) {}	//T -> auto *
template <typename T> void func(T& x) {}	//T -> auto &

template <typename T> void func(const T  x) {}	//const T  -> const auto
template <typename T> void func(const T* x) {}	//const T* -> const auto*
template <typename T> void func(const T& x) {}	//const T& -> const auto&
