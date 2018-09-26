//C++
typedef unsigned int uint_t;

void func(unsigned int);
void func(uint_t); //error: redefinitio

typedef std::map<std::string, int> map_int_t;
typedef std::map<std::string, std::string> map_str_t;
//我们需要一个固定以std::string为key的map，它可以映射到int或另一个std::string

//C++方案
template <typename Val>
struct str_map {
	typedef std::map<std:string, Val> type;
};
str_map<int>::type map1;

//C++11方案 使用using的写法
template <typename Val>
using str_map_t = std::map<std::string, Val>;
str_map_t<int> map1;

//下面的写法作用是等价的
//重定义 unsigned int
typedef unsigned int uint_t;
using uint_t = unsigned int;
//重定义 std::map
typedef std::map<std::string, int> map_int_t;
using map_int_t = std::map<std::string, int>;

//使用typedef会增加代码阅读的难度
typedef void (*func_t) (int, int);
//使用using阅读起来更加清晰
using func_t = void (*)(int, int);

//再看一个例子简写易读的比对
//C++98/03
template <typename T>
struct func_t {
	typedef void (*type)(T, T);
};
func_t<int>::type xx_1;

//C++11
template <typename T>
using func_t = void (*)(T, T);
func_t<int> xx_2;

//这里注意using的作用和typedef一样的，是个别名
void foo(void (*func_call)(int, int));
void foo(func_t<int> func_call); //error: redefinitio，无法实现重载，因为跟上面是等价的

//使用using可以定义任何模板表达方式，即“模板别名”
template <typename T>
using type_t = T;
//...
type_t<int> i;
