#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "player.h"

void drawMap(char map[][SQ_SIZE*2], Player* player){
	for (int i = 0 ; i < SQ_SIZE ; i++ ){
		for(int j=0; j < SQ_SIZE*2 ; j++){
			if (i == player->row && j == player->col){
				map[i][j]='P';	
			}
		        putchar(map[i][j]);
		}

		putchar('\n');	
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


