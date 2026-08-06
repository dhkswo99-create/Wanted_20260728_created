#include <iostream>
#include <string>

class Actor
{
public:
	Actor(const char* newName) // 전달 받을 때 복사는 방지 &로 근데? L밸류임 매개변수가
	{
		// 이름 값 설정
		// 1. 공간 할당
		// 2. 값 복사
		size_t length = strlen(newName) + 1;
		name = new char[length]; // or memset(name, 0, length);
		strcpy_s(name, length, newName);
	}
	~Actor()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	//복사 생성자
	Actor(const Actor& other)
	{
		if (name) //기존 공간 있다면 해제
		{
			delete[] name;
			name = nullptr;
		}
		// 공간 할당 값복사.
		size_t length = strlen(other.name) + 1;
		name = new char[length]; // or memset(name, 0, length);
		strcpy_s(name, length, other.name);
	}

	//이동 생성자
	Actor(Actor&& other) noexcept // 여기선 예외가 발생해선 안된다는 구문.
	{ // 왜 const를 넣으면 안되는가? other의 포인터가 null을 가리키게 하기 위해서.
		if (name)
		{
			delete[] name;
		}
		name = other.name;
		other.name = nullptr; //주소값을 이전 시킨 후 원본 주소에 null 대입.
	}


private:
	char* name;
};



int main()
{
	const char*  actor2Name = "TestActor";
	Actor actor1("Test"); // R밸류를 대입하는 중 그래서 오류.
	Actor actor2(actor2Name);

	int count =  10; // count == L value 메모리 차지, 이름 가짐 변경 가능
	// 10은 Rvalue 정수 리터럴, 임시값.. 메모리 X 이름 X 변경 X

	//L-value Reference 
	int& lRdf = count;
	//int& lRef2 = 10; 오류
	
	//R-value Reference
	int&& rRef = 10;
	//int&& rRef = count; 오류.
	rRef = 20;

}