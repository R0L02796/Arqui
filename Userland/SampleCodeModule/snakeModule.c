#include "snakeModule.h"
#include "videoModule.h"
#include "stdlib.h"
#include "timeModule.h"
#include "soundModule.h"
#include "stddef.h"


static int xResolution;
static int yResolution;

static Color white = {255, 255, 255};
static Color black = {0, 0, 0};


void startSnake(){
    getSize(&xResolution, &yResolution);	

	SnakePartStruct Parts = {1,NULL,xResolution/2,yResolution/2};
	SnakePartStruct tail = {0,NULL,Parts.posX-20,Parts.posY};

	SnakeStruct snakes = {&Parts,SUP};
   	FruitStruct fruits = {xResolution/15, yResolution/1.3};

	Snake snake = &snakes;
	Fruit fruit = &fruits;

	addPart(snake->head,&tail);

    printInitScreenSnk(fruit,snake);

	char * str = "\n          ~~~WELCOME TO LENIAS SNAKE, PRESS ENTER TO PLAY OR PRESS BACKSPACE TO QUIT. YOU MAY QUIT ANYTIME DURING GAME~~~";
	putStr(str);

	char c;
	while((c = getChar()) != '\b' && c != '\n');
	if (c == '\b') {
		return;
	}
	drawRectangle(black, xResolution/2, 20, (xResolution/2)-60, 10);

	int exitStatus = playSnk(fruit, snake);	

}

int playSnk(Fruit fruit, Snake snake) {
	int playing = 1;
	int exitStatus = 0;
	while (playing) {
		wait(1);
		char command = getChar();
		if (command == '\b') {
			playing = 0;
		}
		actSnk(command,snake);

	}
	return exitStatus;
}

void actSnk(char command,Snake snake) {
	switch (snake->dir)
	{
		case SUP: 
			switch(command)
			{
				case SRIGHT:
					moveSnake(snake, SRIGHT);
					break;
				case SLEFT:
					moveSnake(snake, SLEFT);
					break;
				default:
					return;
			}
		case SDOWN: 
			switch(command)
			{
				case SRIGHT:
					moveSnake(snake, SRIGHT);
					break;
				case SLEFT:
					moveSnake(snake, SLEFT);
					break;
				default:
					return;
			}
		case SRIGHT: 
			switch(command)
			{
				case SUP:
					moveSnake(snake, SUP);
					break;
				case SDOWN:
					moveSnake(snake, SDOWN);
					break;
				default:
					return;
			}
		case SLEFT: 
			switch(command)
			{
				case SUP:
					moveSnake(snake, SUP);
					break;
				case SDOWN:
					moveSnake(snake, SDOWN);
					break;
				default:
					return;
			}
	
	}
}

void moveSnake(Snake s, int newDir) {	

}

void printInitScreenSnk(Fruit fruit,Snake snake) {
	clearScreen();
	printFrameSnk();
	printSnake(white, snake->head);
	printFruit(white, fruit);
}
void printSnake(Color color, SnakePart s) {
	int xPos=s->posX;
	int yPos=s->posY;
	
	drawRectangle(color, xPos, yPos, 4,4);

	if(s->tail==NULL)
		drawRectangle(color, 20, 100, 10,10);

	 while (s->tail != NULL)
	{
		printSnake(color,s->tail);	
	}
	return;
}

void printFruit(Color color, Fruit b) {
	drawBall(color, 10, b->posX, b->posY);
}

void printFrameSnk() {
	drawRectangle(white, xResolution/2, 2, (xResolution/2 )-2, 0);
	drawRectangle(white, xResolution/2, yResolution-2, (xResolution/2 )-2, 0);
	drawRectangle(white, 2, yResolution/2, 1, (yResolution/2)-2);
	drawRectangle(white, xResolution-2, yResolution/2, 1, (yResolution/2)-2);
}
void addPart(SnakePart head, SnakePart part){
	SnakePart current=head;
	while (head->tail!=NULL)
	{
		current=current->tail;
	}
	current->tail = part;
}

