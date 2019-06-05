#ifndef GAME_HPP_
#define GAME_HPP_
#include <stdint.h>
#include "Board.hpp"
#include "Player.hpp"

	class Game
	{
		private:
			int8_t game_state;
			uint8_t win_amount_mark;
			Board* b;
			Player* p1;
			Player* p2;
		public:
			Game(uint8_t win_amount_mark, Player* p1, Player* p2, Board* b);
			void start(void);
			void stop(void);
			void play(void);
			uint8_t check(void);
	};

#endif /* GAME_HPP_ */
