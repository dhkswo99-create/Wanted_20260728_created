#include <iostream>
#include <string>
#include <windows.h>
#include <string>

class Player
{
public:
	Player(const char* name)
	{
		//문자열 저장을 위해 동적할당.
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		//문자열복사
		strcpy_s(this->name, length, name);


		//값 저장.
		for (size_t ix = 0; ix < length - 1; ++ix)
		{
			this->name[ix] = name[ix];
		}
		this->name[length - 1] = '\0';
	}
	~Player()
	{
		if (name != nullptr) // 방법 2 nullptr != name, 방법 3 if(name) // 0이면 false 아니면 모두 true
		{
			delete[] name;
		}
	}

	void PrintName() const
	{
		std::cout << "이름 : " << name << '\n';
	}


private:
	char* name = nullptr;

};

int main()
{
	Player player("Wanajae");
	player.PrintName();

	const char* name = "Wanjae"; //문자열이 종료됨을 알리는 null문자 '\0'이 마지막에 붙어 크기가 증가함.
	char nameArray[4];
	//nameArray[0] = 'W';
	//nameArray[1] = '\0';
	//nameArray[2] = 'n';
	//nameArray[3] = '\0';
	const wchar_t* wcName = L"WanjaeC";
	//windosw 타입
	// WCHAR
	
	//STL 문자열 타입
	std::string nameString = "Wanjae Choi";
	std::cout << nameString << "\n";
	std::cout << nameString.size() << "\n";
	//문자열 크기(문자 갯수)
	//std::string 을 C-Raw string으로 
	const char* rawName = nameString.c_str();
	size_t length = strlen(name);
	std::cout << "string length : " << length << '\n';
	std::cin.get();
}