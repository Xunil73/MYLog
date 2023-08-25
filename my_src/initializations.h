#ifndef INITIALISATIONS_H
#define INITIALISATIONS_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
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
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    bkgd(COLOR_PAIR(1));
    box(stdscr, 0, 0);

    auto upperHLine = row / 4;
    auto lowerHLine = (row / 4  * 3) + 2;
    mvhline(upperHLine, 1, ACS_HLINE, col-2);
    mvaddch(upperHLine ,0, ACS_LTEE);
    mvaddch(upperHLine ,col-1, ACS_RTEE);

    mvhline(lowerHLine, 1, ACS_HLINE, col-2);
    mvaddch(lowerHLine ,0, ACS_LTEE);
    mvaddch(lowerHLine ,col-1, ACS_RTEE);

    auto labelLine = row - 1;
    constexpr size_t NUMOF_LABELS = 5;
    std::vector<int> labelPosMiddle;  // wir berechnen die Mittenposition der Menülabel über der zweiten Trennlinie
    for(size_t i=1; i<NUMOF_LABELS+1; ++i) {
        auto labelPositions = (col / (NUMOF_LABELS+1)) * i;
        labelPosMiddle.push_back(labelPositions);
    }

    const char* labels[NUMOF_LABELS] {"<F1>Presets", "<F3>Search", "<F5>Edit", "<F7>Info", "<F9>Quit"};
    for(size_t i=0; i<NUMOF_LABELS; ++i){
        auto labelOffset = strlen(labels[i]) / 2;
        attron(COLOR_PAIR(2));
        mvaddstr(labelLine, labelPosMiddle[i] - labelOffset, labels[i]);
        attroff(COLOR_PAIR(2));
    }
}
#endif // INITIALISATIONS_H
