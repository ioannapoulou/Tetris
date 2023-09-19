#include "raylib.h"
#include <iostream>
#include <time.h>

#include "graphics.hpp"
#include "update.hpp"
#include "board.hpp"

using namespace std;

int paused=-1;


Texture2D* LoadImages(Texture2D * textures)
{
    Image imagerec,imageT,imageL,imageSandZ,imagestr,imageshapes ;
    imagerec = LoadImage("images/rectangle.png");
    ImageResize(&imagerec, 100, 100);
    Texture2D texturerec = LoadTextureFromImage(imagerec);

    imageT= LoadImage("images/T.png");
    ImageResize(&imageT, 150, 100);
    Texture2D textureT = LoadTextureFromImage(imageT);

    imageL= LoadImage("images/L.png");
    ImageResize(&imageL, 100, 150);
    Texture2D textureL = LoadTextureFromImage(imageL);

    imageSandZ= LoadImage("images/SandZ.png");
    ImageResize(&imageSandZ, 100, 150);
    Texture2D textureSandZ = LoadTextureFromImage(imageSandZ);

    imagestr= LoadImage("images/straight.png");
    ImageResize(&imagestr, 200, 50);
    Texture2D texturestr = LoadTextureFromImage(imagestr);

    imageshapes= LoadImage("images/shapes.png");
    ImageResize(&imageshapes, 450, 450);
    Texture2D textureshapes = LoadTextureFromImage(imageshapes);

    
    textures[0]=texturerec;
    textures[1]=textureT;
    textures[2]=textureL;
    textures[3]=textureSandZ;
    textures[4]=texturestr;
    textures[5]=textureshapes;

    return textures;
}


void UnloadTextures(Texture2D* textures)
{
    for (int i=0;i<=5;i++)
    {
        UnloadTexture(textures[i]);
    }

    delete textures;
}


int main(void)
{
    srand(time(NULL));
    InitWindow(800,1000, "Tetris");
    Texture2D * textures = new Texture2D[6];
    LoadImages(textures);
    int closed=DrawStartWindow(800,1000,textures[5]);
    if (closed==1)
    {
        Board b(10,16);
        SetTargetFPS(60);
        int* result=Update(b,10,16,1);

        Draw(b,10,16,result[0],result[1],800,1000,-1,result[2],textures);
        while (!WindowShouldClose()) 
        {
            if(GetKeyPressed()==KEY_P)
            {
                paused=paused*(-1);
            }
            if(paused==-1 and result[2]!=1)
            {
                result=Update(b,10,16,0);
            }
            Draw(b,10,16,result[0],result[1],800,1000,paused,result[2],textures);

        }


        // De-Initialization
        UnloadTextures(textures);
        CloseWindow();
    }
}

