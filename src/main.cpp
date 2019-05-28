#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main(void)
{
	Board b(10);
	Player p1("Jacek", 1);
	Player p2("Ewa", 2);
	Game g(5, &p1, &p2, &b);

	//p1.display_name();
	//p2.display_name();


	g.start();
	while(1)
		g.play();



}
