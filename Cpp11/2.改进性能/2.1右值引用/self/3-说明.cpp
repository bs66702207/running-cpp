/**
	实际上T&&并不是一定表示右值，它绑定的类型是未定的，既可能是左值又可能是右值。
*/

//1
template<typename T>
void f(T&& param);	//这里T的类型需要推导，所以&&是一个universal references，简称urs

f(10);			//10是右值
int x = 10;
f(x);			//x是左值

template<typename T>
class Test {
	...
	Test(Test&& rhs); //已经定义了一个特定的类型，没有类型推断
	... //&&是一个右值引用
};

void f(Test& param); //已经定义了一个确定的类型，没有类型推断，&&是一个右值引用

//2复杂一点的例子
template<typename T>
void f(std::vector<T>&& param);//右值引用，因为调用之前vector<T>中的推断类型已经确定了

template<typename T>
void f(const T&& param);//任何一点附加条件都会编程一个普通的右值引用，被const修饰了

//3
/**
	1)所有的右值引用叠加到右值引用上仍然还是一个右值引用
	2)所有的其他引用类型之间的叠加都将变成左值引用
*/
int&& var1 = 0;//var1的类型是int&&
auto&& var2 = var1;//var2存在类型推导，因此是一个universal references。这里auto&&最终会被推导为int&

int w1, w2;
auto&& v1 = w1;//v1是一个urs，它被一个左值初始化，所以它最终是一个左值
decltype(w1)&& v2 = w2;//v2是一个右值引用类型，但它被一个左值初始化，一个左值初始化一个右值引用类型是不合法的，build error，需要进行修改
decltype(w1)&& v2 = std::move(w2);//std::move可以将左值转换成右值
