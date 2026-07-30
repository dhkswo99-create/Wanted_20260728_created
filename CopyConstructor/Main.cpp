#include "Player.h"

#include <iostream>


int main()
{
	Player player1;
	Player player2("Wanjae");
	Player player3(player2);
	Player player4 = player3;

	std::cin.get();
}
	