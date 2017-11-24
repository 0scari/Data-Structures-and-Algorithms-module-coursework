#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>


using namespace std;

#include "StringConvert.h"

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


map <string, string> createBuffersForMatching(string stringA, unsigned int stringB)
{
    string buffer1 = stringA.substr(0, stringA.length() - 1);
    string buffer2 = stringA.substr(stringA.length() - 1, 1) + string(stringB -1, ' ');

    return {{"buffer1", buffer1}, {"buffer2", buffer2}};
}

void repositionLetters(map <string, string> &strBuffers)
{
    char letterN = ' ';
    char letterM;

    for (int i = 0; i < strBuffers["buffer1"].length(); ++i) {

        letterM = strBuffers["buffer1"][i];

        strBuffers["buffer1"][i] = letterN;

        letterN = letterM;
    }

    for (int i = 0; i < strBuffers["buffer2"].length(); ++i) {

        letterM = strBuffers["buffer2"][i];

        strBuffers["buffer2"][i] = letterN;

        letterN = letterM;
    }

};

void printBuffers(map <string, string> buffers)
{
    for (auto buffer : buffers) {
        cout << buffer.first << ": " << buffer.second << "|" << endl;
    }


    return;
}

int main() {

    createBuffersForMatching("ABCDEFG", 3);

    map <string, string> buffers = createBuffersForMatching("ABCDEFG", 3);

    printBuffers(buffers);

    repositionLetters(buffers);

    printBuffers(buffers);



//    cout << s;

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