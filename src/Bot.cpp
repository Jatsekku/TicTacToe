#include "Bot.hpp"
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <limits.h>

#define E	0
#define O 	1		//oponent
#define X 	2		//player

#define WIN_MAX		INT_MAX - 10
#define LOSE_MIN	INT_MIN + 10

#define ALMOST_WIN	INT_MAX - 1000
#define ALMOST_LOSE INT_MIN + 1000


Bot::Bot(std::string name, uint8_t mark)
: Player(name, mark) {};

void Bot::make_move(void)
{
	int move_tmp = findBestMove2(get_board(), get_mark());
	std::cout << "Mój ruch:" << move_tmp << std::endl;
	set_move(move_tmp);
}

int Bot::evaluation(Board *Board, uint8_t win_mark_amount, uint8_t turn)
{

	uint8_t marks[3];
	uint8_t n = Board->get_size();
	uint8_t my_pawn = get_mark();
	uint8_t opponent_pawn = (my_pawn==1)? 2:1;
	float result;

	//Traverse row
	for(uint8_t y = 0; y < n; y++)
	{
		for(uint8_t x = 0; x < (n - (win_mark_amount-1)); x++)
		{


			//window
			marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field((x + window_idx), y)]++;

			if(marks[my_pawn] == win_mark_amount)
				return WIN_MAX;

			if(marks[opponent_pawn] == win_mark_amount)
				return LOSE_MIN;

			//close end for opponent
			if(marks[my_pawn] > 0)
			{
			}
			else
			{
				if(marks[opponent_pawn] == win_mark_amount - 1)
					return ALMOST_LOSE;
				//result -= marks[opponent_pawn];
			}

			//close_end for me
			if(marks[opponent_pawn] > 0)
			{
			}
			else
			{
				if(marks[my_pawn] == win_mark_amount - 1)
					return ALMOST_WIN;

				//result += marks[my_pawn];
			}

		}
	}

	//Traverse column
	for(uint8_t x = 0; x < n; x++)
	{
		for(uint8_t y = 0; y < (n - (win_mark_amount-1)); y++)
		{


			//window
			marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field(x, (y + window_idx))]++;

			if(marks[my_pawn] == win_mark_amount)
				return WIN_MAX;

			if(marks[opponent_pawn] == win_mark_amount)
				return LOSE_MIN;

			//close end for opponent
			if(marks[my_pawn] > 0)
			{
			}
			else
			{
				if(marks[opponent_pawn] == win_mark_amount - 1)
					return ALMOST_LOSE;
				//result -= marks[opponent_pawn];
			}

			//close_end for me
			if(marks[opponent_pawn] > 0)
			{
			}
			else
			{
				if(marks[my_pawn] == win_mark_amount - 1)
					return ALMOST_WIN;

				//result += marks[my_pawn];
			}
			//if(marks)
		}
	}


	//Traverse diagonal
    for(uint8_t diag = win_mark_amount - 1; diag < (2 * n - 1) - (win_mark_amount - 1); ++diag)
    {

        uint8_t z = (diag < n) ? 0 : diag - n + 1;
        for (uint8_t j = z; j <= ((diag - z) - (win_mark_amount - 1)) ; ++j)
        {


			//window
        	marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field(((diag-j) - window_idx), j + window_idx)]++;

			if(marks[my_pawn] == win_mark_amount)
				return WIN_MAX;

			if(marks[opponent_pawn] == win_mark_amount)
				return LOSE_MIN;

			//close end for opponent
			if(marks[my_pawn] > 0)
			{
			}
			else
			{
				if(marks[opponent_pawn] == win_mark_amount - 1)
					return ALMOST_LOSE;
				//result -= marks[opponent_pawn];
			}

			//close_end for me
			if(marks[opponent_pawn] > 0)
			{
			}
			else
			{
				if(marks[my_pawn] == win_mark_amount - 1)
					return ALMOST_WIN;

				//result += marks[my_pawn];
			}
        }
    }

    for(uint8_t adiag = win_mark_amount - 1; adiag < (2 * n - 1) - (win_mark_amount - 1); ++adiag)
    {

        uint8_t z = (adiag < n) ? 0 : adiag - n + 1;
        for (uint8_t j = z; j <= ((adiag - z) - (win_mark_amount - 1)); ++j)
        {


			//window
        	marks[0] = 0; marks[1] = 0; marks[2] = 0;
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field((((n-1) - (adiag-j)) + window_idx), j + window_idx)]++;

			if(marks[my_pawn] == win_mark_amount)
				return WIN_MAX;

			if(marks[opponent_pawn] == win_mark_amount)
				return LOSE_MIN;

			//close end for opponent
			if(marks[my_pawn] > 0)
			{
			}
			else
			{
				if(marks[opponent_pawn] == win_mark_amount - 1)
					return ALMOST_LOSE;
				//result -= marks[opponent_pawn];
			}

			//close_end for me
			if(marks[opponent_pawn] > 0)
			{
			}
			else
			{
				if(marks[my_pawn] == win_mark_amount - 1)
					return ALMOST_WIN;

				//result += marks[my_pawn];
			}
        }
    }

    return 0;
}


