#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"
#include "bullet.h"

typedef struct {
	int row;
	int col;
	unsigned int direction : 2;	// MSB? y:x ; LSB? increment: decrement
} Player ;

void placePlayer(Player*,char [][SQ_SIZE * 2]);
int movePlayer(Player*, char[][SQ_SIZE*2],Bullet*);
void shoot(Bullet* , Player*);

#endif
