#include "board.hpp"
#include "raylib.h"
#include "util.hpp"
#include <iostream>

Board::Board()
{
    score=0;
    b = new int*[16];
    for (int i = 0; i < 16; i++) {
        b[i] = new int[16];
    }

    for (int i=0;i<=15;i++)
    {
        for (int j=0;j<=15;j++)
        {
            b[i][j]=0;
        }
    }   
}

void Board::create_shape(int color)
{
    if(color==Straight and b[0][2]==0 and b[0][3]==0 and  b[0][4]==0 and b[0][5]==0)
    {
        pos1=0;
        pos2=2;
        b[0][2]=Straight;
        b[0][3]=Straight;
        b[0][4]=Straight;
        b[0][5]=Straight;
    }
    else if(color==Square and b[0][3]==0 and b[1][4]==0 and b[1][3]==0 and b[0][4]==0)
    {
        pos1=0;
        pos2=3;
        b[0][3]=Square;
        b[1][4]=Square;
        b[1][3]=Square;
        b[0][4]=Square;

    }
    else if(color==T and b[0][2]==0 and b[0][3]==0 and b[0][4]==0 and b[1][3]==0)
    {
        pos1=0;
        pos2=2;
        b[0][2]=T;
        b[0][3]=T;
        b[0][4]=T;
        b[1][3]=T;
    }
    else if(color==L and b[0][2]==0 and b[1][2]==0 and b[2][2]==0 and b[2][3]==0)
    {
        pos1=0;
        pos2=2;
        b[0][2]=L;
        b[1][2]=L;
        b[2][3]=L;
        b[2][2]=L;
    }
    else if(color==SandZ and b[0][2]==0 and b[1][2]==0 and b[1][3]==0 and b[2][3]==0)
    {
        pos1=0;
        pos2=2;
        b[0][2]=SandZ;
        b[1][2]=SandZ;
        b[1][3]=SandZ;
        b[2][3]=SandZ;
    }  
}


int Board::move_down(int color)
{
    if(color==Straight and b[pos1+1][pos2]==0 and b[pos1+1][pos2+1]==0 and  b[pos1+1][pos2+2]==0 and b[pos1+1][pos2+3]==0)
    {
        b[pos1][pos2]=0;
        b[pos1][pos2+1]=0;
        b[pos1][pos2+2]=0;
        b[pos1][pos2+3]=0;
        b[pos1+1][pos2+1]=color;
        b[pos1+1][pos2+2]=color;
        b[pos1+1][pos2+3]=color;
        b[pos1+1][pos2]=color;
        pos1=pos1+1;
    }
    else if(color==Square and b[pos1+2][pos2]==0 and b[pos1+2][pos2+1]==0)
    {
        b[pos1][pos2]=0;
        b[pos1][pos2+1]=0;
        b[pos1+2][pos2]=color;
        b[pos1+2][pos2+1]=color;
        pos1=pos1+1;

    }
    else if(color==T and b[pos1+1][pos2]==0 and b[pos1+1][pos2+2]==0 and b[pos1+2][pos2+1]==0)
    {
        b[pos1][pos2]=0;
        b[pos1][pos2+1]=0;
        b[pos1][pos2+2]=0;
        b[pos1+1][pos2]=color;
        b[pos1+1][pos2+2]=color;
        b[pos1+2][pos2+1]=color;
        pos1=pos1+1;
    }
    else if(color==L and b[pos1+3][pos2]==0 and b[pos1+3][pos2+1]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+2][pos2+1]=0;
        b[pos1+3][pos2]=color;
        b[pos1+3][pos2+1]=color;
        pos1=pos1+1;
    }
    else if(color==SandZ and b[pos1+2][pos2]==0 and b[pos1+3][pos2+1]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2+1]=0;
        b[pos1+2][pos2]=color;
        b[pos1+3][pos2+1]=color;
        pos1=pos1+1;
    }
    else
    {
        return 1;
    }
    return 0;
}


void Board::move_right(int color)
{
    if(color==Straight and b[pos1][pos2+4]==0)
    {
        b[pos1][pos2]=0;
        b[pos1][pos2+4]=color;
    }
    else if(color==Square and b[pos1+1][pos2+2]==0 and b[pos1][pos2+2]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2]=0;
        b[pos1][pos2+2]=color;
        b[pos1+1][pos2+2]=color;
    }
    else if(color==T and b[pos1][pos2+3]==0 and b[pos1+1][pos2+2]==0 )
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2+1]=0;
        b[pos1+1][pos2+2]=color;
        b[pos1][pos2+3]=color;
    }
    else if(color==L and b[pos1][pos2+1]==0 and b[pos1+1][pos2+1]==0 and b[pos1+2][pos2+2]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2]=0;
        b[pos1+2][pos2]=0;
        b[pos1][pos2+1]=color;
        b[pos1+1][pos2+1]=color;
        b[pos1+2][pos2+2]=color;
    }
    else if(color==SandZ and b[pos1][pos2+1]==0 and b[pos1+1][pos2+2]==0 and b[pos1+2][pos2+2]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2]=0;
        b[pos1+2][pos2+1]=0;
        b[pos1][pos2+1]=color;
        b[pos1+1][pos2+2]=color;
        b[pos1+2][pos2+2]=color;
    }
    pos2=pos2+1;
}


void Board::move_left(int color)
{
    if(color==Straight and b[pos1][pos2-1]==0)
    {
        b[pos1][pos2+3]=0;
        b[pos1][pos2-1]=color;
    }
    else if(color==Square and b[pos1][pos2-1]==0 and b[pos1+1][pos2-1]==0)
    {
        b[pos1][pos2+1]=0;
        b[pos1+1][pos2+1]=0;
        b[pos1][pos2-1]=color;
        b[pos1+1][pos2-1]=color;
    }
    else if(color==T and b[pos1][pos2-1]==0 and b[pos1+1][pos2]==0)
    {
        b[pos1][pos2+2]=0;
        b[pos1+1][pos2+1]=0;
        b[pos1][pos2-1]=color;
        b[pos1+1][pos2]=color;
    }
    else if(color==L and b[pos1][pos2-1]==0 and b[pos1+1][pos2-1]==0 and b[pos1+2][pos2-1]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2]=0;
        b[pos1+2][pos2+1]=0;
        b[pos1][pos2-1]=color;
        b[pos1+1][pos2-1]=color;
        b[pos1+2][pos2-1]=color;
    }
    else if(color==SandZ and b[pos1][pos2-1]==0 and b[pos1+1][pos2-1]==0 and b[pos1+2][pos2]==0)
    {
        b[pos1][pos2]=0;
        b[pos1+1][pos2+1]=0;
        b[pos1+2][pos2+1]=0;
        b[pos1][pos2-1]=color;
        b[pos1+1][pos2-1]=color;
        b[pos1+2][pos2]=color;
    }
    pos2=pos2-1;
}


int Board::get_pos1()
{
    return pos1;
}

int Board::get_pos2()
{
    return pos2;
}


int** Board::get_board()
{
    return b;
}


int Board::get_score()
{
    return score;
}

void Board::increase_score(int number)
{
    score=score+number;
}

void Board::set_board(int pos1,int pos2,int value)
{
    b[pos1][pos2]=value;
}