int Bot::findBestMove2(Board * Board,int player)
{
	int best_val = INT_MIN;
	int best_move = -1;

    for(int y = 0; y<Board->get_size(); y++)
    {
        for (int x = 0; x<Board->get_size(); x++)
        {
            // Check if cell is empty
        	if (Board->get_field(x,y)==0)
            {
                // Make the move
        		 Board->set_field(x,y, X);
                // compute evaluation function for this
                // move.
                int val_tmp = minmax2(Board, 4, false,INT_MIN,INT_MAX);
               // std::cout << "Evaluation: " << evaluation(Board, 3, 0) << " " << (int)Board->get_field(x,y);
               // std::cout<< "move Val z bestmove : "<< val_tmp << " x: " << x << " y: " << y << " idx: " << y*Board->get_size() + x <<std::endl;
               // Board->display();
                // Undo the move
                Board->set_field(x,y,0);

                // If the value of the current move is
                // more than the best value, then update
                // best/

                if (val_tmp > best_val)
                {
                    best_move = y*Board->get_size()+x;
                    best_val = val_tmp;
                }
            }
        }

    }
    return best_move;
}




int Bot::minmax2(Board *Board, int depth, bool maximizing_player, int alpha,int beta)
{
	int static_eval = evaluation(Board, get_game_info(),0);

	if( (static_eval == WIN_MAX) || (static_eval == LOSE_MIN) || (Board->is_board_full() == true))
		return static_eval;

	if(depth == 0)
		return static_eval;

	if(maximizing_player)
	{
		int max_eval = INT_MIN;
		int evalmax;
        for(int y = 0; y < Board->get_size(); y++)
        {
            for(int x = 0; x < Board->get_size(); x++)
            {

                if (Board->get_field(x,y) == 0)
                {
                    // Make the move
             	   Board->set_field(x,y, X);
             	   evalmax= minmax2(Board, depth-1, false,alpha,beta);
                   max_eval = std::max( max_eval,evalmax);
                   alpha=std::max(alpha,evalmax);
                   Board->set_field(x,y,0);
                   if(beta<=alpha)break;
                }
            }
        }
        return max_eval;
	}
	else
	{
		int min_eval = INT_MAX;
		int evalmin;
        for(int y = 0; y < Board->get_size(); y++)
        {
            for(int x = 0; x < Board->get_size(); x++)
            {

                if (Board->get_field(x,y) == 0)
                {
                    // Make the move
             	   Board->set_field(x,y, O);
             	   evalmin= minmax2(Board, depth-1, true,alpha,beta);
                   min_eval = std::min( min_eval,evalmin);
                   beta=std::min(beta,min_eval);
                   Board->set_field(x,y,0);
                   if(beta<=alpha)break;
                }
            }
        }
        return min_eval;
	}
}

