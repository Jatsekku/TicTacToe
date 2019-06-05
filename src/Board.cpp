#include "Board.hpp"
#include <stdint.h>
#include <iostream>

/*

 	 	 x0   x1  x2
		 ___________		   tinycell (2bit)
		|   |   |   |		       ___
	y0	| - | O | X |		      v   v
		|___|___|___|		 ____________________________________________
		|   |   |   |		|   |   |   |   |   |   |   |   |   |   |   /
	y1	| - | - | O |		|   |   |   |   |   |   |   |   |   |   |   \ . . .
		|___|___|___|		|___|___|___|___|___|___|___|___|___|___|___/
		|   |   |   |
	y2	| - | O | - |		  ^___________________________^
		|___|___|___|					cell (byte)

		battle field					physical bf array
		  abstract
 */

int8_t Board::set_field(uint8_t x, uint8_t y, uint8_t mark)
{
	uint16_t field_idx = y * this->bf_size + x;		//Index of field in battle field abstract
	uint16_t cell_idx = field_idx/4;				//Index of cell (byte) in physical bf array
	uint8_t tinycell_idx = (field_idx%4)*2;			//Index of tinycell (2bit) in physical bf array

	if(mark == 0)
		this->bf[cell_idx] &= ~(0x03 << tinycell_idx);

	//If there already is sign return error;
	if(this->bf[cell_idx] & (0x03 << tinycell_idx))
		return -1;

	//Set specified mark on given position
	if(mark == 1)
	{
		this->bf[cell_idx] |= (0x01 << tinycell_idx);
		this->pawns_amount++;
	}

	if(mark == 2)
	{
		this->bf[cell_idx] |= (0x02 << tinycell_idx);
		this->pawns_amount++;
	}


	//No error
	return 0;
}

uint8_t Board::get_field(uint8_t x, uint8_t y)
{
	uint16_t field_idx = y * this->bf_size + x;		//Index of field in battle field abstract
	uint16_t cell_idx = field_idx/4;
	uint8_t tinycell_idx = field_idx%4*2;
	return ((this->bf[cell_idx] & (0x03<<tinycell_idx)) >> tinycell_idx);
}


int8_t Board::set_field(uint16_t idx, uint8_t mark)
{
	uint16_t cell_idx = idx/4;				//Index of cell (byte) in physical bf array
	uint8_t tinycell_idx = (idx%4)*2;			//Index of tinycell (2bit) in physical bf array

	if(mark == 0)
		this->bf[cell_idx] &= ~(0x03 << tinycell_idx);

	//If there already is sign return error;
	if(this->bf[cell_idx] & (0x03 << tinycell_idx))
		return -1;

	//Set specified mark on given position
	if(mark == 1)
	{
		this->bf[cell_idx] |= (0x01 << tinycell_idx);
		this->pawns_amount++;
	}

	if(mark == 2)
	{
		this->bf[cell_idx] |= (0x02 << tinycell_idx);
		this->pawns_amount++;
	}

	//No error
	return 0;
}

uint8_t Board::get_field(uint16_t idx)
{
	uint16_t cell_idx = idx/4;
	uint16_t tinycell_idx = (idx%4)*2;
	return ((this->bf[cell_idx] & (0x03<<tinycell_idx)) >> tinycell_idx);
}
 
uint8_t * Board::get_bf(void)
{
   return this->bf;
}

Board::Board(uint8_t bf_size)
{  
    this->bf_size = bf_size;
    this->cell_number = (bf_size*bf_size%4) ? (bf_size*bf_size/4+1) : (bf_size*bf_size/4);
    this->pawns_amount = 0;

    this->bf = new uint8_t[this->cell_number];

    for(int i = 0; i < cell_number; i++)
    	this->bf[i] = 0;

}

Board::~Board()
{
}

void Board::reset(void)
{
	for(int i = 0; i < this->cell_number; i++)
		this->bf[i] = 0;

}

void Board::display()
{

	uint16_t cell_idx;
	uint8_t tinycell_idx;
	uint8_t field_val;
	uint8_t col_cnt = 0;
	char mark[3] = {' ', 'O', 'X'};

	system("cls");

	for(uint16_t i = 0 ; i < this->bf_size*bf_size; i++)
	{
		cell_idx = i/4;
		tinycell_idx = i%4*2;
		field_val = ((this->bf[cell_idx] & (0x03<<tinycell_idx)) >> tinycell_idx);

		col_cnt++;
		std::cout << "|" << mark[field_val] ;
		if(col_cnt == this->bf_size)
		{
			std::cout << "|" << std::endl;
			col_cnt = 0;
		}
	}


}
  
uint8_t Board::get_size(void){return this-> bf_size;}

bool Board::is_board_full(void)
{
	if(this->pawns_amount == (this->bf_size * this->bf_size)) return true;
	return false;
}
