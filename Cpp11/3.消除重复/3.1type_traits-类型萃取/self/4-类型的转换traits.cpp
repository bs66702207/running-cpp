#include <iostream>
#include <type_traits>
using namespace std;
//P93
int main()
{
	//添加和移除const、reference
	cout << std::is_same<const int, add_const<int>::type>::value << endl;
	cout << std::is_same<int, remove_const<const int>::type>::value << endl;
	cout << std::is_same<int&, add_lvalue_reference<int>::type>::value << endl;
	cout << std::is_same<int&&, add_rvalue_reference<int>::type>::value << endl;
	cout << std::is_same<int, add_rvalue_reference<int&>::type>::value << endl;
	cout << std::is_same<int, add_rvalue_reference<int&&>::type>::value << endl;

	cout << std::is_same<int*, add_pointer<int>::type>::value << endl;

	//移除数组的顶层维度
	cout << std::is_same<int, std::remove_extent<int[]>::type>::value << endl;
	cout << std::is_same<int[2], std::remove_extent<int[][2]>::type>::value << endl;
	cout << std::is_same<int[2][3], std::remove_extent<int[][2][3]>::type>::value << endl;

	//移除数组的所有维度
	//cout << std::is_same<int, std::remove_all_extends<int[][2][3]>::type>::value << endl;

	//取公共类型
	typedef std::common_type<unsigned char, short, int>::type NumbericType;
	cout << std::is_same<int, NumbericType>::value << endl;
}
