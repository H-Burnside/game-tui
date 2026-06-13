#ifndef BULLET_H
#define BULLET_H

#include "constants.h"
#include "window.h"



void loadAMMO(Bullet*);

void renderBullets(char [][SQ_SIZE*2], Bullet*,Corner* );
void updateBullets(char [][SQ_SIZE*2],Bullet*, Corner*, Enemy* enemies,Player*,int level, int* kills, GameState* state);
int searchEnemies(Enemy* enemies, int* bulletRow, int* BulletCol, int level, int* kills);
int foundPlayer(Player*,int* bulletRow, int* bulletCol,int level, int* kills, GameState* state);

#endif 
