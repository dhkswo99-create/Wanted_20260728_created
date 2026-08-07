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

//함수 오버로딩 : 같은 이름의 함수가 여러 개 배치되는 형태.
void Use(int& value)
{
	std::cout << "void Use(int& value)\n";
}
void Use(int&& value) 
{
	std::cout << "void Use(float& value)\n";
}

class Item
{
public:
	virtual ~Item() = default;
};

void Test(Item& item)
{
	std::cout << "void Test&\n";
}
void Test(Item&& item)
{
	std::cout << "void Test&&\n";

}


template<typename T>
void Function(T&& value)
{
	Test(std::forward<T>(value)); //Perfect Forwarding. 받은 R값참조가 그대로 전달될 수 있게 만듦.
}


int main()
{
	Item item;
	Function(item);
	Function(Item());

	//std::unique_ptr<Actor> actor1 = std::make_unique<Actor>();
	//std::unique_ptr<Actor> actor2 = std::move(actor1);
	//move ->> 뭘 받던 다 지우고 &&를 붙여버려서 이동 처리함.


	//const char*  actor2Name = "TestActor";
	//Actor actor1("Test"); // R밸류를 대입하는 중 그래서 오류.
	//Actor actor2(actor2Name);

	int count =  10; // count == L value 메모리 차지, 이름 가짐 변경 가능
	// 10은 Rvalue 정수 리터럴, 임시값.. 메모리 X 이름 X 변경 X

	//L-value Reference 
	int& lRdf = count;
	//int& lRef2 = 10; 오류
	
	
	//R-value Reference
	int&& rRef = 10;
	//int&& rRef = count; 오류.
	//int&& rRef2 = rRef; //받은 애는 표현식의 밸류값을 따라간다
	//int value = 10;
	//Use(value);
	//Use(std::move(value));


}