#include "Pair.hpp"
#include "Player_.hpp"
#include "Player_human.hpp"
#include "iostream"

 Player_human::Player_human(/* args */)
 { 
 }

 Player_human::~Player_human()
 {
 }

int Player_human::move()
{
    uint16_t x,y;
    std::cout << "Podaj koordynaty ruchu  w formacie x y :" <<std::endl;
    std::cin >> x;
    std::cin >> y;
    this->set_move(x,y);
    return 1;
}


