#include "Game.hpp"
#include <stdint.h>
#include <iostream>

Game::Game(uint8_t win_amount_mark, Player* p1, Player* p2, Board* b)
{
	game_state = -1;							//undefined
	this->win_amount_mark = win_amount_mark;
	this->p1 = p1;
	this->p2 = p2;
	this->b = b;
}

void Game::start(void)
{
	this->game_state = 0;

}

void Game::stop(void){game_state = -1;}

void Game::play(void)
{
	p1->set_game_info(this->b, this->win_amount_mark);
	p2->set_game_info(this->b, this->win_amount_mark);

	if(game_state > -1)
	{
		game_state = 1;
		b->display();
		//Player 1 move section
		if(game_state == 1)
		{
			p2->display_name();
			p2->make_move();
			b->set_field(p2->get_move(), p2->get_mark());
			game_state = 2;
			b->display();
		}

		//Player 2 move secion
		if(game_state == 2)
		{
			p1->display_name();
			p1->make_move();
			b->set_field(p1->get_move(), p1->get_mark());

			game_state = 1;
			b->display();
		}
	}
}


