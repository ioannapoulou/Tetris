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
        int create_shape(int color);
        int move_down(int color);
        void move_right(int color);
        void move_left(int color);
        void set_board(int pos1,int pos2,int value);
        int move_up_straight(int color,int form,int Board_width,int Board_height);
        int move_up_L(int color,int form,int Board_width,int Board_height);
        int move_up_SandZ(int color,int form,int Board_width,int Board_height);
        int move_up_T(int color,int form,int Board_width,int Board_height);
};

#endif