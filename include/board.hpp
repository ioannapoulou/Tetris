class Board
{
    int pos1,pos2;
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
        void move_right(int color);
        void move_left(int color);
        void set_board(int pos1,int pos2,int value);
};