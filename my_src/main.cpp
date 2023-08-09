#include <iostream>
#include <string>

#include "hamfunc.h"
#include "printfuncs.h"
#include <vector>

using namespace std;

int main()
{

     //string call ="R1AN/DJ5MY";

    string call ="XV9/DJ5MY";

     Array2d<std::string> full = getFullDxccInfos(call);
     Array2d<std::string> dxccRef = getDxccRefIDs(call);
     printArray(full);
     printArray(dxccRef);



/*

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
*/

}
