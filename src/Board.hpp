 #ifndef BOARD_HPP_
 #define BOARD_HPP_
 
    #include <cstdint>

	class Board
    {
        private:
            uint8_t bf_size;
            uint16_t cell_number;
            uint16_t pawns_amount;
            uint8_t *bf;

        public:
            Board(uint8_t bf_size);
            ~Board();
            void display();

            int8_t  set_field(uint8_t x, uint8_t y, uint8_t mark);
            uint8_t get_field(uint8_t x, uint8_t y);

            int8_t  set_field(uint16_t idx, uint8_t mark);
            uint8_t get_field(uint16_t idx);

            bool is_board_full(void);

            void reset(void);
            uint8_t* get_bf(void);
            uint8_t get_size(void);
    };
 
#endif
