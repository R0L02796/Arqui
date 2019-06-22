#include "snakeModule.h"
#include "videoModule.h"
#include "stdlib.h"
#include "timeModule.h"
#include "soundModule.h"


static int xResolution;
static int yResolution;

static Color white = {255, 255, 255};
static Color black = {0, 0, 0};


void startSnake(){
    getSize(&xResolution, &yResolution);	

	SnakeStruct snakes = {xResolution/2,yResolution/2,UP};
   	FruitStruct fruits = {xResolution/15, yResolution/32};

	Snake snake = &snakes;
	Fruit fruit = &fruits;

    printInitScreenSnk(fruit,snake);

	char * str = "\n          ~~~WELCOME TO LENIAS SNAKE, PRESS ENTER TO PLAY OR PRESS BACKSPACE TO QUIT. YOU MAY QUIT ANYTIME DURING GAME~~~";
	putStr(str);

	char c;
	while((c = getChar()) != '\b' && c != '\n');
	if (c == '\b') {
		return;
	}
	drawRectangle(black, xResolution/2, 20, (xResolution/2)-60, 10);

	int exitStatus = playSnk(fruit);	

}

int playSnk(Fruit fruit) {
	int playing = 1;
	int exitStatus = 0;
	while (playing) {
		wait(1);
		char command = getChar();
		if (command == '\b') {
			playing = 0;
		}
	}
	return exitStatus;
}
void printInitScreenSnk(Fruit fruit,Snake snake) {
	clearScreen();
	printFrameSnk();
	printSnake(white, snake);
	printFruit(white, fruit);
}
void printSnake(Color color, Snake s) {
	int xPos = s->posX;
	int yPos = s->posY;
	drawRectangle(color, xPos, yPos, 3, 50);
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