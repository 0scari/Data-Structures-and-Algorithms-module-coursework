#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>


using namespace std;

//#include "StringConvert.h"

int getMatchingStrAPos (map <string, string> stringA, int index)
{
    int stringALen = -1;

    for (char ch : stringA["buffer1"])

        if (ch != ' ')
            stringALen += 1;


    for (int i = 0; i <= index; ++i)

        if (stringA["buffer2"][i] != ' ')
            stringALen += 1;

    return stringALen;

}

vector < map <string, vector <int>> > findMatchingStrings(map <string, string> stringA, string stringB)
{

    vector < map <string, vector <int>> > output;

    map <string, vector <int>> matchedPair { {"strA", {}}, {"strB", {}} };

    for (int i = 0; i < stringB.length(); ++i) {

        if (stringA["buffer2"][i] == stringB[i]) {

            matchedPair["strA"].push_back ( getMatchingStrAPos(stringA, i) );
            matchedPair["strB"].push_back ( i );

        } else {

            if ( matchedPair["strA"].size() > 0 ) {

                output.push_back(matchedPair);

                matchedPair["strA"] = {};
                matchedPair["strB"] = {};

            }
        }
    }
    return output;
}




int main() {


//    vector < map <string, vector <int>> > res = findMatchingStrings( {{"buffer1", " MU"}, {"buffer2", "BACDEUX "}},
//                                                                      "BADEMLXX");
//
//    for(auto vectM : res)
//    {
//        for(auto map : vectM)
//        {
//            cout << endl << map.first << endl;
//
//            for(auto vI : map.second) {
//
//                cout << vI, ", ";
//            }
//        }
//    }
}