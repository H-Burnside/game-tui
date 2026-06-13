#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"
#include "bullet.h"


void placePlayer(Player*,char [][SQ_SIZE * 2]);
int movePlayer(Player*, char[][SQ_SIZE*2],Bullet*);
void shoot(Bullet* , Player*);

#endif
