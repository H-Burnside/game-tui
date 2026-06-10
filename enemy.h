#ifndef ENEMY_H
#define ENEMY_H

#include "constants.h"
#include "window.h"
#include "player.h"
#include "bullet.h"

typedef struct {
	int row;
	int col;
	int alive;
} Enemy;

void huntPlayer(Player*,char [][SQ_SIZE*2]);
void renderEnemies(Enemy*, Corner*,int);
void updateEnemies(int*, char[][SQ_SIZE*2], Enemy*, int*, Player*,Bullet*);
void prepareEnemies(Enemy*);
void spawnEnemies(char [][SQ_SIZE*2],Enemy* , int level, Player*,int*);

#endif
