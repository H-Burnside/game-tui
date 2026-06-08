#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "map.h"
#include "player.h"
#include "window.h"
#include "bullet.h"

int main(){
	
	// Map
	char map[SQ_SIZE][SQ_SIZE*2];

	// ammo
	Bullet AMMO[MAX_AMMO];
	loadAMMO(AMMO);
	
	// Initiating 
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();

	init_pair(1,COLOR_GREEN, COLOR_BLACK);
	init_pair(3,COLOR_RED, COLOR_BLACK);
	
	// Seed by the current time
	srand(time(NULL));

	// Obtaining the left-up corner
	Corner coo;	
	getCoord(&coo);

	
	
	// Player placing and functions	
	generateMap(map);
	Player player;
	placePlayer(&player,map);

	int running = 1;	
	while(running){
		erase();
		drawMap(map,&player,&coo);
		renderBullets(map,AMMO,&coo);
		refresh();
		running = movePlayer(&player, map,AMMO);
		napms(40);
	}
	endwin();	
	return 0;
}
