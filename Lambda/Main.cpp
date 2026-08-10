#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
	std::vector<int> data = { 1, 2, 3, 4, 5, 6 ,14 };

	std::sort(
		data.begin(),
		data.end(),
		[](int left, int right)
		{
			return left > right;
		});

	int result = 0;
	auto sum = [&result](int value)
		{
			result += value;
		};

	for (int const item : data)
	{
		sum(item);
		std::cout << result << " ";
	}



	std::cin.get();
}
