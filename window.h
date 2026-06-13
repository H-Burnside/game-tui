#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
typedef struct {
	int col;
	int row;
} Corner;

typedef enum {
	PLAYING,
	GAME_OVER
} GameState;

void getCoord(Corner*);
void gameover(int,int);

#endif
