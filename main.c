#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "map.h"
#include "player.h"
#include "window.h"
#include "bullet.h"
#include "enemy.h"

int main(){
	
	// Map
	char map[SQ_SIZE][SQ_SIZE*2];

	// ammo
	Bullet AMMO[MAX_AMMO];
	loadAMMO(AMMO);
	Enemy Enemies[MAX_ENEMIES];

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
	int level = 0; 
	int kills = 0;

	// Seed by the current time
	srand(time(NULL));

	// Obtaining the left-up corner
	Corner coo;	
	getCoord(&coo);

	
	
	// Player placing and functions	
	generateMap(map);
	Player player;
	placePlayer(&player,map);
	prepareEnemies(Enemies);

	// Gamestate 
	GameState state = PLAYING;

	int running = 1;	
	while(running){
		erase();
		if (state == PLAYING){
			mvprintw(0,0,"Level: %d", level);
			drawMap(map,&player,&coo);
			renderBullets(map,AMMO,&coo);
			updateBullets(map,AMMO,&coo,Enemies,&player,level,&kills,&state);
			
			renderEnemies(Enemies,&coo,level);				
			updateEnemies(map,Enemies,&level,&player, AMMO);
			running = movePlayer(&player, map,AMMO);
		} else {
			gameover(level, kills);
			int ch = getch();
			if(ch=='q') running = 0;

		}
		
		refresh();
		napms(40);
	}
	endwin();	
	return 0;
}
