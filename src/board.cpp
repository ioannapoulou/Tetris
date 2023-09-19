#include "board.hpp"
#include "raylib.h"
#include "util.hpp"
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


Board::Board(int width,int height)
{
    score=0;
    b = new int*[height];
    for (int i = 0; i < height; i++) {
        b[i] = new int[width];
    }

    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            b[i][j]=0;
        }
    }  
 
}

int Board::create_shape(int color)
{
    if(color==Straight and b[0][2]==0 and b[0][3]==0 and  b[0][4]==0 and b[0][5]==0)
    {
        posa= make_tuple(0,2);
        posb= make_tuple(0,3);
        posc= make_tuple(0,4);
        posd= make_tuple(0,5);
        b[0][2]=Straight;
        b[0][3]=Straight;
        b[0][4]=Straight;
        b[0][5]=Straight;
    }
    else if(color==Square and b[0][3]==0 and b[1][4]==0 and b[1][3]==0 and b[0][4]==0)
    {
        posa= make_tuple(0,3);
        posb= make_tuple(1,4);
        posc= make_tuple(1,3);
        posd= make_tuple(0,4);
        b[0][3]=Square;
        b[1][4]=Square;
        b[1][3]=Square;
        b[0][4]=Square;

    }
    else if(color==T and b[0][2]==0 and b[0][3]==0 and b[0][4]==0 and b[1][3]==0)
    {
        posa= make_tuple(0,2);
        posb= make_tuple(0,3);
        posc= make_tuple(0,4);
        posd= make_tuple(1,3);
        b[0][2]=T;
        b[0][3]=T;
        b[0][4]=T;
        b[1][3]=T;
    }
    else if(color==L and b[0][2]==0 and b[1][2]==0 and b[2][2]==0 and b[2][3]==0)
    {
        posa= make_tuple(0,2);
        posb= make_tuple(1,2);
        posc= make_tuple(2,3);
        posd= make_tuple(2,2);
        b[0][2]=L;
        b[1][2]=L;
        b[2][3]=L;
        b[2][2]=L;
    }
    else if(color==SandZ and b[0][2]==0 and b[1][2]==0 and b[1][3]==0 and b[2][3]==0)
    {
        posa= make_tuple(0,2);
        posb= make_tuple(1,2);
        posc= make_tuple(1,3);
        posd= make_tuple(2,3);
        b[0][2]=SandZ;
        b[1][2]=SandZ;
        b[1][3]=SandZ;
        b[2][3]=SandZ;
    }  
    else
    {
        return 1;
    }
    return 0;
}


bool sortdesc(const tuple<int, int>& a,
              const tuple<int, int>& b)
{
    return (get<0>(a) > get<0>(b));
}

int Board::move_down(int color)
{
    vector<tuple<int, int> > v;
    v.push_back(posa);
    v.push_back(posb);
    v.push_back(posc);
    v.push_back(posd);

    
    bool flag=true;
    for (int i = 0; i < 4; i++)
    {

        tuple <int, int> help_pos;
        help_pos= make_tuple(get<0>(v[i])+1,get<01>(v[i]));

        if( b[get<0>(v[i])+1] [get<01>(v[i])] !=0 and help_pos!=posa and help_pos!=posb and help_pos!=posc and help_pos!=posd)
        {
            flag=false;
            return 1;  
        }
    }

    tuple <int, int> help_tuple1,help_tuple2,help_tuple3,help_tuple4;

    help_tuple1= make_tuple(get<0>(v[0])+1,get<01>(v[0]));
    help_tuple2= make_tuple(get<0>(v[1])+1,get<01>(v[1]));
    help_tuple3= make_tuple(get<0>(v[2])+1,get<01>(v[2]));
    help_tuple4= make_tuple(get<0>(v[3])+1,get<01>(v[3]));

    posa=help_tuple1;
    posb=help_tuple2;
    posc=help_tuple3;
    posd=help_tuple4;

    sort(v.begin(), v.end(), sortdesc);
    if(flag==true)
    {
        for (int i = 0; i < 4; i++)
        {
            b[get<0>(v[i])+1] [get<01>(v[i])]=color;
            b[get<0>(v[i])] [get<01>(v[i])]=0;
        }
    }

    return 0;    
}

bool sortbysec(const tuple<int, int>& a,
               const tuple<int, int>& b)
{
    return (get<1>(a) > get<1>(b));
}

