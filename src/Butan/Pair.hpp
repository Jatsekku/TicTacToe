 #ifndef PAIR_HPP_
 #define PAIR_HPP_
 #include <cstdint>
 #include <iostream>
 class Pair
 {
 private:
     uint8_t _x;
     uint8_t _y;
 public:
     Pair(/* args */);
     ~Pair();
    uint8_t x(){return _x;};
    uint8_t y(){return _y;};
    void set_x(uint8_t val){_x=val;};
    void set_y(uint8_t val){_y=val;};
    void display(){std::cout << "x : " << _x << " y : "<< _y << std::endl;};
};
 

 #endif