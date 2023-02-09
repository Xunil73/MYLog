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

    string call ="R1AN/DJ6TB/p";

    Array2d<std::string> dxcc_indexes = getDxccIndex(call);

    printArray(dxcc_indexes);






}
