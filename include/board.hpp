class Board
{
    int pos1,pos2;
    int**b;
    public:
        Board();
        int get_pos1();
        int get_pos2();
        int** get_board();
        void create_shape(int color);
        int move_down(int color);
        void move_right(int color);
        void move_left(int color);
};