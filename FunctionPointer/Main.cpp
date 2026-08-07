#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int array[], int length, bool (*comparer)(int, int) )
{
	for (int ix = 0; ix < length - 1; ++ix)
	{
		for (int jx = 0; jx < length - 1 - ix; ++jx)
		{
			if (comparer(array[jx], array[jx + 1]))
			{
				Swap(array[jx], array[jx + 1]);
			}
		}
	}
}

class Actor
{
public:
	void Tick(float deltaTime)
	{

	}
};

//멤버 함수 포인터
void (Actor::*ActorTick)(float);



bool Ascending(int a, int b)
{
	return a > b;
}
bool Decending(int a, int b)
{
	return a > b;
}

int main()
{
	ActorTick = &Actor::Tick;

	int array[] = { 5, 2, 8, 4, 1 };
	int length = sizeof(array) / sizeof(array[0]);

	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << " ";
	} std::cout << '\n';
	BubbleSort(array, length, Ascending);
	//int array[] = { 5, 3, 7, 2, 1, 6 };
	//int length = sizeof(array)/sizeof(array[0]);
	//BubbleSort(array, length);
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << " ";
	}


	//함수 포인터.
	//float (*FunctionPointer)(float, float);

	//FunctionPointer = (true) ? Add : Multiply; // 로직을 외부에 두고 전달받아 사용할 수 있게 됨.
	//std::cout<<
	//	FunctionPointer(1, 3) << '\n';

	////FunctionPointer = Add;

	//FunctionPointer = Multiply;
	//std::cout<<
	//	FunctionPointer(1, 3) << '\n';
	
}