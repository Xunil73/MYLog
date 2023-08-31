#ifndef INITIALISATIONS_H
#define INITIALISATIONS_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>


/* used at program startup. Checks terminal size, if row and columns are to low
   the program asks to resize or quit. Sets the resized row and col values as
   side effect.
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


void drawStdscrStylesheet(const int& row, const int& col) {

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);

    bkgd(COLOR_PAIR(1));

    // create the main box
    mvhline(0, 1, ACS_HLINE, col-2);
    mvaddch(0, 0, ACS_ULCORNER);
    mvaddch(0, col-1, ACS_URCORNER);
    mvaddch(1,0, ACS_VLINE);
    mvvline(1, 0, ACS_VLINE, row-5);
    mvvline(1, col-1, ACS_VLINE, row-5);
    mvaddch(row-5, 0, ACS_LLCORNER);
    mvaddch(row-5, col-1, ACS_LRCORNER);
    mvhline(row-5, 1, ACS_HLINE, col-2);

    mvaddstr(0, col-17, "[up/dwn]");

    // we draw the qso spreadsheet with headerline and the spacing lines between the columns
    attron(COLOR_PAIR(2));
    mvaddstr(2, 3, " Nr.         Call       Mode   Band   DD   MM   YYYY   Time  RSTt RSTr         AddInfo         ");
    attroff(COLOR_PAIR(2));
    const size_t COL_LINE_LEN {row-11};
    constexpr size_t COL_LINE_H_POS[] {9,25,32,39,44,49,56,63,68,73};
    constexpr size_t CLPOS_ARRSIZE = sizeof(COL_LINE_H_POS) / sizeof(COL_LINE_H_POS[0]);
    for(size_t i=0; i<CLPOS_ARRSIZE; ++i) {
        mvvline(3, COL_LINE_H_POS[i], ACS_VLINE, COL_LINE_LEN);
    }


    // we draw the menu labels on the bottom line of the screen
    attron(COLOR_PAIR(3)); // first we paint the area below the main box "back in black"
    for(size_t i=4; i>0; --i) {
        for(size_t j=0; j<col; ++j) {
            mvaddch(row-i, j, ' ');
        }
    }
    attroff(COLOR_PAIR(3));
    // we create the F<n> menu labels
    const char* F_LABELS[] { "Help", "Pres~" ,"S~rch", "Edit", "Info", "Qsl", "DBmod", "Quit"};
    constexpr size_t F_LABELS_ARRLEN = sizeof(F_LABELS) / sizeof(F_LABELS[0]);
    size_t maxLen {0};
    for(size_t i=0; i< F_LABELS_ARRLEN; ++i) { // we store the longest strlen. All others become the same length
        size_t len = strlen(F_LABELS[i]);
        if(len > maxLen) maxLen = len;
    }

    move(row-1, 0);
    for(size_t i=0; i<F_LABELS_ARRLEN; ++i) {
        attron(COLOR_PAIR(3));
        printw("F<%i>", i+1);  // we write the <Fn>
        attroff(COLOR_PAIR(3));

        size_t addSpace = maxLen - strlen(F_LABELS[i]);
        attron(COLOR_PAIR(4));
        printw("%s", F_LABELS[i]);  // we write the F_LABELS
        for(size_t j=0; j<addSpace; ++j) {
            addch(' ');
        }
        attroff(COLOR_PAIR(4));

        attron(COLOR_PAIR(3));
        addstr("  ");
        attroff(COLOR_PAIR(3));
    }
}
#endif // INITIALISATIONS_H
