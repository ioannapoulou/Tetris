#include <string>
#include "raylib.h"
#include <iostream>
#include <time.h>


#include "graphics.hpp"
#include "util.hpp"


using namespace std;


void Draw(Board& board,int Board_width,int Board_height,int CreateNew)
{    
    BeginDrawing();
    bool all_line;
    ClearBackground(RAYWHITE);
    for (int y = 0; y < Board_height; y++) {
        all_line=true;
        for (int x = 0; x < Board_width; x++) 
        {
            DrawText(TextFormat("Score: %d", board.get_score()), 0, 0, 40, DARKGRAY);
            if(board.get_board()[y][x]==0)
            {
                DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
                DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,WHITE);
            }
            else if(board.get_board()[y][x]==1)
            {
                DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
                DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,RED);
            }
            else if(board.get_board()[y][x]==2)
            {
                DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
                DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,GREEN);
            }
            else if(board.get_board()[y][x]==3)
            {
                DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
                DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,BLUE);
            }
            else if(board.get_board()[y][x]==4)
            {
                DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
                DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,YELLOW);
            }
            else if(board.get_board()[y][x]==5)
            {
                DrawRectangle(x * 50, y * 50+50, 50, 50,BLACK);
                DrawRectangle(x * 50 +2, y * 50 +52, 46, 46,PURPLE);
            }
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
    EndDrawing();
}

int DrawStartWindow(int width,int height)
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
        DrawRectangle(width-MeasureText("EXIT",30)-70,700,MeasureText("EXIT",30)+40,50,DARKGRAY);
        DrawText("EXIT",width-MeasureText("EXIT",30)-50,710, 30, BLACK); 
        DrawRectangle(0,900,800,100,MyOrange);
        DrawText("Made by Ioanna Poulou",width/2-MeasureText("Made by Ioanna Poulou",20)/2,940, 20, DARKGRAY);

        Image image = LoadImage("images/shapes.png");
        Texture2D texture = LoadTextureFromImage(image);

        // Resize the image if needed
        int newWidth = 300; // Set the new width you want
        int newHeight = 300; // Set the new height you want
        ImageResize(&image, newWidth, newHeight);

        // Unload the previous texture and create a new one from the resized image
        UnloadTexture(texture);
        texture = LoadTextureFromImage(image);
        DrawTexture(texture,50, 600, RAYWHITE);

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
        DrawRectangle(width-MeasureText("EXIT",30)-70,700,MeasureText("EXIT",30)+40,50,DARKGRAY);
        DrawText("EXIT",width-MeasureText("EXIT",30)-50,710, 30, BLACK);
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
        DrawRectangle(width-MeasureText("EXIT",30)-70,700,MeasureText("EXIT",30)+40,50,DARKGRAY);
        DrawText("EXIT",width-MeasureText("EXIT",30)-50,710, 30, BLACK); 
        EndDrawing();
        WaitTime(0.5);
        return 1;
    }
    return 0;
}


