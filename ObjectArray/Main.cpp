#include <iostream>

class Player
{
public:
	Player()
		: x(0), y(0)
	{
		std::cout << "Player 기본 생성자 호출\n";
	}

	Player(int inX, int inY)
		: x(inX), y(inY)
	{
		std::cout << "Player 생성자 호출\n";
	}

	void ShowPosition() const
	{
		std::cout << "x: " << x << "  y: " << y << "\n";
	}

	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int inX) { x = inX; }
	void SetY(int inY) { y = inY; }

private:
	int x;
	int y;
};

int main()
{
	Player players[5];
	players[2] = Player(5, 3);
	for (int ix = 0; ix < 5; ++ix)
	{
		players[ix].SetX(ix * 2);
		players[ix].SetY(ix * 3);
	}

	// 범위 기반 for 문
	for (const Player& player : players)
	{
		player.ShowPosition();
	}

	std::cin.get();
}