//1.简单的type_traits
//编译期常量

//静态常量
template<typename Type>
struct GetLeftSize
{
	static const int value = 1;
};

//枚举变量
template<typename Type>
struct GetLeftSize
{
    enum{value = 1};
};

//c++11
template<typename Type>
struct GetLeftSize : std::integral_constant<int, 1>
{
};

//以上都可以通过GetLeftSize::value来获取
