#include <iostream>


class Actor
{
public:
	virtual ~Actor() = default;

};

class Camera : public Actor
{

};

class Player : public Actor
{
private:
	int x = 0;
};

int main()
{
	Actor* actor1 = new Player(); //업캐스팅
	Camera* actor2 = new Camera(); //객체 생성
	//Player* actor3 = new Actor(); //다운 캐스팅 불가능

	auto player = dynamic_cast<Player*>(actor2);
	if (player)
	{
		std::cout
			<< "Player 형변환 성공\n";
	}
	actor1 = dynamic_cast<Camera*>(actor1); // 서로 관계 없는 클래스간 형 변환 불가. 널처리
	if (actor2)
	{
		std::cout
			<< "Camera 형변환 성공\n";
	}
	//auto playmera = dynamic_cast<Player*>(actor3);
	//if (playmera)
	//{
	//	std::cout
	//		<< "Camera 형변환 성공\n";
	//}
s	const type_info& typeInfo1 = typeid(*actor1); //타입정보 얻기.
	const type_info& typeInfo2 = typeid(*actor2);
	//const type_info& typeInfo3 = typeid(*actor3);

	//if (typeInfo1 == typeInfo2)
	//{
	//	std::cout << typeInfo3.name();
	//}


	
	std::cin.get();

}