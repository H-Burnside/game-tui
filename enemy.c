#include <ncurses.h>
#include <stdlib.h>
#include "enemy.h"



void renderEnemies(Enemy* enemies,Corner* coo, int level){
	for(int i = 0 ; i < MAX_ENEMIES ; i++){
		if(enemies[i].alive){
			attron(COLOR_PAIR(3));
			mvaddch(coo->row + enemies[i].row, coo->col + enemies[i].col, 'X');
			attroff(COLOR_PAIR(3));
		}
		if (i == level -1) break;
	}
}

void updateEnemies(int* enemiesAlive,char map[][SQ_SIZE*2],Enemy* enemies, int* level, Player* player,Bullet* AMMO){

	if (!(*enemiesAlive)){
			spawnEnemies(map, enemies, *level, player,enemiesAlive);
			(*level)+=1;
	} else {
		for (int i = 0; i < *level ; i++){
			if(enemies[i].alive){
				for(int j = 0; j < MAX_AMMO ; j++){
					if(AMMO[j].direction >> 2){
						if(AMMO[j].row == enemies[i].row &&
						   AMMO[j].col == enemies[i].col){
							enemies[i].alive = 0;
							(*enemiesAlive)-=1;
							AMMO[j].direction = 0;
						}
					}
				}
			}
		}
	}
}



void prepareEnemies(Enemy* enemies){
	for (int i = 0 ; i < MAX_ENEMIES ; i++ ){
		enemies[i].alive =  0; 
	}
}

void spawnEnemies(char map[][SQ_SIZE *2],Enemy* enemies, int level, Player* player,int* enemiesAlive){
	int randRow, randCol;
	for (int i = 0; i < level ; i++) {
		do {
			randRow = rand()%SQ_SIZE;
			randCol = rand()%(SQ_SIZE*2);
			if (map[randRow][randCol]==' ' &&
				randRow!=player->row &&
				randCol!=player->col){

					enemies[i].row = randRow;
					enemies[i].col = randCol;
					enemies[i].alive = 1;
					(*enemiesAlive)+=1;
			}
		}while(map[randRow][randCol]!=' ' ||  (randRow==player->row && randCol == player->col));

	}
}
