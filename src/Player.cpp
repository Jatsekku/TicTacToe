#include "Player.hpp"
#include <stdint.h>
#include <string>
#include <iostream>

Player::Player(void)
{
	mark = 0;
	current_move = -1;
}

Player::Player(std::string name, uint8_t mark)
{
	this->name = name;
	this->mark = mark;
	current_move = -1;
}

int16_t Player::get_move(void)
{
	return this->current_move;
}

uint8_t Player::get_mark(void)
{
	return this->mark;
}

void Player::make_move(void)
{

}

void Player::set_move(int16_t idx)
{
	this->current_move = idx;
}

void Player::display_name(void)
{
	std::cout << "Gracz: " << this->name << " " << std::endl;
}
