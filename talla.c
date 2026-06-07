#include <ncurses.h>

int main() {
    int row = 10;
    int col = 20;

    initscr();
    keypad(stdscr, TRUE);
    noecho();

    while(1) {

        clear();

        mvaddch(row, col, '@');

        refresh();

        int key = getch();

        switch(key){
            case 'h': col--; break;
            case 'j': row++; break;
            case 'k': row--; break;
            case 'l': col++; break;
        }
    }

    endwin();
}
