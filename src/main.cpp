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
    while (!WindowShouldClose()) 
    {
        Update(b,10,16);
        Draw(b,10,16);
    }

    // De-Initialization
    CloseWindow();
}

