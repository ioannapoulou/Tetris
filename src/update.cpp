#include <string>
#include <iostream>
#include <time.h>
#include "raylib.h"

#include "update.hpp"


int CreateNew=0;
int result=0;
int number;


void Update(Board& b,int Board_width,int Board_height)
{ 
    if(CreateNew==0)
    {
        number=rand() % 5 + 1;
        b.create_shape(number);
        CreateNew=1;
    }
    else if(CreateNew==1)
    {
        result=b.move_down(number);
        if((b.get_pos1()>=Board_height-1 and number==Straight) or (number==Square and b.get_pos1()>=Board_height-2) or (number==L and b.get_pos1()>=Board_height-3) or (number==T and b.get_pos1()>=Board_height-2) or (number==SandZ and b.get_pos1()>=Board_height-3))
        {
            CreateNew=0;
        }
        if(result==1)
        {
            CreateNew=0;
        }
    }

    if ((IsKeyDown(KEY_RIGHT)) and ((b.get_pos2()+4<Board_width and number==Straight) or (number==Square and b.get_pos2()+2<Board_width) or (number==L and b.get_pos2()+2<Board_width) or (number==T and b.get_pos2()+3<Board_width) or (number==SandZ and b.get_pos2()+2<Board_width)))
    {
        b.move_right(number);
    }
    else if ((IsKeyDown(KEY_LEFT)) and b.get_pos2()-1>=0)
    {
        b.move_left(number);
    }
}


