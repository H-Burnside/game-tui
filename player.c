#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "map.h"

void placePlayer(Player* player){
	player->row = rand()%(SQ_SIZE-2)+1 ;
	player->col = rand()%((SQ_SIZE*2)-2)+1;
}

void movePlayer(Player* player, char map[][SQ_SIZE*2]){
	putchar('\t');
	char cursor = (char)getchar();
	switch(cursor){
		case 'j':
			// Going down
			if(
				((player->row+1)<SQ_SIZE) && 		// it can go down	
			    	(map[player->row+1][player->col]==' ')  // there's space to go
			){
				// Changing location
				map[player->row][player->col]=' ';
				player->row += 1;
			} else {
				printf("\a");
			}
			break;

		case 'k':
			// Going up 
			if (
				((player->row-1)> 0 ) && 		// it can go up	
			    	(map[player->row-1][player->col]==' ')  // there's space to go
			){
				// Changing location
				map[player->row][player->col]=' ';
				player->row -=1;
			} else {
				printf("\a");
			}

			break;

		case 'h':
			// Going to the left  
			if (
				((player->col-1)> 0 ) && 		// it can go up	
			    	(map[player->row][player->col-1]==' ')  // there's space to go
			){
				// Changing location
				map[player->row][player->col]=' ';
				player->col -=1;
			} else {
				printf("\a");
			}
			break;
		case 'l':
			// Going to the right  
			if (
				((player->col+ 1)<SQ_SIZE*2 ) && 		// it can go 	
			    	(map[player->row][player->col+1]==' ') 		// there's space to go
			){
				// Changing location
				map[player->row][player->col]=' ';
				player->col +=1;
			} else {
				printf("\a");
			}

			break;
	}
	printf("\033[2J\033[1;1H");
}
