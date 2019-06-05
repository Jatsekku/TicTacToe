#ifndef BOT_HPP_
#define BOT_HPP_

	#include "Player.hpp"
	#include "Board.hpp"
	#include <stdint.h>

	class Bot : public Player
	{
		private:


		public:
			Bot(void);
			Bot(std::string name, uint8_t mark);
			void make_move(void);

			int evaluation(Board *Board, uint8_t win_mark_amount, uint8_t turn);
			int minmax2(Board *Board, int depth, bool maximizing_player,int alpha,int beta);
			int findBestMove2(Board * Board,int player);


			int dummy_evaluation(Board *Board, uint8_t win_mark_amount, uint8_t turn);
			int minmax(Board *Board, int depth, bool maximizing_player,int alpha,int beta);
			int findBestMove(Board * Board,int player);

	};

#endif /* BOT_HPP_ */
