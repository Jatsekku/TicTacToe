#include "Player.hpp"
#include <stdint.h>
#include <string>
#include <iostream>

Player::Player(void)
{
	this->mark = 0;
	this->current_move = -1;
	this->bf = nullptr;
	this->win_mark_amount = 0;
}

Player::Player(std::string name, uint8_t mark)
{
	this->name = name;
	this->mark = mark;
	this->current_move = -1;
	this->bf = nullptr;
	this->win_mark_amount = 0;
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
	std::cout << "virtual make_move Error " << std::endl;
}

void Player::set_game_info(Board* bf, uint8_t win_mark_amount)
{
	this->bf = bf;
	this->win_mark_amount = win_mark_amount;
}

void Player::set_move(int16_t idx)
{
	this->current_move = idx;
}

void Player::display_name(void)
{
	std::cout << "Player: " << this->name << " " << std::endl;
}

uint8_t Player::get_game_info(void) { return this->win_mark_amount;}

Board* Player::get_board(void) {return this->bf;}
