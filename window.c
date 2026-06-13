#include <ncurses.h>
#include "window.h"
#include "constants.h"

void getCoord(Corner* coo){
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	
	coo->row = rows/2 - (SQ_SIZE/2);
	coo->col = cols/2 - SQ_SIZE;
}

void gameover(int level, int kills){

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    mvprintw(rows/2 - 2, cols/2 - 5, "GAME OVER");
    mvprintw(rows/2, cols/2 - 8, "Level: %d", level);
    mvprintw(rows/2 + 1, cols/2 - 8, "Kills: %d", kills);
    mvprintw(rows/2 + 3, cols/2 - 15,
             "Press q to quit");
}
