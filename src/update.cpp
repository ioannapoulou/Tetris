#include <string>
#include <iostream>
#include <time.h>
#include "raylib.h"

#include "update.hpp"


int CreateNew=0;
int result=0;
int number;
int number2=-1;
float timer;
int right=0;
int left=0;
int down=0;
int up=0;
int form=0;


int func(Board& b,int Board_width,int Board_height)
{
    if(CreateNew==0)
    {
        form=0;
        if(number2==-1)
        {
            number=rand()%5 +1;
            number2=rand()%5 +1;
        }
        else 
        {
            number=number2;
            number2=rand()%5 +1;
        }

        int End=b.create_shape(number);
        if(End==1)
        {
            return 1;
        }
        else
        {
            CreateNew=1;
        }
    }
    else if(CreateNew==1)
    {
        result=b.move_down(number);
        if(number==Straight)
        {
            if ( (b.get_pos1()>=Board_height-1 and form==0) or (b.get_pos1()>=Board_height-4 and form==1) )
            {
                CreateNew=0;
            }
            if(result==1)
            {
                CreateNew=0;
            }
        }

        else if(number==L)
        {
            if ( (b.get_pos1()>=Board_height-3 and form==0) or (b.get_pos1()>=Board_height-1 and form==1) or (b.get_pos1()>=Board_height-1 and form==2) or (b.get_pos1()>=Board_height-2 and form==3) )
            {
                CreateNew=0;
            }
            if(result==1)
            {
                CreateNew=0;
            }
        }
        else if(number==SandZ)
        {
            if( ( (b.get_pos1()>=Board_height-3) and (form==0) ) or ( (b.get_pos1()>=Board_height-1) and (form==1) ) )
            {
                CreateNew=0;
            }
            if(result==1)
            {
                CreateNew=0;
            }
        }
        else if(number==Square)
        {
            if(b.get_pos1()>=Board_height-2)
            {
                CreateNew=0;
            }
            if(result==1)
            {
                CreateNew=0;
            }
        }
        else if(number==T)
        {
            if( ( (b.get_pos1()>=Board_height-2) and (form==0) ) or ( (b.get_pos1()>=Board_height-3) and (form==1) )   or ( (b.get_pos1()>=Board_height-1) and (form==2) )  or ( (b.get_pos1()>=Board_height-3) and (form==3) )   ) 
            {
                CreateNew=0;
            }
            if(result==1)
            {
                CreateNew=0;
            }
        }

    }
    if(up==1)
    {
        if(number==Straight)
        {
            form=b.move_up_straight(number,form,Board_width,Board_height);
        }
        else if(number==L)
        {
            form=b.move_up_L(number,form,Board_width,Board_height);
        }
        else if(number==SandZ)
        {
            form=b.move_up_SandZ(number,form,Board_width,Board_height);
        }
        else if(number==T)
        {
            form=b.move_up_T(number,form,Board_width,Board_height);
        }
        up=0;
    }
    if  (right==1)
    {
        if(number==Straight)
        {
            if( (b.get_pos2()+4<Board_width and form==0) or (b.get_pos2()+1<Board_width and form==1) )
            {
                b.move_right(number);
                right=0;
            }
        }
        else if(number==L)
        {
            if( (b.get_pos2()+2<Board_width and form==0) or (b.get_pos2()+3<Board_width and form==1)  or (b.get_pos2()+1<Board_width and form==2) or (b.get_pos2()+3<Board_width and form==3) )
            {
                b.move_right(number);
                right=0;
            }
        }
        else if(number==SandZ)
        {
            if( (b.get_pos2()+2<Board_width and form==0) or (b.get_pos2()+3<Board_width and form==1)  )
            {
                b.move_right(number);
                right=0;
            }
        }
        else if(number==Square)
        {
            if( b.get_pos2()+2<Board_width )
            {
                b.move_right(number);
                right=0;
            }
        }
        else if(number==T)
        {
            if( ( (b.get_pos2()+3<Board_width) and (form==0) ) or ( (b.get_pos2()+2<Board_width) and (form==1 ) )  or ( (b.get_pos2()+3<Board_width) and (form==2 ) )  or ( (b.get_pos2()+1<Board_width) and (form==3 ) )  )  
            {
                b.move_right(number);
                right=0;
            }
        }
    } 
    
    else if (left==1)
    {
        if( ( (number==Straight) or(number==Square) or(number==SandZ) ) and (b.get_pos2()-1>=0) )
        {
            b.move_left(number);
            left=0;
        }
        else if(number==L)
        {
            if( (b.get_pos2()-1>=0 and form==0) or (b.get_pos2()-1>=0 and form==1) or (b.get_pos2()-2>=0 and form==2) or (b.get_pos2()-1>=0 and form==3))
            {
                b.move_left(number);
                left=0;
            }
        }
        else if(number==T)
        {
            if( (b.get_pos2()-1>=0 and form==0) or (b.get_pos2()-1>=0 and form==1) or (b.get_pos2()-1>=0 and form==2) or (b.get_pos2()-2>=0 and form==3))
            {
                b.move_left(number);
                left=0;
            }
        }
    }    
    return 0;
}

int* Update(Board& b,int Board_width,int Board_height,int first_time)
{   
    int End;
    int* result=new int[3];
    if(IsKeyPressed(KEY_RIGHT))
    {
        right=1;
    }
    if(IsKeyPressed(KEY_LEFT))
    {
        left=1;
    }
    if(IsKeyPressed(KEY_DOWN))
    {
        down=1;
    }
    if(IsKeyPressed(KEY_UP))
    {
        up=1;
    }

    timer=timer+GetFrameTime();

    if(first_time==1)
    {
        End=func(b,Board_width,Board_height);
    }
    else
    {
        if(timer>=0.2 and down==1)
        {
            down=0;
            End=func(b,Board_width,Board_height);
            timer=0;
        }
        else if(timer>=0.5 and down==0)
        {
            End=func(b,Board_width,Board_height);
            timer=0;
        }
    }
    result[0]=CreateNew;
    result[1]=number2;
    result[2]=End;
    return result;
}





// or (number==Square and b.get_pos1()>=Board_height-2) or (number==L and b.get_pos1()>=Board_height-3 and form==0) or (number==L and b.get_pos1()>=Board_height-1 and form==1) or (number==L and b.get_pos1()>=Board_height-1 and form==2)or (number==T and b.get_pos1()>=Board_height-2) or (number==SandZ and b.get_pos1()>=Board_height-3))
// or (number==Square and b.get_pos2()+2<Board_width) or (number==L and b.get_pos2()+2<Board_width) or(number==L and form==1 and b.get_pos2()+3<Board_width) or (number==T and b.get_pos2()+3<Board_width) or (number==SandZ and b.get_pos2()+2<Board_width)))
// (  (left==1) and ((number!=L and b.get_pos2()-1>=0) or (b.get_pos2()-2>=0 and form==2 and number==L)  or (number==L and form!=2 and b.get_pos2()-1>=0)) ) 