#include <ncurses.h>
#include "window.h"
#include "constants.h"

void getCoord(Corner* coo){
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	
	coo->row = rows/2 - (SQ_SIZE/2);
	coo->col = cols/2 - SQ_SIZE;
}
