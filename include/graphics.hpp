#ifndef GRAPHICSGAME 
#define GRAPHICSGAME


#include "board.hpp"


void Draw(Board& board ,int Board_width,int Board_height,int CreateNew,int NumberNext,int width,int height,int paused,int end,Texture2D* textures) ;
int DrawStartWindow(int width,int height,Texture2D texture);

#endif