/*
int Bot::dummy_evaluation(Board *Board, uint8_t win_mark_amount, uint8_t turn)
{

	uint8_t marks[3];
	uint8_t n = Board->get_size();

	//Traverse row
	for(uint8_t y = 0; y < n; y++)
	{
		for(uint8_t x = 0; x < (n - (win_mark_amount-1)); x++)
		{
			marks[0] = 0; marks[1] = 0; marks[2] = 0;

			//window
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field((x + window_idx), y)]++;

			if(marks[X] == win_mark_amount)
				return 10;
			if(marks[O] == win_mark_amount)
				return -10;
		}
	}

	//Traverse column
	for(uint8_t x = 0; x < n; x++)
	{
		for(uint8_t y = 0; y < (n - (win_mark_amount-1)); y++)
		{
			marks[0] = 0; marks[1] = 0; marks[2] = 0;

			//window
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field(x, (y + window_idx))]++;

			if(marks[X] == win_mark_amount)
				return 10;
			if(marks[O] == win_mark_amount)
				return -10;
		}
	}


	//Traverse diagonal
    for(uint8_t diag = win_mark_amount - 1; diag < (2 * n - 1) - (win_mark_amount - 1); ++diag)
    {

        uint8_t z = (diag < n) ? 0 : diag - n + 1;
        for (uint8_t j = z; j <= ((diag - z) - (win_mark_amount - 1)) ; ++j)
        {
        	marks[0] = 0; marks[1] = 0; marks[2] = 0;

			//window
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field(((diag-j) - window_idx), j + window_idx)]++;

			if(marks[X] == win_mark_amount)
				return 10;
			if(marks[O] == win_mark_amount)
				return -10;
            //printf("%d ", x[j][diag - j]);
        }
    }

    for(uint8_t adiag = win_mark_amount - 1; adiag < (2 * n - 1) - (win_mark_amount - 1); ++adiag)
    {

        uint8_t z = (adiag < n) ? 0 : adiag - n + 1;
        for (uint8_t j = z; j <= ((adiag - z) - (win_mark_amount - 1)); ++j)
        {
        	marks[0] = 0; marks[1] = 0; marks[2] = 0;

			//window
			for(uint8_t window_idx = 0; window_idx < win_mark_amount; window_idx++)
				marks[Board->get_field((((n-1) - (adiag-j)) + window_idx), j + window_idx)]++;

			if(marks[X] == win_mark_amount)
				return 10;
			if(marks[O] == win_mark_amount)
				return -10;

            //printf("%d ", x[j][ (n-1) - (adiag-j)]);
        }
    }

    return 0;
}

int Bot::findBestMove(Board * Board,int player)
{
	int best_val = -100000;
	//int val_tmp;
	int best_move = -1;

    for(int y = 0; y<Board->get_size(); y++)
    {
        for (int x = 0; x<Board->get_size(); x++)
        {
            // Check if cell is empty
        	if (Board->get_field(x,y)==0)
            {
                // Make the move
        		 Board->set_field(x,y, X);
                // compute evaluation function for this
                // move.
                int val_tmp = minmax(Board, 5, false,-100000,100000);
                //std::cout << "Evaluation: " << dummy_evaluation(Board, 3, 0) << " " << (int)Board->get_field(x,y);
               // std::cout<< "move Val z bestmove : "<< val_tmp << " x: " << x << " y: " << y << " idx: " << y*Board->get_size() + x <<std::endl;
               // Board->display();
                // Undo the move
                Board->set_field(x,y,0);

                // If the value of the current move is
                // more than the best value, then update
                // best/

                if (val_tmp > best_val)
                {
                    best_move = y*Board->get_size()+x;
                    best_val = val_tmp;
                }
            }
        }

    }
    return best_move;
}

int Bot::minmax(Board *Board, int depth, bool maximizing_player, int alpha,int beta)
{
	int static_eval = dummy_evaluation(Board, get_game_info(),0);

	if( (static_eval == 10) || (static_eval == -10) || (Board->is_board_full() == true))
		return static_eval;

	if(depth == 0)
		return static_eval;

	if(maximizing_player)
	{
		int max_eval = -100000;
		int evalmax;
        for(int y = 0; y < Board->get_size(); y++)
        {
            for(int x = 0; x < Board->get_size(); x++)
            {

                if (Board->get_field(x,y) == 0)
                {
                    // Make the move
             	   Board->set_field(x,y, X);
             	   evalmax= minmax(Board, depth-1, false,alpha,beta);
                   max_eval = std::max( max_eval,evalmax);
                   alpha=std::max(alpha,evalmax);
                   Board->set_field(x,y,0);
                   if(beta<=alpha)break;
                }
            }
        }
        return max_eval;
	}
	else
	{
		int min_eval = 100000;
		int evalmin;
        for(int y = 0; y < Board->get_size(); y++)
        {
            for(int x = 0; x < Board->get_size(); x++)
            {

                if (Board->get_field(x,y) == 0)
                {
                    // Make the move
             	   Board->set_field(x,y, O);
             	   evalmin= minmax(Board, depth-1, true,alpha,beta);
                   min_eval = std::min( min_eval,evalmin);
                   beta=std::min(beta,min_eval);
                   Board->set_field(x,y,0);
                   if(beta<=alpha)break;
                }
            }
        }
        return min_eval;
	}
}
*/
