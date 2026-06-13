#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "enemy.h"



void moveEnemy(char map[][SQ_SIZE*2],Enemy* enemy, Player* player){
	// Positive distances means that the player
	// down side and in the right
	int dr = player->row - enemy->row;
	int dc = player->col - enemy->col;
	time_t currentTime;
	time(&currentTime);
	if (currentTime - enemy->lastMove >= 1){
		if (fabs(dr) > fabs(dc)){
			if(dr > 0){
				if (map[enemy->row+1][enemy->col]==' '){
					enemy->row++;
					enemy->lastMove = currentTime;
				}
			} else {
				if (map[enemy->row-1][enemy->col]==' '){
					enemy->row--;	
					enemy->lastMove = currentTime;
				}
			}
		} else {
			if (dc > 0){
				if(map[enemy->row][enemy->col+1]==' '){
					enemy->col++;
					enemy->lastMove = currentTime;
				}
			} else {
				if (map[enemy->row][enemy->col-1]==' '){
					enemy->col--;
					enemy->lastMove = currentTime;
				}
			}
		}
	}
}


void renderEnemies(Enemy* enemies,Corner* coo, int level){
	for(int i = 0 ; i < level ; i++){
		if(enemies[i].alive){
			attron(COLOR_PAIR(3));
			mvaddch(coo->row + enemies[i].row, coo->col + enemies[i].col, 'X');
			attroff(COLOR_PAIR(3));
		}
	}
}

void updateEnemies(char map[][SQ_SIZE*2],Enemy* enemies, int* level, Player* player,Bullet* AMMO){

	if (countEnemies(enemies,*level)==0){
			(*level)+=1;
			spawnEnemies(map, enemies, *level, player);
	} else {
		for (int i = 0; i < *level ; i++){
			if(enemies[i].alive){
				moveEnemy(map, &enemies[i],player);
				shoot2player(map,&enemies[i],AMMO,player);
			}
		}
	}
}



void prepareEnemies(Enemy* enemies){
	for (int i = 0 ; i < MAX_ENEMIES ; i++ ){
		enemies[i].alive =  0; 
		time(&enemies[i].lastMove);
		time(&enemies[i].lastShoot);
	}
}

void spawnEnemies(char map[][SQ_SIZE *2],Enemy* enemies, int level, Player* player){
	int randRow, randCol;
	for (int i = 0; i < level ; i++) {
		enemies[i].alive = 1;
		do {
			randRow = rand()%SQ_SIZE;
			randCol = rand()%(SQ_SIZE*2);
			if (map[randRow][randCol]==' ' &&
				(randRow!=player->row &&
				randCol!=player->col)){

					enemies[i].row = randRow;
					enemies[i].col = randCol;
			}
		}while(map[randRow][randCol]!=' ' ||  (randRow==player->row && randCol == player->col));

	}
}

int countEnemies(Enemy* enemies, int level){
	int c = 0;
	for (int i = 0; i < MAX_ENEMIES ; i++){
		if(enemies[i].alive) c++;
		if(level == i) break;
	}
	return c;
}






void shoot2player(char map [][SQ_SIZE*2],Enemy* shooter,Bullet* ammo, Player* player){
	time_t currenttime;
	time(&currenttime);
	if(currenttime -  shooter->lastShoot < 2) return;

	// Initialazing bullet
	Bullet bulletLoaded;
	bulletLoaded.direction = ACTIVE ;
	bulletLoaded.row = shooter->row;
	bulletLoaded.col = shooter->col;

	if (shooter->row == player->row){
		// active in the xaxis and decrementing 	// 100
		if(shooter->col < player-> col) {
			// it has to be incrementing
			bulletLoaded.direction |= INCREMENT;		// 101
		}
	}else if (shooter->col == player->col){
		bulletLoaded.direction |= YAXIS;	// 110
		if (shooter->row < player->row){
			// it has to be incrementing 
			bulletLoaded.direction |= (INCREMENT);		// 111
		}
	}else {
		return;
	}
	
	// Updating the coordenates
	Direction direction = bulletLoaded.direction & ( YAXIS | INCREMENT);
	bulletLoaded.row += yoffset[direction];
	bulletLoaded.col += xoffset[direction];
	
	
	// Searching obstacules
	int step = (bulletLoaded.direction & INCREMENT) ? 1 : -1 ;
	// Case yaxis 
	if(bulletLoaded.direction & YAXIS){
		for(int i = shooter->row; i!= player->row; i+=step){
			if(map[i][shooter->col]!=' ') return;	// quit the function if it finds an obstacule
		}
	}else{
		// Case xaxis
		for (int i = shooter->col ; i!= player->col; i+=step){
			if (map[shooter->row][i]!=' ') return;
		}
	}
	
				
	// Free way to the player	
	for(int i = 0 ; i < MAX_AMMO ; i++){
		// inactive bullets
		if (!(ammo[i].direction >> 2)){
			ammo[i]=bulletLoaded;
			shooter->lastShoot = currenttime;
			break;
		}
	}
}	
