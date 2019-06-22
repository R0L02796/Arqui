/* 
	****** 	Module for Snake 	******
*/
#ifndef SNAKEMODULE_H
#define SNAKEMODULE_H
#include "videoModule.h"

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97

typedef struct fruit{
	int posX;
	int posY;
} FruitStruct;

typedef struct snake{
	int posX;
	int posY;
	int dir;
}SnakeStruct;

typedef SnakeStruct * Snake;
typedef FruitStruct * Fruit;

// Prepares everything to start game
void startSnake(); 

// Prints snake
void printSnake(Color color, Snake snake);

// Displays initial screen of game
void printInitScreenSnk(Fruit fruit,Snake snake);

// Prints game's limits
void printFrameSnk();

// Prints fruit
void printFruit(Color color, Fruit fruit);

//Starts game
int playSnk(Fruit fruit) ;

#endif
