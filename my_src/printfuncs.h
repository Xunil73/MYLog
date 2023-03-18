#ifndef PRINTFUNCS_H
#define PRINTFUNCS_H

class Userinterface {
    public:
        Userinterface();
        void drawHeader();
        void drawBody();
        void drawInputSection();
};

inline Userinterface::Userinterface() {}

inline void Userinterface::drawHeader() {
    std::cout.width(70);
    std::cout.fill('*');
    std::cout << "" << std::endl;

    for(int j=0; j<4; ++j) {
        std::cout << "*";
        for(int i=0; i<68; ++i) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }

    std::cout.width(70);
    std::cout.fill('*');
    std::cout << "" << std::endl;
}
#endif // PRINTFUNCS_H
