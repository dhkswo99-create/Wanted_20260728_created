#include <iostream>

int main()
{
	int value1 = 0;
	char buffer[50] = {};

	//int -> 32bit? no -> 최소 32bit.
	//long long == __int64

	while (true)
	{
		std::cout << "0이 아닌 숫자를 입력하세요 : ";
		std::cin >> buffer;

		if ((value1 = atoi(buffer)) == 0) //ASKII to int, 오류 코드가 0이기 때문에 0을 사용할 수 없다.
		{
		}
		else
		{
			break;
		}
	}

	int value2 = 0;
	std::cout << "0이 아닌 숫자를 입력하세요 : ";
	std::cin >> buffer;
	while (true)
	{
		std::cout << "0이 아닌 숫자를 입력하세요 : ";
		std::cin >> buffer;

		if ((value2 = atoi(buffer)) == 0) 
		{
		}
		else
		{
			break;
		}
	}

	std::cout << "두 수의 합은 " << (value1 + value2) << "입니다.";
	std::cin.get();

}