#include <string>
#include "raylib.h"
#include <iostream>
#include <time.h>


#include "graphics.hpp"
#include "util.hpp"

using namespace std;

float PauseTimer=0;
float LastTimePausedIsShowed=0;


void Pause(int width,int height)
{
    
    PauseTimer=PauseTimer+GetFrameTime();
    if(PauseTimer<1)
    {
        LastTimePausedIsShowed=PauseTimer;
        DrawRectangle(width/2-MeasureText("PAUSED",150)/2-15,height/2-90,MeasureText("PAUSED",150)+30,175,MyLightOrange);
        DrawText("PAUSED",width/2-MeasureText("PAUSED",150)/2,height/2-75,150, MyBlack);
    }
    else if(PauseTimer>=2*LastTimePausedIsShowed)
    {
        PauseTimer=0;
    }
}


void End(int width,int height)
{
    
    PauseTimer=PauseTimer+GetFrameTime();
    if(PauseTimer<1)
    {
        LastTimePausedIsShowed=PauseTimer;
        DrawRectangle(width/2-MeasureText("GAME OVER",120)/2-15,height/2-90,MeasureText("GAME OVER",120)+30,175,MyLightRed);
        DrawText("GAME OVER",width/2-MeasureText("GAME OVER",120)/2,height/2-75,120, MyBlack);
    }
    else if(PauseTimer>=2*LastTimePausedIsShowed)
    {
        PauseTimer=0;
    }
}


Texture2D FindNextTexture(int NumberNext,Texture2D* textures)
{

    Texture2D texture;

    if(NumberNext==1)
    {
        texture=textures[0];
    }
    else if(NumberNext==2)
    {
        texture=textures[1];
    }
    else if(NumberNext==3)
    {
        texture=textures[2];
    }
    else if (NumberNext==4)
    {
        texture=textures[3];
    }
    else if(NumberNext==5)
    {
        texture=textures[4];
    }
    return texture;
}

int* FindPosOfNextShape(int NumberNext,int* pos)
{
    if(NumberNext==1)
    {
        pos[0]=600;
        pos[1]=200;
    }
    else if(NumberNext==2)
    {
        pos[0]=575;
        pos[1]=200;
    }
    else if(NumberNext==3)
    {
        pos[0]=600;
        pos[1]=200;
    }
    else if (NumberNext==4)
    {
        pos[0]=600;
        pos[1]=200;
    }
    else if(NumberNext==5)
    {
        pos[0]=550;
        pos[1]=200;
    }
    return pos;
}


void DrawBoard(int x,int y,Board& board)
{
    if(board.get_board()[y][x]==0)
    {
        DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
        DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,WHITE);
    }
    else if(board.get_board()[y][x]==1)
    {
        DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
        DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,YELLOW);
    }
    else if(board.get_board()[y][x]==2)
    {
        DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
        DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,PURPLE);
    }
    else if(board.get_board()[y][x]==3)
    {
        DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
        DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,ORANGE);
    }
    else if(board.get_board()[y][x]==4)
    {
        DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
        DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,GREEN);
    }
    else if(board.get_board()[y][x]==5)
    {
        DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
        DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,CYAN);
    }
    
}


void Draw(Board& board,int Board_width,int Board_height,int CreateNew,int NumberNext,int width,int height,int paused,int end,Texture2D* textures)
{    
    BeginDrawing();
    bool all_line;
    int posx,posy;
    ClearBackground(RAYWHITE);
    Texture2D texture;
    
    texture=FindNextTexture(NumberNext,textures);

    int * pos = new int[2];
    pos=FindPosOfNextShape(NumberNext,pos);
    posx=pos[0];
    posy=pos[1];
    delete pos;

    for (int y = 0; y < Board_height; y++) {
        all_line=true;
        for (int x = 0; x < Board_width; x++) 
        {
            DrawText(TextFormat("Score: %d", board.get_score()), 0, 0, 40, DARKGRAY);
            DrawBoard(x,y,board);
            if((board.get_board()[y][x]==0))
            {
                all_line=false;
            }
        }
        if(all_line==true and CreateNew==0)
        {
            for(int y2=y;y2>=1;y2--)
            {
                for (int x2=0;x2<Board_width;x2++)
                {
                    board.set_board(y2,x2,board.get_board()[y2-1][x2]);
                }
            }
            board.increase_score(100);
        }
    }
    DrawText("Next Shape",650-MeasureText("Next Shape",25)/2, 150, 25, DARKGRAY);
    DrawTexture(texture,posx, posy, RAYWHITE);

    DrawRectangle(width-MeasureText("PAUSE",30)-70,925,MeasureText("PAUSE",30)+40,50,DARKGRAY);
    DrawText("EXIT",width-MeasureText("PAUSE",30)-70+(MeasureText("PAUSE",30)+40)/2-(MeasureText("EXIT",30))/2,935, 30, BLACK);

    DrawRectangle(width-MeasureText("PAUSE",30)-70,850,MeasureText("PAUSE",30)+40,50,DARKGRAY);
    DrawText("PAUSE",width-MeasureText("PAUSE",30)-50,860, 30, BLACK); 

    if(GetKeyPressed()==KEY_ESCAPE)
    {
        CloseWindow();
    }
    if(paused==1)
        Pause(width,height);
    if(end==1)
        End(width,height);
    EndDrawing();
}

