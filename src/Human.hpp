#ifndef HUMAN_HPP_
#define HUMAN_HPP_

	#include "Player.hpp"

	class Human : public Player
	{
		private:

		public:
			Human(void);
			Human(std::string name, uint8_t mark);
			void make_move(void);
	};

#endif /* HUMAN_HPP_ */
