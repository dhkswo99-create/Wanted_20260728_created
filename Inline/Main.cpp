#include <iostream>

__forceinline

inline int Square(int x)
{
	return x * x;
}

int main()
{
	std::cout << Square(3);
}