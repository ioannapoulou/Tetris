#ifndef BOARDGAME 
#define BOARDGAME

#include<tuple> // for tuple


class Board
{
    std::tuple <int, int> posa;
    std::tuple <int, int> posb;
    std::tuple <int, int> posc;
    std::tuple <int, int> posd;
    int**b;
    int score;
    public:
        Board(int width,int height);
        int get_score();
        void increase_score(int number);
        int get_pos1();
        int get_pos2();
        int** get_board();
        void create_shape(int color);
        int move_down(int color);
        void move_right(int color,int form);
        void move_left(int color);
        void move_up(int color);
        void set_board(int pos1,int pos2,int value);
};

#endif