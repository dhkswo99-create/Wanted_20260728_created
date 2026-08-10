#include <algorithm>
#include <iostream>
#include <vector>

struct Greater
{
	bool operator()(int left, int right)
	{
		return left < right;
	}
};



int main()
{
	//정렬에 사용할 벡터(동적 배열)
	std::vector<int> data = {3, 2, 4, 5, 2, 6, 4, 6, 52, 54};

	Greater greater;


	//정렬
	std::sort(data.begin(), data.end(), greater);

	for (const int item : data)
	{
		std::cout << item << " ";
	} std::cout << "\n";
	





}



















