#include <iostream>

void Release(int **t)// < * 1차 포인터면 스택 변수라 호출 끝나면 더미값 >>> 더블 포인터 사용
{
	if (t != nullptr)
	{
		std::cout << **t;
		delete *t;
		*t = nullptr;
	}
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SwapRef(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int numberA = 10, numberB = 20;
	Swap(&numberA, &numberB);
	SwapRef(numberA, numberB);
	int var = 8;
	int *ptr = &var;

	int *testPtr = new int;
	*testPtr = var;
	//delete testPtr;
	//testPtr = nullptr;s
	Release(&testPtr);

	const int length = 100;
	int *buffer = new int[length];
	int **bufferPtr = &buffer;
	memset(buffer, 0, sizeof(int)*length);
	delete[] buffer;
}



