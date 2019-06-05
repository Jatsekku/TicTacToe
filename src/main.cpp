#include <iostream>
#include "Board.hpp"
#include "Human.hpp"
#include "Bot.hpp"
#include "Game.hpp"

int main(void)
{
	int bf_size;
	int win_mark_amount;

	std::cout << "Please enter the board size: "<< std::endl << ">";
	std::cin >> bf_size;
	std::cout << "Please enter the number of symbols required to win:" << std::endl << ">";
	std::cin >> win_mark_amount;

	Board b(bf_size);
	Human p1("Player", 1);
	Bot p2("XO_Bot", 2);
	Game g(win_mark_amount, &p1, &p2, &b);


	g.start();
	g.play();


	return 0;
}

