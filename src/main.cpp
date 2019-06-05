#include <iostream>
#include "Board.hpp"
#include "Human.hpp"
#include "Bot.hpp"
#include "Game.hpp"

int main(void)
{
	Board b(6);
	Human p1("Jacek", 1);
	Bot p2("XO_Bot", 2);
	Game g(4, &p1, &p2, &b);


	g.start();
	while(1)
		g.play();



}

