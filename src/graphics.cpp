#include <string>
#include "raylib.h"
#include <iostream>
#include <time.h>


#include "graphics.hpp"



using namespace std;


void Draw(Board& board,int Board_width,int Board_height)
{    
    BeginDrawing();
    DrawFPS(0,0);
    ClearBackground(RAYWHITE);
    for (int y = 0; y < Board_height; y++) {
        // all_line=true;
        for (int x = 0; x < Board_width; x++) {
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
            // if((board.get_board()[y][x]==0))
            // {
            //     all_line=false;
            // }
        }
        // if(all_line==true and CreateNew==0)
        // {
        //     for(int x=0;x<Board_width;x++)
        //     {
        //         board.set_board(y,x,0);
        //     }
        //     board.increase_score(100);
        // }
    }
    EndDrawing();
}


