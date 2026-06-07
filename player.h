#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"

typedef struct {
	int row;
	int col;
} Player ;

void placePlayer(Player*);
int movePlayer(Player*, char[][SQ_SIZE*2]);

#endif
