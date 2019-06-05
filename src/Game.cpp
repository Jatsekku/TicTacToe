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
	uint8_t win_pawn;
	p1->set_game_info(this->b, this->win_amount_mark);
	p2->set_game_info(this->b, this->win_amount_mark);


	while(win_pawn == 0 && b->is_board_full() == false)
	{
		b->display();
		p2->display_name();
		p2->make_move();
		b->set_field(p2->get_move(), p2->get_mark());


		if((win_pawn = (int)check()) != 0)
		{

			std::cout << "The winner is:"<< std::endl;
			if(win_pawn == 1 )
				p1->display_name();
			if(win_pawn == 2)
				p2->display_name();
			break;
		}

		if(b->is_board_full() == true)
		{
			std::cout << "draft" << std::endl;
			break;
		}

		game_state = 2;
		b->display();

		p1->display_name();
		p1->make_move();
		b->set_field(p1->get_move(), p1->get_mark());



		if((win_pawn = (int)check()) != 0)
		{

			std::cout << "The winner is:"<< std::endl;
			if(win_pawn == 1 )
				p1->display_name();
			if(win_pawn == 2)
				p2->display_name();
			break;
		}

		if(b->is_board_full() == true)
		{
			std::cout << "draft" << std::endl;
			break;
		}

	}
}

uint8_t Game::check(void)
{
	uint8_t marks[3];							//marks counter tab {E, O, X}
	uint8_t n = b->get_size();					//size of battle_field

	uint8_t result = 0;

	//Traverse row
	for(uint8_t y = 0; y < n; y++)
	{
		for(uint8_t x = 0; x < (n - (win_amount_mark-1)); x++)
		{
			//window
			marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_amount_mark; window_idx++)
				marks[b->get_field((x + window_idx), y)]++;

			if(marks[1] == win_amount_mark)
			{
				result = 1;
				break;
			}

			if(marks[2] == win_amount_mark)
			{
				result = 2;
				break;
			}
		}
	}

	//Traverse column
	for(uint8_t x = 0; x < n; x++)
	{
		for(uint8_t y = 0; y < (n - (win_amount_mark-1)); y++)
		{
			//window
			marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_amount_mark; window_idx++)
				marks[b->get_field(x, (y + window_idx))]++;

			if(marks[1] == win_amount_mark)
			{
				result = 1;
				break;
			}

			if(marks[2] == win_amount_mark)
			{
				result = 2;
				break;
			}
		}
	}


	//Traverse diagonal
    for(uint8_t diag = win_amount_mark - 1; diag < (2 * n - 1) - (win_amount_mark - 1); ++diag)
    {

        uint8_t z = (diag < n) ? 0 : diag - n + 1;
        for (uint8_t j = z; j <= ((diag - z) - (win_amount_mark - 1)) ; ++j)
        {
			//window
        	marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_amount_mark; window_idx++)
				marks[b->get_field(((diag-j) - window_idx), j + window_idx)]++;

			if(marks[1] == win_amount_mark)
			{
				result = 1;
				break;
			}

			if(marks[2] == win_amount_mark)
			{
				result = 2;
				break;
			}
        }
    }

    //Traverse anti-diagonal
    for(uint8_t adiag = win_amount_mark - 1; adiag < (2 * n - 1) - (win_amount_mark - 1); ++adiag)
    {

        uint8_t z = (adiag < n) ? 0 : adiag - n + 1;
        for (uint8_t j = z; j <= ((adiag - z) - (win_amount_mark - 1)); ++j)
        {
			//window
        	marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_amount_mark; window_idx++)
				marks[b->get_field((((n-1) - (adiag-j)) + window_idx), j + window_idx)]++;

			if(marks[1] == win_amount_mark)
			{
				result = 1;
				break;
			}

			if(marks[2] == win_amount_mark)
			{
				result = 2;
				break;
			}
        }
    }

    return result;
}
