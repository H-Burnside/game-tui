#include <stdlib.h>
#include <time.h>

#include "map.h"
#include "player.h"
int main(){
	// Map
	char map[SQ_SIZE][SQ_SIZE*2];

	// Seed by the current time
	srand(time(NULL));

	// Player placing and functions	
	Player player;
	placePlayer(&player);

	generateMap(map);
	while (1){
		drawMap(map,&player);
		movePlayer(&player,map);
	}

	return 0;
}
