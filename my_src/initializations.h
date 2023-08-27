#ifndef INITIALISATIONS_H
#define INITIALISATIONS_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>


/* used at program startup. Checks terminal size, if row and columns are to low
   the program asks to resize or quit
*/
void termResizeOrQuit(int& row, int& col) {

    if(row <= 24 || col <= 80) {
        const char* resizeMsg = "Please resize to maximum or press any Key to quit";
        mvaddstr(row/2, col/2 - (strlen(resizeMsg)/2), resizeMsg);
        refresh();
        bool resized {FALSE};
        while(!resized) {
            switch(int ch =getch()) {
                case ERR: napms(10);
                          break;
                case KEY_RESIZE: endwin();  // stop ncurses mode
                                 refresh(); // ...and do new initialization - see ncurses docs
                                 clear();
                                 getmaxyx(stdscr, row, col);
                                 resized = TRUE;
                                 break;
                default: exit(0);
            }
        }
    }
}


void drawStdscrStylesheet(int& row, int& col) {

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE); // gibt es da ein schöneres Gelb?!
    init_pair(3, COLOR_BLACK, COLOR_WHITE);

    bkgd(COLOR_PAIR(1));

    // create the main box
    mvhline(0, 1, ACS_HLINE, col-2);
    mvaddch(0, 0, ACS_ULCORNER);
    mvaddch(0, col-1, ACS_URCORNER);
    mvaddch(1,0, ACS_VLINE);
    mvvline(1, 0, ACS_VLINE, row-5);
    mvvline(1, col-1, ACS_VLINE, row-5);
    mvaddch(row-4, 0, ACS_LLCORNER);
    mvaddch(row-4, col-1, ACS_LRCORNER);
    mvhline(row-4, 1, ACS_HLINE, col-2);

    mvaddstr(0, col-17, "[up/dwn]");

    attron(COLOR_PAIR(2));
    mvaddstr(2, 3, " Nr.         Call        DD   MM   YYYY   Time   RST(tx)  RST(rx)         AddInfo        ");
    attroff(COLOR_PAIR(2));
    mvvline(3, 9, ACS_VLINE, row-8);
    mvvline(3, 26, ACS_VLINE, row-8);
    mvvline(3, 31, ACS_VLINE, row-8);
    mvvline(3, 36, ACS_VLINE, row-8);
    mvvline(3, 43, ACS_VLINE, row-8);
    mvvline(3, 50, ACS_VLINE, row-8);
    mvvline(3, 59, ACS_VLINE, row-8);
    mvvline(3, 68, ACS_VLINE, row-8);

}
#endif // INITIALISATIONS_H
