#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>


using namespace std;


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

void printMatchArray (vector < map <string, vector <unsigned int>> > matches) {

    cout << "Container size: " << matches.size() << endl;

    for(auto vectM : matches)
    {
        cout << endl << "----- \n";
        for(auto map : vectM)
        {
            cout << endl << map.first << endl;

            for(auto vI : map.second) {

                cout << vI, ", ";
            }
        }
    }
}

int* dMTest (array<int, 5> &arr)
{
    for (int &i : arr)
        if (i == 2)
            return &i;

};

#include "helpers.h"
#include "RangeIntersection.h"
#include "StringMatch.h"
#include "RangeIntersectionResolver.h"
#include "StringConvert.h"


int main() {

    vector < map <string, vector <unsigned int>> > res = StringMatch::matchStrings("ABCDEFGHIJ12345", "XXXBDACFXX0013");



//    cout << ":( " << res[6]["strB"][0] ;
//    printMatchArray(res);


    RangeIntersectionResolver::resolve(res);


//
    RangeIntersectionResolver::print();

//    createBuffersForMatching("ABCDEFG", 3);
//
//    map <string, string> buffers = createBuffersForMatching("ABCDEFG", 3);
//
//    printBuffers(buffers);
//
//    repositionLetters(buffers);
//
//    printBuffers(buffers);


//    string s1 = "ABCLOLAT";
//    string s2 = "ABCXAXAZL";
//
//    StringConvert::removeUnion(s1, s2);
//
//    cout <<  endl << s1 + "\n" + s2;
//    for (auto a : StringConvert::strUnion)
//        cout << a.first << ": " << a.second << "\n";

//    cout << "dbg";

//    for (auto letter : StringConvert::strUnion) {
//        cout << ": " + string(1,letter.second);
//        s2 = s2.substr(0,letter.first) + string(1,letter.second) + s2.substr(letter.first, s2.length() - letter.first);
//        cout << endl <<  s2 << endl;
//
//    }

//    map <string, unsigned int> test = getMinMax({{"strA", {5,6,7}},{"strB", {2,3,4}}});
//    cout << "min " << test["min"] << " | max: " << test["max"];

//    vector < map <string, vector<int>> > test = {{{"buffer1", {1,2,3}}, {"buffer2", {1,2,4}}}, {{"buffer1", {1,2,3}}, {"buffer2", {1,2,4}}}};
//
//    map <string, vector<int>> *ptr = &test[1];
//
//    cout << test.size() << endl;
//
//    for (int i = 0; i < test.size(); ++i)
//
//        if (ptr == &test[i])
//            test.erase(test.begin() + i);
//
//    cout << test.size();




//    array <int, 5> arr {1,2,3,4,5};
//
//    int *a = dMTest(arr);
//
//    for (auto &ar : arr)
//        if (a == &ar)
//            cout << &ar << endl;
//
////    cout << a;


}