#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include "player.h"
#include "map.h"

void placePlayer(Player* player){
	player->row = rand()%(SQ_SIZE-2)+1 ;
	player->col = rand()%((SQ_SIZE*2)-2)+1;
}

int movePlayer(Player* player, char map[][SQ_SIZE*2]){
	char cursor = getch();
	switch(cursor){
		case 'j':
			// Going down
			if(
				((player->row+1)<SQ_SIZE) && 		// it can go down	
			    	(map[player->row+1][player->col]==' ')  // there's space to go
			){
				// Changing location
				player->row += 1;
			} else {
				beep();
			}
			return 1;

		case 'k':
			// Going up 
			if (
				((player->row-1)> 0 ) && 		// it can go up	
			    	(map[player->row-1][player->col]==' ')  // there's space to go
			){
				// Changing location
				player->row -=1;
			} else {
				beep();
			}
			return 1;
		case 'h':
			// Going to the left  
			if (
				((player->col-1)> 0 ) && 		// it can go up	
			    	(map[player->row][player->col-1]==' ')  // there's space to go
			){
				// Changing location
				player->col -=1;
			} else {
				beep();
			}
			return 1;
		case 'l':
			// Going to the right  
			if (
				((player->col+ 1)<SQ_SIZE*2 ) && 		// it can go 	
			    	(map[player->row][player->col+1]==' ') 		// there's space to go
			){
				// Changing location
				player->col +=1;
			} else {
				beep();
			}
			return 1;
			break;
		case 'q':
			return 0;
	}
	return 0;
}
