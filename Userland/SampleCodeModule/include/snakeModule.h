/* 
	****** 	Module for Snake 	******
*/
#ifndef SNAKEMODULE_H
#define SNAKEMODULE_H
#include "videoModule.h"


#define SUP 119
#define SDOWN 115
#define SRIGHT 100
#define SLEFT 97

#define ADV 1
#define RET -1
#define STOP 0

typedef struct fruit{
	int posX;
	int posY;
} FruitStruct;

typedef struct snakePart{
	int isHead;
	struct snakePart * tail;
	int posX;
	int posY;
}SnakePartStruct;

typedef struct snake{
	SnakePartStruct * head;
	int dirX;
	int dirY;
}SnakeStruct;

typedef SnakePartStruct * SnakePart;
typedef SnakeStruct * Snake;
typedef FruitStruct * Fruit;

// Prepares everything to start game
void startSnake(); 

// Prints snake
void printSnake(Color color, SnakePart snake);

// Displays initial screen of game
void printInitScreenSnk(Fruit fruit, Snake snake);

//moves all parts that aren't head
void moveParts(SnakePart curr,int x, int y);

// Prints game's limits
void printFrameSnk();

// Prints fruit
void printFruit(Color color, Fruit fruit);

//Starts game
int playSnk(Fruit fruit, Snake snake) ;

//moves snake on act
void moveSnakeOnAct(Snake s, int newDirX, int newDirY);

//moves snake
void moveSnake(Snake s);

// Recives an action from the player to move and executes it
void actSnk(char command, Snake snake);

//adds part
void addPart(SnakePart head, SnakePart part);

void printpts(int point);






#endif
