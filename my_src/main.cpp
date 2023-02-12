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

    printArrayOneLine(cq_zones);

    Array2d<std::string> itu_zones = getItuZoneInfos(call);

    printArrayOneLine(itu_zones);
}
