#include <iostream>
#include <array>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

void PrintArray(int* array, int count) //함수를 거치면 배열 정보가 빠져서 크기를 받아야 한다. 왜? 포인터로 바뀌어서
{
	for (int ix = 0; ix < count; ++ix)
	{
		std::cout << array[ix] << " ";
	}
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //원래 앱 종료지점마다 써줘야 하나
	// 첫 시작지점에만 넣을 수 있는 함수
	std::array<int, 5> stdArray;
	stdArray.size();

	const int length = 5;
	int array[length] = {}; // 공간의 크기가 변하면 쓸 수 없다.
	//memset(array, 0, sizeof(int)* length);

	//동적배열
	int* dArray = new int[length]; //메인 아래 지역 변수 그래서 스택에 잡힘 포인터가 힙에 잡힘 
	//크기가 변할 수 있어서. 스택이 작아서 힙에 할당.
	//new 대신 DBG_NEW 해줘야함. 원래는  
	dArray[0] = 10;

	delete[] dArray;

	int* ptr = array;
	*(ptr + 2) = 30; // 포인터의 덧셈은 메모리 점프
	for (int ix = 0; ix < length; ++ix)
	{
		array[ix] = ix;
	}
	for (const int value : array/*원시배열*/) //범위 기반 루프
	{
		std::cout << value << " ";
	}

	PrintArray(array, length);

	std::cin.get();
}