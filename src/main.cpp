#include "raylib.h"
#include <iostream>
#include <time.h>

#include "graphics.hpp"
#include "update.hpp"
#include "board.hpp"

using namespace std;

int paused=-1;

int main(void)
{
    srand(time(NULL));
    InitWindow(800,1000, "Tetris");
    int closed=DrawStartWindow(800,1000);
    
    if (closed==1)
    {
        Board b(10,16);
        SetTargetFPS(60);
        int* result=Update(b,10,16,1);
        Draw(b,10,16,result[0],result[1],800,1000,-1);
        while (!WindowShouldClose()) 
        {
            if(GetKeyPressed()==KEY_P)
            {
                paused=paused*(-1);
            }
            if(paused==-1)
            {
                result=Update(b,10,16,0);
            }
            Draw(b,10,16,result[0],result[1],800,1000,paused);
        }

        // De-Initialization
        CloseWindow();
    }
}

