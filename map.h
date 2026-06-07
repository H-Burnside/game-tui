#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "constants.h"
#include "window.h"

void drawMap(char map[][SQ_SIZE*2],Player*,Corner*);
char maper(int,int);

void generateMap(char map[][SQ_SIZE*2]);

#endif
