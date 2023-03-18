#ifndef PRINTFUNCS_H
#define PRINTFUNCS_H

#include <cstring>

class Userinterface {
    public:
        Userinterface();
        void drawHeader(const char* filltext);
        void drawBody();
        void drawInputSection();
};

inline Userinterface::Userinterface() {}

inline void Userinterface::drawHeader(const char* filltext) {
    std::cout.width(70);
    std::cout.fill('*');
    std::cout << "" << std::endl;

    // Rahmen wird gezeichnet, in der Mitte fuegen wir den filltext ein
    int filltextLen = strlen(filltext);
    int centerpos;
    if (filltextLen % 2 == 0) centerpos = 34 - filltextLen / 2;
    else centerpos = 33 - filltextLen / 2;

    for(int j=0; j<5; ++j) {
        if(j==2) {
            std::cout << "*";
            for(int i=0; i<(34 - filltextLen / 2); ++i) {
                std::cout << " ";
            }
            std::cout << filltext;
            for(int i=0; i<centerpos; ++i) {
                std::cout << " ";
            }
            std::cout << "*" << std::endl;
        }
        else {
            std::cout << "*";
            for(int i=0; i<68; ++i) {
                std::cout << " ";
            }
            std::cout << "*" << std::endl;
        }
    }
        std::cout.width(70);
        std::cout.fill('*');
        std::cout << "" << std::endl;
}
#endif // PRINTFUNCS_H
