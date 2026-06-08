#ifndef BULLET_H
#define BULLET_H

#include "constants.h"
#include "window.h"

typedef enum {
	TO_LEFT,
	TO_RIGHT,
	TO_UP,
	TO_DOWN
} Direction;

typedef struct {
	int row;
	int col;
	unsigned int direction: 3; // MSB: active, i<<1: y-axis, LSB: increment;
} Bullet ;

void loadAMMO(Bullet*);

void renderBullets(char [][SQ_SIZE*2], Bullet*,Corner* );
#endif 
