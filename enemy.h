#ifndef ENEMY_H
#define ENEMY_H

#include "constants.h"
#include "window.h"
#include "player.h"
#include "bullet.h"
#include "unistd.h"


void renderEnemies(Enemy*, Corner*,int);
void updateEnemies(char[][SQ_SIZE*2], Enemy*, int*, Player*,Bullet*);
void prepareEnemies(Enemy*);
void spawnEnemies(char [][SQ_SIZE*2],Enemy* , int level, Player*);
void moveEnemy(char [][SQ_SIZE*2],Enemy*,Player*);
int countEnemies(Enemy*,int level);
void shoot2player(char [][SQ_SIZE*2],Enemy*,Bullet* ammo, Player* player);
#endif