void Board::move_right(int color)
{
    vector<tuple<int, int> > v;
    v.push_back(posa);
    v.push_back(posb);
    v.push_back(posc);
    v.push_back(posd);

    
    bool flag=true;
    for (int i = 0; i < 4; i++)
    {

        tuple <int, int> help_pos;
        help_pos= make_tuple(get<0>(v[i]),get<01>(v[i])+1);

        if( b[get<0>(v[i])] [get<01>(v[i])+1] !=0 and help_pos!=posa and help_pos!=posb and help_pos!=posc and help_pos!=posd)
        {
            flag=false;  
        }
    }

    tuple <int, int> help_tuple1,help_tuple2,help_tuple3,help_tuple4;

    help_tuple1= make_tuple(get<0>(v[0]),get<01>(v[0])+1);
    help_tuple2= make_tuple(get<0>(v[1]),get<01>(v[1])+1);
    help_tuple3= make_tuple(get<0>(v[2]),get<01>(v[2])+1);
    help_tuple4= make_tuple(get<0>(v[3]),get<01>(v[3])+1);

    posa=help_tuple1;
    posb=help_tuple2;
    posc=help_tuple3;
    posd=help_tuple4;

    sort(v.begin(), v.end(), sortbysec);
    if(flag==true)
    {
        for (int i = 0; i < 4; i++)
        {
            b[get<0>(v[i])] [get<01>(v[i])+1]=color;
            b[get<0>(v[i])] [get<01>(v[i])]=0;
        }
    }

    return ;    
}

bool sortbysecasc(const tuple<int, int>& a,
               const tuple<int, int>& b)
{
    return (get<1>(a) < get<1>(b));
}

void Board::move_left(int color)
{
    vector<tuple<int, int> > v;
    v.push_back(posa);
    v.push_back(posb);
    v.push_back(posc);
    v.push_back(posd);

    
    bool flag=true;
    for (int i = 0; i < 4; i++)
    {

        tuple <int, int> help_pos;
        help_pos= make_tuple(get<0>(v[i]),get<01>(v[i])-1);

        if( b[get<0>(v[i])] [get<01>(v[i])-1] !=0 and help_pos!=posa and help_pos!=posb and help_pos!=posc and help_pos!=posd)
        {
            flag=false;  
        }
    }

    tuple <int, int> help_tuple1,help_tuple2,help_tuple3,help_tuple4;

    help_tuple1= make_tuple(get<0>(v[0]),get<01>(v[0])-1);
    help_tuple2= make_tuple(get<0>(v[1]),get<01>(v[1])-1);
    help_tuple3= make_tuple(get<0>(v[2]),get<01>(v[2])-1);
    help_tuple4= make_tuple(get<0>(v[3]),get<01>(v[3])-1);

    posa=help_tuple1;
    posb=help_tuple2;
    posc=help_tuple3;
    posd=help_tuple4;

    sort(v.begin(), v.end(), sortbysecasc);
    if(flag==true)
    {
        for (int i = 0; i < 4; i++)
        {
            b[get<0>(v[i])] [get<01>(v[i])-1]=color;
            b[get<0>(v[i])] [get<01>(v[i])]=0;
        }
    }

    return ;
}


int Board::move_up(int color,int form)
{
    if(color==Straight)
    {
        if(form==0)
        {
            vector<tuple<int, int> > v;
            v.push_back(posa);
            v.push_back(posb);
            v.push_back(posc);
            v.push_back(posd);

            sort(v.begin(), v.end(), sortbysec);

            if( get<0>(v[0]) <=2 )
            {
                for (int i=0;i<4;i++)
                {
                    b[get<0>(v[i])] [get<01>(v[i])]=0;
                    
                }
                for (int i=0;i<4;i++)
                {
                    b[i] [get<01>(v[3])]=color;
                }
                tuple <int, int> help_tuple1,help_tuple2,help_tuple3,help_tuple4;

                help_tuple1= make_tuple(0,get<01>(v[3]));
                help_tuple2= make_tuple(1,get<01>(v[3]));
                help_tuple3= make_tuple(2,get<01>(v[3]));
                help_tuple4= make_tuple(3,get<01>(v[3]));

                posa=help_tuple1;
                posb=help_tuple2;
                posc=help_tuple3;
                posd=help_tuple4;
            }


            else 
            {
                for (int i=0;i<4;i++)
                {
                    b[get<0>(v[i])] [get<01>(v[i])]=0;
                    b[get<0>(v[3])-i] [get<01>(v[3])]=color;
                }
                b[get<0>(v[3])] [get<01>(v[3])]=color;
                tuple <int, int> help_tuple1,help_tuple2,help_tuple3,help_tuple4;

                help_tuple1= make_tuple(get<0>(v[3])-3,get<01>(v[3]));
                help_tuple2= make_tuple(get<0>(v[3])-2,get<01>(v[3]));
                help_tuple3= make_tuple(get<0>(v[3])-1,get<01>(v[3]));
                help_tuple4= make_tuple(get<0>(v[3]),get<01>(v[3]));

                posa=help_tuple1;
                posb=help_tuple2;
                posc=help_tuple3;
                posd=help_tuple4;
            }
            form=1;
        }
        else
        {
            
            form=0;
        }
    }
    return form;;
}


int Board::get_pos1()
{
    return get<0>(posa);
}

int Board::get_pos2()
{
    return get<01>(posa);
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




