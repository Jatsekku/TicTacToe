#include "Human.hpp"
#include <stdint.h>
#include <iostream>

Human::Human(std::string name, uint8_t mark)
: Player(name, mark) {};

void Human::make_move(void)
{
	int move_idx_tmp;
	//TODO(Jacek) Zadbaj o kontrolę błędów. Ruch musi byc wykonany i nie moze byc taki sami jak poprzedni
	std::cout << "Make move:" << std::endl;
	std::cin >> move_idx_tmp;
	set_move(move_idx_tmp);
}
