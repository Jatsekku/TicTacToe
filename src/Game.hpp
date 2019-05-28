#ifndef GAME_HPP_
#define GAME_HPP_
#include <stdint.h>
#include "Board.hpp"
#include "Player.hpp"

	enum
	{
		_undefined = -2,
		_stop = -1,
		_start = 0,
		_p1 = 1,
		_p2 = 2
	};


	class Game
	{
		private:
			int8_t game_state;
			uint8_t win_amount_mark;
			Board* b;
			//TODO(Butan): Dodaj player'ów
			Player* p1;
			Player* p2;
		public:
			Game(uint8_t win_amount_mark, Player* p1, Player* p2, Board* b);
			void start(void);
			void stop(void);
			void play(void);
	};

#endif /* GAME_HPP_ */
