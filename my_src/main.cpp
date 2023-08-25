//#include <iostream>
#include <ncurses.h>
#include <panel.h>
#include <menu.h>
#include "initializations.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include "hamfunc.h"
#include "printfuncs.h"
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
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


    int row, col; //Zeilen, Spalten
    initscr();
    atexit(quit);

    getmaxyx(stdscr, row, col);
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    //nodelay(stdscr, TRUE); // zum Test auskommentiert, da ich Programmende ganz unten durch getch() verhindere
    termResizeOrQuit(row, col); /* wir muessen terminal resizen falls zu klein, ansonsten Abbruch
                                   Definition in initializations.h */
    start_color();

    drawStdscrStylesheet(row, col); /* Grundlegendes Stylesheet des stdscr - initializations.h */
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
