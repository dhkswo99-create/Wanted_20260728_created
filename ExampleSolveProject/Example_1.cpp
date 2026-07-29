#include <iostream>
#include <string>
void exam1()
{
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		int inputNumber;
		char buffer[50] = {};
		std::cout << i << "번째 정수 입력 : ";
		std::cin >> buffer;
		while ((inputNumber = atoi(buffer)) == 0)
		{
			std::cout << i << "번째 정수 입력 : ";
			std::cin >> buffer;
		} 
		sum += inputNumber;
	} 
	std::cout << "모든 정수의 합 : " << sum;
}

void exam2()
{
	std::string name;
	std::string phoneNumber;
	std::cout << "이름 입력 : ";
	std::cin >> name;
	std::cout << "전화번호 입력 : ";
	std::cin >> phoneNumber;
}

void exam3()
{
	int inputNumber;
	char buffer[50] = {};
	std::cout << "출력할 구구단 입력 : ";
	std::cin >> buffer;
	while ((inputNumber = atoi(buffer)) == 0)
	{
		std::cout << "출력할 구구단 입력 : ";
		std::cin >> buffer;
	}
	for (int i = 1; i < 10; i++)
	{
		std::cout << inputNumber << " x " << i << " = " << (inputNumber * i) << "\n";
	}
}




