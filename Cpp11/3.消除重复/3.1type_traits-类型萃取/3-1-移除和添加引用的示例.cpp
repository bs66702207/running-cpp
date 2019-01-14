#include <iostream>
#include <type_traits>
#include <memory>

//����ģ������ഴ������ʱ��Ҫע���Ƴ����ã�����������У���Ϊ��������ʱ����Ҫԭʼ�����ͣ�������Ҫ�����ܵ������Ƴ�
template<typename T>
typename std::remove_reference<T>::type* Create()
{
	typedef typename std::remove_reference<T>::type U;
	return new U();
}


template <class T>
struct Construct
{
	typedef typename std::remove_reference<T>::type U;//�Ƴ����ܵ�����
	Construct() : m_ptr(new U){}

	typename std::add_lvalue_reference<U>::type Get() const//�����ֵ����
	{
		*m_ptr = 100;  //����ӵ�һ�У��Է�*m_ptr�Ǹ�δ�����ֵ
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
