#include <iostream>
#include <memory>

class Actor
{
public:
	virtual ~Actor() = default;
};

class Player : public Actor
{
public:
	Player()
	{
		std::cout << "Player 생성\n";
	}
	~Player()
	{
		std::cout << "Player 소멸\n";
	}
};


int main()
{
	std::shared_ptr<Actor> actor = std::make_shared_for_overwrite<Actor>() ;
	std::shared_ptr<Player> player = std::make_shared_for_overwrite<Player>();

	//sharedptr은 소유권 공유 가능
	//참조 횟수를 추적해야함.
	//어디서 사용하는지 계속 추적되어야 함.
	std::shared_ptr<Player> otherplayer = player;

}