 #ifndef PLAYER_HPP_
 #define PLAYER_HPP_
 #include "Pair.hpp"
 class Player_
 {
 private:
     bool my_turn;
     bool figure;
     Pair Last_move;

 public:
     Player(/* args */);
     ~Player();
     virtual int move(){return 0;}; 
     void Print_move(){std::cout << "X : "<<(int)(Last_move.x()) <<" Y : " <<(int)(Last_move.y()) <<std::endl;}
     Pair get_move(){return Last_move;};        
     void set_move(uint8_t x, uint8_t y){
         Last_move.set_x(x);
         Last_move.set_y(y);};

 };
    
 #endif
