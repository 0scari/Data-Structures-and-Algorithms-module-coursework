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

    vector < array <vector <int>, 2> > matchStrings (string stringA, string stringB)
    {
        vector < array <vector <int>, 2> > output;

        array <string, 2>   stringForMatching;
        stringForMatching = getStringsForMatching(stringA, stringB.length());

        for (string matching : stringsForMatching) {

        }

    }

    array <string, 2> getStringsForMatching (string stringA, long int stringB)
    {
        return {"CDEBDE", "     "};
    }

    vector < array <vector <int>, 2> > findMatchingStrings(string stringA, string stringB)
    {
        vector < array  <vector  <int>, 2> > output;
        array  < vector <int>, 2 >           matchingPair;

        array  < string, 2 > strAForMatching = ; // TODO where to put it?

        do {

            for (int i = 0; i < stringA.length(); ++i) {

                if (stringA[i] == stringB[i]) {

                    matchingPair[1].push_back(getMatchingStrAPos(i));
                    matchingPair[1].push_back(i);
                }

            }
        } while
    }

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





};

#endif //WEEK_8_STRINGCONVERT_H
