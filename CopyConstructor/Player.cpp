#include "Player.h"
#include <iostream>
Player::Player()
{
	std::cout << "Player() called\n";
}
Player::Player(const char* inName)
	:name(nullptr)
{
	if (!inName) inName = "";
	size_t length = strlen(inName) + 1;
	name = new char[length] {}; //0으로 초기화
	strcpy_s(name, length, inName);
	std::cout << "Player(const char* inName) called\n";
}
//복사생성자
Player::Player(const Player& other)
	//: name(other.name) 얕은복사
{
	//깊은 복사
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);
	

	std::cout << "Player(const Player& other) called\n";
}

Player::~Player()
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}

Player& Player::operator=(const Player& other)
{
	//복사처리
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);
	std::cout << "operator=(const Player& other)\n";
	return *this;
}

