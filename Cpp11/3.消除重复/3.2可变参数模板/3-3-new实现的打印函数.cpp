#include <iostream>

template <typename T>
void Print(T t)
{
	std::cout << t << std::endl;
}

template <typename T, typename... Args>
void Print(T t, Args... args)
{
	std::cout << t;
	Print(args...);
}

int main(void)
{
	Print(1);
	Print(1, 2);
	Print(1, 2, 3);
	Print(1, 2, 3, 4);
	Print(1, 2, 3, 4, 5);

	return 0;
}
