#include <iostream>
#include <type_traits>
#include <memory>

//根据模板参数类创建对象时，要注意移除引用，下面的例子中，因为创建对象时，需要原始的类型，所以需要将可能的引用移除
template<typename T>
typename std::remove_reference<T>::type* Create()
{
	typedef typename std::remove_reference<T>::type U;
	return new U();
}


template <class T>
struct Construct
{
	typedef typename std::remove_reference<T>::type U;//移除可能的引用
	Construct() : m_ptr(new U){}

	typename std::add_lvalue_reference<U>::type Get() const//添加左值引用
	{
		*m_ptr = 100;  //特意加的一行，以防*m_ptr是个未定义的值
		return *m_ptr.get();
	}

private:
	std::unique_ptr<U> m_ptr;
};

int main(void)
{
	Construct<int> c;
	int a = c.Get();

	std::cout << a << std::endl;

	return 0;
}
