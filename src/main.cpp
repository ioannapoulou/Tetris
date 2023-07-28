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
    InitWindow(400,400, "Tetris");
    SetTargetFPS(60);
    Board b(10,16);
    int result=Update(b,10,16,1);
    Draw(b,10,16,result);
    while (!WindowShouldClose()) 
    {
        result=Update(b,10,16,0);
        Draw(b,10,16,result);
    }

    // De-Initialization
    CloseWindow();
}

