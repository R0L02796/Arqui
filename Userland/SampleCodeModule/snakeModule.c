
#include "snakeModule.h"
#include "videoModule.h"
#include "stdlib.h"
#include "timeModule.h"
#include "soundModule.h"
#include "stddef.h"


static int xResolution;
static int yResolution;

static int stepV; 
static int stepH; 

static Color white = {255, 255, 255};
static Color black = {0, 0, 0};


void startSnake(){
    getSize(&xResolution, &yResolution);	

	stepV = yResolution/50;
	stepH = xResolution/50;

	SnakePartStruct Parts = {NULL,25*stepH,25*stepV};
	SnakeStruct snakes = {&Parts,STOP,RET};
   	FruitStruct fruits = {10*stepH, 37*stepV};

	Snake snake = &snakes;
	Fruit fruit = &fruits;

	addPart(snake);
	addPart(snake);

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

//misterio porque no anda
void printPts(int point) {
	setCursor(50, 30);
	char points[1];
	decToStr(point, points);
	putStr(points);
	return;
}

int hrToSec(int h, int m, int s){
	return h*3600+m*60+s;
}

int playSnk(Fruit fruit, Snake snake) {
	int playing = 1;
	int exitStatus = 0;
	int startTime = hrToSec(getHour(),getMinute(),getSecond());
	int speed = 15;
	while (playing) {
		wait(speed);
		int now = hrToSec(getHour(),getMinute(),getSecond());
		if((now - startTime) >= 15)
		{
			if (speed>0)
				speed--;
			startTime = now;
			addPart(snake);
		}

		char command = getChar();
		if (command == '\b') {
			playing = 0;
		}
		actSnk(command,snake);
		moveSnake(snake);
	}
	return exitStatus;
}

void actSnk(char command,Snake snake) {
	switch (snake->dirY)
	{
		case ADV: 
			switch(command)
			{
				case SRIGHT:
					moveSnakeOnAct(snake, ADV, STOP);
					break;
				case SLEFT:
					moveSnakeOnAct(snake, RET, STOP);
					break;
				default:
					return;
			}
		case RET: 
			switch(command)
			{
				case SRIGHT:
					moveSnakeOnAct(snake, ADV, STOP);
					break;
				case SLEFT:
					moveSnakeOnAct(snake, RET, STOP);
					break;
				default:
					return;
			}
		case STOP:
			switch (snake->dirX)
			{
				case ADV: 
					switch(command)
					{
						case SUP:
							moveSnakeOnAct(snake, STOP, RET);
							break;
						case SDOWN:
							moveSnakeOnAct(snake, STOP, ADV);
							break;
						default:
							return;
					}
				case RET: 
					switch(command)
					{
						case SUP:
							moveSnakeOnAct(snake, STOP, RET);
							break;
						case SDOWN:
							moveSnakeOnAct(snake, STOP, ADV);
							break;
						default:
							return;
					}
				default:
					return;
			}
	}
}

void moveParts(SnakePart curr,int x, int y){
	if(curr==NULL)
		return;
	moveParts(curr->tail,curr->posX,curr->posY);
	curr->posX=x;
	curr->posY=y;
}

void printInitScreenSnk(Fruit fruit,Snake snake) {
	clearScreen();
	printFrameSnk();
			putStr("on print");

	printSnake(white, snake->head);
	printFruit(white, fruit);
}
void printSnake(Color color, SnakePart s) {
	if (s==NULL)
		return;
			putStr("on printsnk");
	drawRectangle(color,s->posX, s->posY, 4,4);
	printSnake(color,s->tail);
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


void addPart(Snake s){
	SnakePart current=s->head;
	while (current->tail!=NULL)
	{
		current=current->tail;
	}
	SnakePartStruct P = {NULL,current->posX + s->dirX*stepH,current->posY + s->dirY*stepV};
	current->tail = &P;
}

void moveSnakeOnAct(Snake s, int newDirX, int newDirY) {	
	s->dirX=newDirX;
	s->dirY=newDirY;
}

void moveSnake(Snake s){
	SnakePart h = s->head;	
	printSnake(black,h);
	int x=h->posX;
	int y=h->posY;
	h->posX=h->posX + s->dirX*stepH;
	h->posY=h->posY + s->dirY*stepV;
	moveParts(h->tail,x,y);
	printSnake(white,h);
}
