#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>


using namespace std;

#include "StringConvert.h"

int getMatchingStrAPos (array <string, 2> stringA, int index)
{
    int stringALen = -1;

    for (char ch : stringA[0])

        if (ch != ' ')
            stringALen += 1;


    for (int i = 0; i <= index; ++i)

        if (stringA[1][i] != ' ')
            stringALen += 1;

    return stringALen;
}

int main() {


    int res = getMatchingStrAPos({"    CD", "EBDE "}, 1);

    std::cout << res << std::endl;
    return 0;
}