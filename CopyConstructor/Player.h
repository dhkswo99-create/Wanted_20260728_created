#pragma once
class Player
{
public:
	Player();
	Player(const char* inName);
	//복사생성자
	//Player(const Player& other);
	//Getter
	inline const char* GetName() const { return name; }
	~Player();
	//대입연산자 오버로딩
	//연산자 -> 연산자를 이름으로 갖는 함수
	Player& operator=(const Player& other);
	
	

private: // 같은 클래스라면 접근할 수 있다.
	char* name = nullptr;
	//Player(const Player& other); 삭제 처리를 위해서 (외부에서 사용하지 못하게)
	//Player(const Player& other) = delete; //최근

};

