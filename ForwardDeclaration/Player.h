#pragma once
//#include "Weapon.h"
//전방선언
//1. 컴파일 시간 단축
//2. 헤더 순환 참조 방지.
//전방선언은 포인터 타입에만 사용 가능.
//왜? 자료형이 얼마나 메모리를 가지는 지 알아야 하는데, 포인터가 아니라면 전방 선언에서 그 크기를
//짐작할 수 없다.
//레퍼런스나 포인터타입은 가능하다.
//순환 참조가 걸릴 때 불가능하기에 포인터를 쓰게 된다. 
class Weapon;

class Player

{
public:
	Player();
	~Player();
private:
	Weapon* weapon = nullptr; //전방 선언 시 주의점 -> 오타를 못잡음.
};