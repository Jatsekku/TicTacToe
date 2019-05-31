#ifndef PLAYER_HPP_
#define PLAYER_HPP_

	#include <string>

	class Player
	{
		private:
			std::string name;		//Player's name
			uint8_t mark;			//Mark (X/O) associated with player
			int16_t current_move;	//Idx of cell in bf, which define the current move of player
		public:
			Player(void);
			Player(std::string name, uint8_t mark);
			virtual void make_move(void);
			void set_move(int16_t idx);
			int16_t get_move(void);
			uint8_t get_mark(void);
			//std::string get_name(void);
			void display_name(void);
			//void display_info(void);
	};

#endif /* PLAYER_HPP_ */
