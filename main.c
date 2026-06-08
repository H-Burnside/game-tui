#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "map.h"
#include "player.h"
#include "window.h"
int main(){
	
	// Map
	char map[SQ_SIZE][SQ_SIZE*2];
	
	// Initiating 
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();

	init_pair(1,COLOR_GREEN, COLOR_BLACK);

	
	// Seed by the current time
	srand(time(NULL));

	// Obtaining the left-up corner
	Corner coo;	
	getCoord(&coo);

	
	
	// Player placing and functions	
	Player player;
	placePlayer(&player);
	generateMap(map);

	int running = 1;	
	while(running){
		erase();
		drawMap(map,&player,&coo);
		refresh();
		running = movePlayer(&player, map);
	}
	endwin();	
	return 0;
}
