#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "constants.h"


void drawMap(char map[][SQ_SIZE*2],Player*);
char maper(int,int);

void generateMap(char map[][SQ_SIZE*2]);

#endif
