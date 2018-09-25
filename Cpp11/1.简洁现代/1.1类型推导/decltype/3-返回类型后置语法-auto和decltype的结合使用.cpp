//我们需要获得add返回值
//方法一
template <typename R, typename T, typename U>
R add(T t, U u) {
	return t+u;
}
int a = 1; float b = 2.0;
auto c = add<decltype(a + b)>(a, b);//不方便

//方法二：行不通
template <typename T, typename U>
decltype(t + u) add(T t, U u) {//error: t、u未定义
	return t+u;
}

//方法三：代码太难读懂
template <typename T, typename U>
decltype((*(T*)0) + (*(U*)0)) add(T t, U u) {
	return t+u;
}

//方法四：auto和decltype结合起来
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	return t + u;
}

//方法四的优势，方法一是无法胜任的
int & foo(int& i);
float foo(float& f);

template <typename T>
auto func(T& val) -> decltype(foo(val)) {
	return foo(val);
}
