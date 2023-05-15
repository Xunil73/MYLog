#include "printfuncs.h"

// globale Hilfsfunktionen

inline void zeichneReihe(int width, char framechar) {
    for(int i=0; i<width; ++i) {
        std::cout << framechar;
    }
    std::cout << std::endl;
}


inline void zeichneRand(int width, char framechar, int lines) {
    for(int i=0; i<lines; ++i) {
        for(int j=0; j<width; ++j) {
            if(j == 0 || j== width-1) {
                std::cout << framechar;
            }
            else {std::cout << " ";}
        }
        std::cout << std::endl;
    }

}


Screen::Screen() {}

void Screen::setScreenWidth(int width) {
    screenWidth = width;
}

void Screen::setHeaderLines(int lines) {
    headerLines = lines;
}

void Screen::setBodyLines(int lines) {
    bodyLines = lines;
}

void Screen::setBodyText(Array2d<std::string>* arr) {
    filltext = arr;
}

int Screen::getScreenWidth() {
    return screenWidth;
}

int Screen::getHeaderLines() {
    return headerLines;
}

int Screen::getBodyLines() {
    return bodyLines;
}

void Screen::setFrameChar(const char framechar) {
    frameChar = framechar;
}

void Screen::printScreen() {
    zeichneReihe(screenWidth, frameChar);
    zeichneRand(screenWidth, frameChar, headerLines);
    zeichneReihe(screenWidth, frameChar);
}

