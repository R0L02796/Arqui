
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

	SnakePartStruct Parts = {"head",NULL,25*stepH,25*stepV};
	SnakePartStruct Part1 = {"a",NULL,25*stepH,25*stepV};
	SnakePartStruct Part2 = {"b",NULL,25*stepH,25*stepV};
	SnakePartStruct Part3 = {"c",NULL,25*stepH,25*stepV};
	



	SnakeStruct snakes = {&Parts,STOP,ADV};
   	FruitStruct fruits = {10*stepH, 37*stepV};

	Snake snake = &snakes;
	Fruit fruit = &fruits;

	addPart(snake, &Part1);
	addPart(snake, &Part2);
	addPart(snake, &Part3);

    printInitScreenSnk(fruit,snake);

	char * str = "\n          ~~~WELCOME TO LENIAS SNAKE, PRESS ENTER TO PLAY OR PRESS BACKSPACE TO QUIT. YOU MAY QUIT ANYTIME DURING GAME~~~";
	putStr(str);

	char c;
	while((c = getChar()) != '\b' && c != '\n');
	if (c == '\b') {
		return;
	}
	drawRectangle(black, xResolution/2, 20, (xResolution/2)-60, 10);

	int status = playSnk(fruit, snake);	
	if (status==1)
	{
		doBeep();
		wait(15);
		noBeep();
		printLoseScreen();
		wait(25);
		return;
	}
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
	SnakePartStruct Part4 = {"d",NULL,25*stepH,25*stepV};
	SnakePartStruct Part5 = {"e",NULL,25*stepH,25*stepV};
	SnakePartStruct Part6 = {"f",NULL,25*stepH,25*stepV};
	SnakePartStruct Part7 = {"g",NULL,25*stepH,25*stepV};
	SnakePartStruct Part8 = {"h",NULL,25*stepH,25*stepV};
	SnakePartStruct Part9 = {"i",NULL,25*stepH,25*stepV};
	SnakePartStruct Part10 = {"j",NULL,25*stepH,25*stepV};
	SnakePartStruct Part11 = {"k",NULL,25*stepH,25*stepV};
	SnakePartStruct Part12 = {"l",NULL,25*stepH,25*stepV};
	SnakePartStruct Part13 = {"m",NULL,25*stepH,25*stepV};
	SnakePartStruct Part14 = {"n",NULL,25*stepH,25*stepV};
	SnakePartStruct Part15 = {"o",NULL,25*stepH,25*stepV};
	SnakePartStruct Part16 = {"o",NULL,25*stepH,25*stepV};
	SnakePartStruct Part17 = {"o",NULL,25*stepH,25*stepV};
	SnakePartStruct Part18 = {"o",NULL,25*stepH,25*stepV};

	int px[20] = {45,32,23,12,3,43,2,37,9,25,10,40,22,3,5,46,15,26,16,43};
	int py[20] = {43,3,25,32,5,42,13,17,23,10,8,21,32,33,13,42,15,23,25,20};
	int cont=-1;

	int status=0;
	int playing = 1;
	int startTime = hrToSec(getHour(),getMinute(),getSecond());
	int startPts = hrToSec(getHour(),getMinute(),getSecond());
	int speed = 15;
	while (playing) {
		wait(speed);
		if (speed>0){
			int now = hrToSec(getHour(),getMinute(),getSecond());
			if((now - startTime) >= 15)
			{
				doBeep();
				wait(5);
				noBeep();
				speed--;
				startTime = now;
				switch (speed)
				{
				case 1:
					addPart(snake,&Part4);
					break;
				case 2:
					addPart(snake, &Part5);
					break;
				case 3:
					addPart(snake, &Part6);
					break;
				case 4:
					addPart(snake, &Part7);
					break;
				case 5:
					addPart(snake, &Part8);
					break;
				case 6:
					addPart(snake, &Part9);
					break;
				case 7:
					addPart(snake, &Part10);
					break;
				case 8:
					addPart(snake, &Part11);
					break;
				case 9:
					addPart(snake, &Part12);
					break;
				case 10:
					addPart(snake, &Part13);
					break;
				case 11:
					addPart(snake, &Part14);
					break;
				case 12:
					addPart(snake, &Part15);
					break;
				case 13:
					addPart(snake, &Part16);
					break;
				case 14:
					addPart(snake, &Part17);
					break;
				case 15:
					addPart(snake, &Part18);
					break;
				default:
					break;
				}
			}
		}
		char command = getChar();
		if (command == '\b') {
			playing = 0;
		}
		int pts = startPts - hrToSec(getHour(),getMinute(),getSecond());
		printPts(pts);
		actSnk(command,snake);
		moveSnake(snake);
		status = snakeStatus(snake, fruit);
		if (status==1)
		{
			playing=0;
			return status;
		}

		if(status==2)
			{
			status=0;
			if(cont > 20)
			{
				playing=0;
				return status;
			}
			cont++;
			moveFruit(cont,fruit,px,py);
			}
	}
	return status;
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
	printSnake(white, snake->head);
	printFruit(white, fruit);
}
void printSnake(Color color, SnakePart s) {
	SnakePart aux = s;
	while (aux!=NULL)
	{
		drawRectangle(color, aux->posX, aux->posY, 4, 4);
		aux=aux->tail;
	}
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

void addPart(Snake snk, SnakePart part){
	snk->head=addPartrec(snk->head,snk->dirX,snk->dirY,part);
}

SnakePart addPartrec(SnakePart current, int x, int y,SnakePart part){
	if (current->tail==NULL)
	{
		SnakePart P = part;
		P->posX = current->posX + x*stepH*(-1);
		P->posY = current->posY + y*stepV*(-1);
		current->tail= P;
		return current;	
	}
	current->tail=addPartrec(current->tail, x, y,part);
	return current;
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

int snakeStatus(Snake snk, Fruit fruit){
	if((snk->head)->posX >= xResolution-2 || (snk->head)->posX <= 2 || (snk->head)->posY >= yResolution-2 || (snk->head)->posY <= 2)
		return 1;
	if(colition(snk))
		return 1;

	if((snk->head)->posX == fruit->posX && (snk->head)->posY == fruit->posY)
		return 2;
	return 0;
}

void printLoseScreen()
{
	setCursor(20*stepH, 300);
	putStr("      GAME OVER     ");
}

void moveFruit(int i,Fruit fruit,int px [20], int py [20] )
{
	printFruit(black,fruit);

	fruit->posX=px[i]*stepH;
	fruit->posY=py[i]*stepV;

	printFruit(white,fruit);

}

int colition(Snake s)
{
	int x=(s->head)->posX;
	int y=(s->head)->posY;
	SnakePart aux = s->head;
	aux=aux->tail;
	while (aux!=NULL)
	{
		if(aux->posX==x && aux->posY == y)
			return 1;
		aux=aux->tail;
	}
	return 0;
}