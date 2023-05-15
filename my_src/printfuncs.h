#ifndef PRINTFUNCS_H
#define PRINTFUNCS_H

#include <iostream>
#include <vector>
#include "array2d.h"

void printLine();
void printEmptyFrame();

void printScreen(std::vector<Array2d<std::string>*> header, std::vector<Array2d<std::string>*> body) {
    printLine();
    for(auto element : header) {
        if(element == nullptr) {
            printEmptyFrame();
        }
        else {
            std::cout << "*  "; printArrayOneLine(*element);
            std::cout.width(74);
            std::cout.fill(' ');
            std::cout << "";
            std::cout << '*';
        }

    }
}

inline void printLine() {
    std::cout.width(75);
    std::cout.fill('*');
    std::cout << "";
    std::cout << std::endl;
}

inline void printEmptyFrame() {
    std::cout << '*';
    std::cout.width(73);
    std::cout.fill(' ');
    std::cout << "";
    std::cout << '*' << std::endl;
}
#endif // PRINTFUNCS_H
