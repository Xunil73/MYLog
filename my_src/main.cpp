#include <iostream>
#include <string>
/*
#include "array2d.h"
#include "Datenbank.h"
*/
#include "hamfunc.h"

using namespace std;

int main()
{

    string call ="LU/DJ5MY/Z";

    Array2d<std::string> dxcc_indexes = getDxccRefID(call);

    printArray(dxcc_indexes);

    Array2d<std::string> fullDxccInfo = getFullDxccInfo(call);

    printArray(fullDxccInfo);
}

