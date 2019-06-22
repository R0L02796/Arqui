/* 
	****** 	Module for Snake 	******
*/
#ifndef SNAKEMODULE_H
#define SNAKEMODULE_H
#include "videoModule.h"
typedef struct fruit{
	int posX;
	int posY;
	int dirX;
	int dirY;
} FruitStruct;

typedef FruitStruct * Fruit;

// Prepares everything to start game
void startSnake(); 


// Displays initial screen of game
void printInitScreenSnk(Fruit fruit);

// Prints game's limits
void printFrameSnk();

// Prints fruit
void printFruit(Color color, Fruit fruit);



#endif
