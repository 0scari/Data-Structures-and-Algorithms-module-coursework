//
// Created by Oskars Pozdnakovs on 24/11/2017.
//

#ifndef WEEK_8_STRINGMATCH_H
#define WEEK_8_STRINGMATCH_H

class StringMatch
{

public:

    static vector <map <string, vector <unsigned int>> > matchStrings (string stringA, string stringB)
    {
        StringMatch::stringA = stringA;

        vector < map <string, vector <unsigned int>> > output;
        vector < map <string, vector <unsigned int>> > outputPairs;

        map <string, string>   stringABuffers;
        stringABuffers    =    createBuffersForMatching(stringA, stringB.length());

        do {
            outputPairs   = findMatchingStrings(stringABuffers, stringB);
            output.insert ( output.end(), outputPairs.begin(), outputPairs.end());

            repositionLetters(stringABuffers);

        } while ( hasLetters(stringABuffers["buffer2"]) );

        return output;
    }

private:

    static string stringA;

    static map <string, string> createBuffersForMatching(string stringA, unsigned int stringB)
    {
        string buffer1 = stringA.substr(0, stringA.length() - 1);
        string buffer2 = stringA.substr(stringA.length() - 1, 1) + string(stringB -1, ' ');

        return {{"buffer1", buffer1}, {"buffer2", buffer2}};
    }

    static void repositionLetters(map <string, string> &strBuffers)
    {
        char letterN = ' ';
        char letterM;

        for (int i  = 0; i < strBuffers["buffer1"].length(); ++i) {

            letterM = strBuffers["buffer1"][i];

            strBuffers["buffer1"][i] = letterN;

            letterN = letterM;
        }

        for (int i  = 0; i < strBuffers["buffer2"].length(); ++i) {

            letterM = strBuffers["buffer2"][i];

            strBuffers["buffer2"][i] = letterN;

            letterN = letterM;
        }
    }

    static vector < map <string, vector <unsigned int>> > findMatchingStrings(map <string, string> stringA, string stringB)
    {
        vector < map <string, vector <unsigned int>> > outputVector;

        // { {"strA", {}}, {"strB", {}} }
        map <string, vector <unsigned int>> matchedPair {};

        for (unsigned int i = 0; i < stringB.length(); ++i) {

            if (stringA["buffer2"][i] == stringB[i]) {

                matchedPair["strA"].push_back ( getMatchingStrAPos(stringA, i) );
                matchedPair["strB"].push_back ( i );

            } else {

                if ( matchedPair["strA"].size() > 0
                     and canReduceCost(matchedPair, {{'A', StringMatch::stringA},
                                                     {'B', stringB}}))

                    outputVector.push_back(matchedPair);


                matchedPair["strA"] = {};
                matchedPair["strB"] = {};
            }
        }

        // in case the matching letters were the rightmost
        // then we are 1 iteration short in the for loop
        // to push the pair into the output vector
        if ( matchedPair["strA"].size() > 0
             and canReduceCost(matchedPair, {{'A', StringMatch::stringA},
                                             {'B', stringB}}))

            outputVector.push_back(matchedPair);


        return outputVector;
    }

    static int getMatchingStrAPos (map <string, string> stringA, unsigned int index)
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

    static bool hasLetters(string string1)
    {
        for (char ch : string1)
            if (ch != ' ')
                return true;

        return false;
    }

    static bool canReduceCost(map <string, vector <unsigned int>> matchedPair, map <char, string> strings)
    {
        map <string, unsigned int> range = calcRange(matchedPair);
        int sizeDifference               = calcSizeDifference_A_to_B(range, strings);

        unsigned int alteringCost        = calcAlteringCost(range, sizeDifference);
        unsigned int replacementCost     = calcReplacementCost(range,
                                                               matchedPair["strA"].size(),
                                                               sizeDifference);

        return replacementCost < alteringCost;
    }

    static unsigned int calcAlteringCost (map <string, unsigned int> range, int sizeDifference)
    {
        if (sizeDifference > 0)
            sizeDifference = sizeDifference * -2;

        return (range["max"] - range["min"] + 1) * 5 + sizeDifference;
    }

    static unsigned int calcReplacementCost (map <string, unsigned int> range,
                                             unsigned int matchingLetters,
                                             int sizeDifference)
    {

        if (sizeDifference > 0)
            sizeDifference = sizeDifference * -4;

        else  if (sizeDifference < 0)
            sizeDifference = sizeDifference * 3;

        return (range["max"] - range["min"] - matchingLetters + 1) * 7 + sizeDifference;
    }

    static int calcSizeDifference_A_to_B (map <string, unsigned int> range, map <char, string> string)
    {

        if (range["max"] > string['A'].length() -1)

            return string['A'].length() - 1 - range["max"];

         else if (range["max"] > string['B'].length() -1)

            return range["max"] - (string['B'].length() - 1);


        return 0;

    }

};

string StringMatch::stringA;

#endif //WEEK_8_STRINGMATCH_H
