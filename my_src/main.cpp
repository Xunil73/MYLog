#include <iostream>
#include <string>

#include "hamfunc.h"


using namespace std;

int main()
{

    string call ="R1AN/DJ5MY";

    Array2d<std::string> dxcc_indexes = getDxccRefIDs(call);

    printArray(dxcc_indexes);

    Array2d<std::string> fullDxccInfo = getFullDxccInfos(call);

    printArray(fullDxccInfo);

    Array2d<std::string> cq_zones = getCqZoneInfos(call);

    for(size_t i=0; i<cq_zones.getZeilen(); ++i) {
        for(size_t j=0; j<cq_zones.getSpalten(); ++j) {
            cout << cq_zones.at(i,j) << ", ";
        }
    }
    cout << endl;

    Array2d<std::string> itu_zones = getItuZoneInfos(call);

    for(size_t i=0; i<itu_zones.getZeilen(); ++i) {
        for(size_t j=0; j<itu_zones.getSpalten(); ++j) {
            cout << itu_zones.at(i,j) << ", ";
        }
    }
    cout << endl;
}
