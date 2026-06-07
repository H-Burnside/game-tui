#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#include "map.h"
#include "player.h"
#include "window.h"

void drawMap(char map[][SQ_SIZE*2], Player* player,Corner* coo){
	for (int i = 0 ; i < SQ_SIZE ; i++ ){
		for(int j=0; j < SQ_SIZE*2 ; j++){
			if (i == player->row && j == player->col){
				attron(COLOR_PAIR(1));
				mvaddch(coo->row + i , coo->col +j, 'P');	
				attroff(COLOR_PAIR(1));
			}else {
		        mvaddch(coo->row + i, coo->col + j, map[i][j]);
			}
		}
	}

}



void generateMap(char map[][SQ_SIZE*2]){
	for(int i = 0 ; i < SQ_SIZE  ; i++){
		for (int j = 0; j < SQ_SIZE*2  ; j++){
			map[i][j]= maper(i,j);
		}
	}
}


char maper(int x, int y){
	// Borders
	if (x == 0 || x == SQ_SIZE -1 ){
		return '-';
	} else if ( y == 0 || y == ((SQ_SIZE*2)-1)){
	       return '|';
	} else if ((rand()%SQ_SIZE)<(SQ_SIZE / PROB)) {
 		return '+';
	} else {
		return ' ';
	}
}


