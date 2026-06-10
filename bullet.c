#include <ncurses.h>
#include "bullet.h"

/**
 * Creates the linked list for the bullets
 * args: Bullet AMMO[MAX_AMMO]
 * return: HEAD
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

void updateBullets(char map[][SQ_SIZE * 2],Bullet* ammo, Corner* coo){
	for (int i = 0 ; i < MAX_AMMO ; i ++){
		// Active bullets ammo[i]: Bullet
		if (ammo[i].direction >> 2 ){
			if(map[ammo[i].row][ammo[i].col]==' '){
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

