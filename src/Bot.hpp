#ifndef BOT_HPP_
#define BOT_HPP_

	#include "Player.hpp"
	#include "Board.hpp"
	#include <stdint.h>


	class Bot : public Player
	{
		private:


		public:
			void make_move(void);
			int basic_evaluation(Board &Board, uint8_t win_mark_amount, uint8_t turn);


	};

#endif /* BOT_HPP_ */
