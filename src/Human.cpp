#include "Human.hpp"
#include <stdint.h>
#include <iostream>

Human::Human(std::string name, uint8_t mark)
: Player(name, mark) {};

void Human::make_move(void)
{
	int move_idx_tmp;

	std::cout << "Your move: " << std::endl;
	std::cin >> move_idx_tmp;
	set_move(move_idx_tmp);
}
