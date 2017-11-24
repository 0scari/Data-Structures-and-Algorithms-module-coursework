//
// Created by Oskars Pozdnakovs on 23/11/2017.
//

#ifndef WEEK_8_STRINGCONVERT_H
#define WEEK_8_STRINGCONVERT_H

class StringConvert {

public:
    StringConvert(string stringA, string stringB)
    {

        this->stringB = stringB;

        convert("CDEBDE", "ABCDE");
    }

private:

    string          stringB;
    map <int, char> strUnion;

    vector <int>    costs;
    vector <string> converts;

    void convert (string stringA, string stringB)
    {
        removeUnion(stringA, stringB);

    }

    void removeUnion(string &stringA, string &stringB)
    {

    }

    string restoreUnion(string stringA)
    {

    }

    int calcMatchRate (string stringA, string stringB)
    {

    }

    string insertChar (string str, int pos, char letter)
    {

    }

    string deleteChar (string str, int pos)
    {

    }

    vector <map <string, vector <int>> > matchStrings (string stringA, string stringB)
    {
        vector < map <string, vector <int>> > output;

        map <string, string>   stringAMatch;
        stringAMatch     =     getStringsForMatching(stringA, stringB.length());

        map <string, vector <int>> matchedPair { {'strA', {}}, {'strB', {}} };



        return output;
    }

    map <string, string> getStringsForMatching (string stringA, long int stringB)
    {
        map <string, string> output;
        output.emplace('buffer1', "CDEBDE");
        output.emplace('buffer2', "     ");

        return output;
    }

    vector < map <string, vector <int>> > findMatchingStrings(map <string, string> stringA, string stringB)
    {
        vector < map <string, vector <int>> > output;

        map <string, vector <int>> matchedPair { {'strA', {}}, {'strB', {}} };

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





};

#endif //WEEK_8_STRINGCONVERT_H
