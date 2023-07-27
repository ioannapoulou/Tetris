#include <string>
#include "game.hpp"
#include "raylib.h"
#include "board.hpp"
#include <iostream>
#include <time.h>
#include <util.hpp>

using namespace std;


Game::Game(int Width,int Height,int BoardSize)
{
    
    InitWindow(Width,Height, "Tetris");
    SetTargetFPS(60);

    // Main game loop
    int** b = new int*[16];
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

    srand(time(NULL));
    Board board; 
    
    int CreateNew=0;
    int number;
    while (!WindowShouldClose()) {
        int result=0;
        if(CreateNew==0)
        {
            number=1;
            board.create_shape(number);
            CreateNew=1;
        }
        else if(CreateNew==1)
        {
            result=board.move_down(number);
            if((board.get_pos1()>=15 and number==Straight) or (number==Square and board.get_pos1()>=14) or (number==L and board.get_pos1()>=13) or (number==T and board.get_pos1()>=14) or (number==SandZ and board.get_pos1()>=13))
            {
                CreateNew=0;
            }
            if(result==1)
            {
                CreateNew=0;
            }
        }

        if ((IsKeyDown(KEY_RIGHT)) and ((board.get_pos2()+4<=15 and number==Straight) or (number==Square and board.get_pos2()+2<=15) or (number==L and board.get_pos2()+2<=15) or (number==T and board.get_pos2()+3<=15) or (number==SandZ and board.get_pos2()+2<=15)))
        {
            board.move_right(number);
        }
        else if ((IsKeyDown(KEY_LEFT)) and board.get_pos2()-1>=0)
        {
            board.move_left(number);
        }
        
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Draw the board
        bool all_line;
        for (int y = 0; y < BoardSize; y++) {
            all_line=true;
            for (int x = 0; x < BoardSize; x++) {
                // Alternate colors for each tile
                // Draw the tile
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
                if((x!=0 and board.get_board()[y][x]!=board.get_board()[y][x-1]) or (board.get_board()[y][x]==0))
                {
                    all_line=false;
                }
            }
            if(all_line==true and CreateNew==0)
            {
                for(int x=0;x<BoardSize;x++)
                {
                    board.set_board(y,x,0);
                }
                board.increase_score(100);
            }
        }

        EndDrawing();
        if (IsKeyDown(KEY_DOWN))
        {
            WaitTime(0.2);
        }
        else
        {
            WaitTime(0.5);
        }
    }

    // De-Initialization
    CloseWindow();  
}
