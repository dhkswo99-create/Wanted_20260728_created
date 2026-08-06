#include <iostream>
#include <memory> //스마트 포인터 사용

class Actor
{
public :
	virtual ~Actor() = default;
};

class 플레이어 : public Actor
{
public:
	플레이어(const char* t)
		: name(t)
	{
		std::cout << t;
		std::cout << "Player constructed.\n";
	}

	~플레이어()
	{
		std::cout << GetName();
		std::cout << "Player destroyed.\n";
	}
	void Attack() const
	{
		std::cout << "Player attacks.\n";
	}
	const char* GetName()
	{
		return name;
	}
public:
	플레이어* p = nullptr;
	const char* name;
};
 
template<typename T>
class Data 
{
private:
	T* data;
};

void PlayerAttack(플레이어* 플레이어)
{
	플레이어->Attack();
	delete 플레이어;
}
void PlayerAttack2(const 플레이어& player)
{
	player.Attack();
}
void PlayerAttack3(const std::unique_ptr<플레이어>& player)
{
	player->Attack();
}



int main()
{
	플레이어* 플레이어1 = new 플레이어("3");
	delete 플레이어1;
	플레이어1 = nullptr;
	std::unique_ptr<플레이어> player2 = std::make_unique <플레이어>("1");
	std::shared_ptr<플레이어> player3 = std::make_shared<플레이어>("2");
	//std::unique_ptr<Player> player4 = player2; unique_ptr은 한 객체만 포인터를 소유
	player2->Attack();
	//-> 로 참조 가능

	//원시포인터 delete 방지가 안된다는 단점이 존재

	//권장되는 방법
	PlayerAttack2(*player2);

	//유니크포인터 참조 받기
	PlayerAttack3(player2);

	//유니크포인터  소유권 넘기기
	//밸류카테고리랑 연결
	std::unique_ptr<플레이어> otherPlayer = std::move(player2);
	player2.reset(); // 기존 거 초기화.
	if (player2)
	{
	}
}