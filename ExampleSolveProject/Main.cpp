#include <iostream>
#include <string>
void exam1(); // 1-3 1SET
void exam2();
void exam3();
void exam4(); // 4-7 2SET
void exam5();
void exam6();
void exam7();
void exam8();
void exam9();

int main()
{
	int examNum;
	std::cout << "출력할 문제 번호를 입력하세요 : ";
	std::cin >> examNum;
	switch (examNum)
	{
	case 1:
		exam1();
		break;
	case 2:
		exam2();
		break;
	case 3:
		exam3();
		break;
	case 4:
		exam4();
		break;
	case 5:
		exam5();
		break;
	case 6:
		exam6();
		break;
	case 7:
		exam7();
		break;
	case 8:
		exam8();
		break;
	case 9:
		exam9();
		break;
	}
}
