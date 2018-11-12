#include <iostream>
#include <string>

using namespace std;

template<class Function, class... Args>
inline auto FuncWrapper(Function && f, Args && ... args) -> decltype(f(std::forward<Args>(args)...))
{
	return f(std::forward<Args>(args)...);
}

void test0() {
	std::cout << "void" << std::endl;
}

int test1() {
	return 1;
}

int test2(int x) {
	return x;
}

string test3(string s1, string s2) {
	return s1 + s2;
}

int main()
{
	FuncWrapper(test0);
	cout << FuncWrapper(test1) << endl;
	cout << FuncWrapper(test2, 1) << endl;
	cout << FuncWrapper(test3, "aa", "bb") << endl;

	return 0;
}
