#include "raylib.h"
#include <iostream>
#include <time.h>

#include "graphics.hpp"
#include "update.hpp"
#include "board.hpp"

using namespace std;



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
        Draw(b,10,16,result[0],result[1],800,1000);
        while (!WindowShouldClose()) 
        {
            result=Update(b,10,16,0);
            Draw(b,10,16,result[0],result[1],800,1000);
        }

        // De-Initialization
        CloseWindow();
    }
}

