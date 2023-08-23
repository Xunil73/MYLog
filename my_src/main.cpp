//#include <iostream>
#include <ncurses.h>
#include <panel.h>
#include <menu.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "hamfunc.h"
#include "printfuncs.h"
#include <vector>

using namespace std;

/* wir verwenden Panels für
   1. Filtern / Suchen, 2. editieren, 3. Anzeige zusätzlicher Infos zum QSO,
   4. Output in Datei (ADIF, etc.) */
enum class Panels {SEARCH, EDIT, SHOW_INFO, EXPORT};

void quit() {
    endwin();
}


int main() {

    int row, col;  // Zeilen, Spalten

    initscr();
    atexit(quit);

    clear();
    noecho();
    cbreak();
    //nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();

    getmaxyx(stdscr, row, col);

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

    auto labelLine =lowerHLine - 1;
    constexpr size_t NUMOF_LABELS = 5;
    vector<int> labelPosMiddle;  // wir berechnen die Mittenposition der Menülabel über der zweiten Trennlinie
    for(size_t i=1; i<NUMOF_LABELS+1; ++i) {
        auto labelPositions = (col / (NUMOF_LABELS+1)) * i;
        labelPosMiddle.push_back(labelPositions);
    }

    const char* labels[NUMOF_LABELS] {"<F1>newQSO", "<F3>Search", "<F5>Edit", "<F7>showInfo", "<F9>Quit"};
    for(size_t i=0; i<NUMOF_LABELS; ++i){
        auto labelOffset = strlen(labels[i]) / 2;
        attron(COLOR_PAIR(2));
        mvaddstr(labelLine, labelPosMiddle[i] - labelOffset, labels[i]);
        attroff(COLOR_PAIR(2));
    }
    refresh();
    getch();

    return 0;

/*
    {  //Code zum Testen einzelner Funktionen - wenn Ncurses läuft iostream und diesen Code löschen!!!
        //string call = "E1K";

        //string call ="R1AN/DJ5MY/AM";

        //string call ="XV9/DJ5MY";

        //string call = "XV9MAE/P";

        //string call = "XV9MAE/T"; // unmögliche Kombi, keine Ausgabe

        //string call = "DP0GVN";

        Array2d<std::string> full = getFullDxccInfos(call);

        Array2d<std::string> dxccRef = getDxccRefIDs(call);
        printArray(full);
        printArray(dxccRef);

        printArray(splitCall(call));



        Array2d<std::string> dxcc = getDxccNameInfos(call);
        Array2d<std::string> cont = getContinentInfos(call);
        Array2d<std::string> cq = getCqZoneInfos(call);
        Array2d<std::string> itu = getItuZoneInfos(call);
        cout << "das Call " << call << " gehört zu" << endl;
        cout << "DXCC: "; printArrayNoHeader(dxcc);
        cout << "Kontinent: "; printArrayOneLine(cont);
        cout << "cq-Zone: "; printArrayOneLine(cq);
        cout << "itu-Zone: "; printArrayOneLine(itu);
        cout << "Ende der Ausgabe\n";

        vector<Array2d<std::string>*> one;
        vector<Array2d<std::string>*> two;
        one.push_back(nullptr);
        one.push_back(nullptr);
        one.push_back(&cq);
        printScreen(one, two);

    }

    Ende Code zum Test einzelner Funktionen */
}