int DrawStartWindow(int width,int height,Texture2D texture)
{
    int result=GetKeyPressed();
    while (result!=KEY_ENTER and result!=KEY_ESCAPE) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Welcome to Tetris",width/2-MeasureText("Welcome to Tetris",50)/2, 220, 50, MyBlue);
        DrawText("Are you ready to play?",width/2-MeasureText("Are you ready to play?",35)/2 , 290, 35, MyOrange);
        DrawText("(Press 'Enter' to start OR 'ESCAPE' to leave)",width/2-MeasureText("(Press 'Enter' to start OR 'ESCAPE' to leave)",25)/2, 330, 25, DARKGRAY);
        DrawRectangle(width/2-MeasureText("START",60)/2 - 10,410,MeasureText("START",60)+20,70,MyGreen);
        DrawText("START", width/2-MeasureText("START",60)/2, 420, 60, DARKGRAY); 
        DrawTexture(texture,50, 515, RAYWHITE);
        DrawRectangle(0,900,800,100,MyOrange);
        DrawText("Made by Ioanna Poulou",width/2-MeasureText("Made by Ioanna Poulou",20)/2,940, 20, DARKGRAY);
        DrawRectangle(width-MeasureText("EXIT",30)-70,925,MeasureText("EXIT",30)+40,50,DARKGRAY);
        DrawText("EXIT",width-MeasureText("EXIT",30)-50,935, 30, BLACK); 

        EndDrawing();  
        result=GetKeyPressed();
    }
    if(GetKeyPressed()==KEY_ESCAPE)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to Tetris",width/2-MeasureText("Welcome to Tetris",50)/2, 220, 50, MyBlue);
        DrawText("Are you ready to play?",width/2-MeasureText("Are you ready to play?",35)/2 , 290, 35, MyOrange);
        DrawText("(Press 'Enter' to start OR 'ESCAPE' to leave)",width/2-MeasureText("(Press 'Enter' to start OR 'ESCAPE' to leave)",25)/2, 330, 25, DARKGRAY);
        DrawRectangle(width/2-MeasureText("START",60)/2 - 10,410,MeasureText("START",60)+20,70,MyGreen);
        DrawText("START", width/2-MeasureText("START",60)/2, 420, 60, DARKGRAY); 
        DrawTexture(texture,50, 515, RAYWHITE);
        DrawRectangle(0,900,800,100,MyOrange);
        DrawText("Made by Ioanna Poulou",width/2-MeasureText("Made by Ioanna Poulou",20)/2,940, 20, DARKGRAY);
        DrawRectangle(width-MeasureText("EXIT",30)-70,925,MeasureText("EXIT",30)+40,50,DARKGRAY);
        DrawText("EXIT",width-MeasureText("EXIT",30)-50,935, 30, BLACK); 
        EndDrawing();
        WaitTime(0.5);
        CloseWindow();
        return 0;
    }
    if(result==KEY_ENTER)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to Tetris",width/2-MeasureText("Welcome to Tetris",50)/2, 220, 50, MyBlue);
        DrawText("Are you ready to play?",width/2-MeasureText("Are you ready to play?",35)/2 , 290, 35, MyOrange);
        DrawText("(Press 'Enter' to start OR 'ESCAPE' to leave)",width/2-MeasureText("(Press 'Enter' to start OR 'ESCAPE' to leave)",25)/2, 330, 25, DARKGRAY);
        DrawRectangle(width/2-MeasureText("START",60)/2 - 10,410,MeasureText("START",60)+20,70,MyDarkGreen);
        DrawText("START", width/2-MeasureText("START",60)/2, 420, 60, DARKGRAY);
        DrawTexture(texture,50, 515, RAYWHITE);
        DrawRectangle(0,900,800,100,MyOrange);
        DrawText("Made by Ioanna Poulou",width/2-MeasureText("Made by Ioanna Poulou",20)/2,940, 20, DARKGRAY);
        DrawRectangle(width-MeasureText("EXIT",30)-70,925,MeasureText("EXIT",30)+40,50,DARKGRAY);
        DrawText("EXIT",width-MeasureText("EXIT",30)-50,935, 30, BLACK); 
        EndDrawing();
        WaitTime(0.5);
        return 1;
    }
    return 0;
}




