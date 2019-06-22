/* 
	****** 	Module for Snake 	******
*/
#ifndef SNAKEMODULE_H
#define SNAKEMODULE_H
#include "videoModule.h"
typedef struct ball{
	int posX;
	int posY;
	int dirX;
	int dirY;
} BallStruct;

typedef BallStruct * Ball;

// Prepares everything to start game
void startSnake(); 


// Displays initial screen of game
void printInitScreen(Ball ball);

// Prints game's limits
void printFrame();

// Prints ball
void printBall(Color color, Ball ball);



#endif
