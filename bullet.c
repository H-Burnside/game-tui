#include <ncurses.h>
#include "bullet.h"

/**
 * Create a pool of bullets with no direction
 * args: Bullet AMMO[MAX_AMMO]
 */
void loadAMMO(Bullet* ammo){
	for (int i = 0 ; i < MAX_AMMO ; i++ ){
		ammo[i].direction = 0 ;
	}
}


/**
 * Show the bullets on the map
 */
void renderBullets(char map[][SQ_SIZE*2], Bullet* ammo, Corner* coo){
	for (int i = 0 ; i < MAX_AMMO ; i ++){
		// Active bullets ammo[i]: Bullet
		if (ammo[i].direction >> 2 ){
			// only show bullets in free spaces
			if ((map[ammo[i].row][ammo[i].col])==' '){
				attron(COLOR_PAIR(3));
				mvaddch(
					coo->row + ammo[i].row,
					coo->col + ammo[i].col,'.'
				);
				attroff(COLOR_PAIR(3));
			
			}

		}
	}
}

/**
 * Logic behind the movement of the bullets
 */
void updateBullets(char map[][SQ_SIZE * 2],Bullet* ammo, Corner* coo, Enemy* enemies,Player* player, int level, int* kills, GameState* state){
	for (int i = 0 ; i < MAX_AMMO ; i ++){
		// Active bullets ammo[i]: Bullet
		if (ammo[i].direction >> 2 ){

			if(map[ammo[i].row][ammo[i].col]==' ' && searchEnemies(enemies,&ammo[i].row, &ammo[i].col, level, kills)==0 && !foundPlayer(player, &ammo[i].row, &ammo[i].col,level, kills,state)){
				// moving the bullet
				Direction direction = (ammo[i].direction & (YAXIS | INCREMENT));
				switch(direction){
					case TO_UP: ammo[i].row-=1; break; // up
					case TO_RIGHT: ammo[i].col+=1; break; // right
					case TO_DOWN: ammo[i].row+=1; break; // down
					case TO_LEFT: ammo[i].col-=1; break; // left
				}				
			} else {
				// When the bullet finds something
				ammo[i].direction=0;
			}
		}

	}
}

/**
 * It finds enemies in the travel of the bullet
 * return 1 in the positive case
 */
int searchEnemies(Enemy* enemies, int* bulletRow, int* bulletCol, int level, int* kills){
	for(int i = 0; i < level ; i++){
		if(enemies[i].alive && enemies[i].row == *bulletRow &&
		   enemies[i].col == *bulletCol){
			enemies[i].alive = 0;
			(*kills)+=1;
			return 1;
		}
	}	
	return 0;
}

int foundPlayer(Player* player, int* bulletRow, int* bulletCol, int level, int* kills, GameState* state){
	if (player->row == *bulletRow && player->col == *bulletCol){
		gameover(level, *kills);
		(*state)= GAME_OVER;
		return 1;
	}
	return 0;

}

