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
        vector < map <string, vector <int>> > outputPairs;


        map <string, string>   stringABuffers;
        stringABuffers  = createBuffersForMatching(stringA, stringB.length());

        do {
            outputPairs     = findMatchingStrings(stringABuffers, stringB);
            output.insert   ( output.end(), outputPairs.begin(), outputPairs.end());



        } while (hasLetters(stringABuffers["buffer2"]));

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

    int getMatchingStrAPos (map <string, string> stringA, int index)
    {
        int stringALen = -1;

        for (char ch : stringA["buffer1"])

            stringALen += 1;

        for (int i = 0; i <= index; ++i)

            stringALen += 1;

        return stringALen;

    }

    bool hasLetters(string string1)
    {
        for (char ch : string1)
            if (ch != ' ')
                return true;

        return false;
    }

    int quantityOfLetters(string string1)
    {
        int letters = 0;

        for (char ch : string1)
            if (ch != ' ')
                letters++;

        return letters;
    }



};

#endif //WEEK_8_STRINGCONVERT_H
