#include "game.h"

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    srand(time(NULL));
    iniziaGioco();
    endwin();
    return 0;
}