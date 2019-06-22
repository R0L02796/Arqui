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

   	BallStruct ballS = {xResolution/2, yResolution/2, 15, 17};

	Ball ball = &ballS;

    printInitScreen(ball);


}

void printInitScreen(Ball ball) {
	clearScreen();
	printFrame();
	printBall(white, ball);
}

void printBall(Color color, Ball b) {
	drawBall(color, 10, b->posX, b->posY);
}

void printFrame() {
	drawRectangle(white, xResolution/2, 2, (xResolution/2 )-2, 0);
	drawRectangle(white, xResolution/2, yResolution-2, (xResolution/2 )-2, 0);
	drawRectangle(white, 2, yResolution/2, 1, (yResolution/2)-2);
	drawRectangle(white, xResolution-2, yResolution/2, 1, (yResolution/2)-2);
}