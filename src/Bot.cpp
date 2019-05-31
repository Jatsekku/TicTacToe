#include "Bot.hpp"
#include <stdint.h>
#include <iostream>


int Bot::basic_evaluation(Board& Board, uint8_t win_mark_amount, uint8_t turn)
{
	int result = 0;							//Result value of evaluation
	uint8_t m = win_mark_amount;			//Temporary renaming var win_mark_amount to m :)
	uint8_t bf_size = Board.get_size();		//Size of the battle field (bf_size x bf_size)
	uint8_t bot_mark = get_mark();			//Mark associated with bot player
	uint8_t prev_mark;
	int possibility = 0, density = 0, line_value=0;// line_value=density/possibility

	//Traversing all rows

	for(uint8_t y = 0; y < bf_size; y++)
	{
		for(uint8_t x = 0; x < bf_size; x++)
		{
			int field_val = Board.get_field(x,y);
			//First, we looking for empty field or field with player's mark or
			if((field_val == 0) || (field_val == bot_mark))
			{
				possibility++;
				if(field_val == bot_mark)
					density ++;
			}


		}
	}
}
