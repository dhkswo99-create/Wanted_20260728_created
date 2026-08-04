#include "CraftObject.h"
#include <iostream>

class Actor : public CraftObject
{
	TYPE_DELARATIONS(Actor, CraftObject)

};

class Player :public Actor
{
	TYPE_DELARATIONS(Player, Actor)
};
class Camera :public Actor
{
	TYPE_DELARATIONS(Camera, Actor)
};

int main()
{
	//std::shared_ptr<Actor> player = std::make_shared<Player>();
	std::shared_ptr<Actor> camera = std::make_shared<Camera>();
	std::shared_ptr<Player> targetPlayer = Cast<Player>(camera);
	if (targetPlayer)
	{
		std::cout << "성공\n";
	}
	else
	{
		std::cout << "실패\n";
	}

}









//#include <iostream>
//
////#define TO_NAME(x) "Type_"#x
////
////#define CLASS_NAME(type)						\
////	public:                                 \
////	virtual const char* ClassName() const	\
////	{										\
////		return TO_NAME(type);				\
////	}
//
//class Actor
//{
//	CLASS_NAME(Actor);
//public:
//	static size_t TypeId()
//	{
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//};
//
//class Player : public  Actor
//{
//	CLASS_NAME(Player);
//public:
//	static size_t TypeId() 
//	{
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//};
//class ActorChild : public Actor
//{
//	CLASS_NAME(ActorChild);
//};
//
//int main()
//{
////{
////	Actor* actor = new Actor();
////	Actor* player = new Player();
////	Player* child = new Player();
////	
////	std::cout
////		<< actor->ClassName() << '\n';
////	
////	std::cout
////		<< player->ClassName() << '\n';
////
////	//if (!strcmp(player->ClassName(), actor->ClassName())) //strcmp 구현 해보기
////	//{
////	//	std::cout
////	//		<< "두 타입이 같음\n";
////	//}
////	//else
////	//{
////	//	std::cout
////	//		<< "두 타입이 다름\n"
////	//		<< strcmp(player->ClassName(), actor->ClassName())
////	//		<< '\n'
////	//		<< strcmp(actor->ClassName(), player->ClassName())
////	//		<< '\n'
////	//		<< strcmp(actor->ClassName(), child->ClassName())
////	//		<< '\n';
////
////	//}
////	//타입 ID로 비교.
////	if (child->TypeId() == Player::TypeId())
////	{
////		std::cout << "두 타입이 같음\n";
////	}
////	else
////	{
////		std::cout << "두 타입이 다름\n";
////	}
//
//
//
//
//
//
//
//
//
//	delete actor;
//	actor = nullptr;
//	delete player;
//	player = nullptr;
//}
//
