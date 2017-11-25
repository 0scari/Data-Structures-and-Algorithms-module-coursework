//
// Created by Oskars Pozdnakovs on 23/11/2017.
//

#ifndef WEEK_8_STRINGCONVERT_H
#define WEEK_8_STRINGCONVERT_H

class StringConvert {

public:
    StringConvert(string stringA, string stringB)
    {
        // TODO ensure str_len > 1

        this->stringB = stringB;

        convert("DEGOLIMAZ", "ABCTTTTTTTTTTTTTDE");
    }

//private:

    static string          stringB;
    static map <int, char> strUnion;

    static vector <int>    costs;
    static vector <string> converts;

    void convert (string stringA, string stringB)
    {
        removeUnion(stringA, stringB);



    }

    static void removeUnion(string &stringA, string &stringB)
    {
        // TODO remove union feature

        string longestStr;
        string shortestStr;

        if (stringA.length() >= stringB.length()) {

            longestStr  = stringA;
            shortestStr = stringB;

        } else {

            longestStr  = stringB;
            shortestStr = stringA;
        }

        unsigned int strLen = shortestStr.length();

        int n = 0; // quantity of removed chars;

        for (unsigned int i = 0; i < strLen; ++i) {

            if (stringA[i] == stringB[i]) {

                strUnion[i + n] = stringA[i];

                stringA = stringA.substr(0, i) + stringA.substr(i +1, stringA.length() - i);
                stringB = stringB.substr(0, i) + stringB.substr(i +1, stringB.length() - i);

                i      -= 1;
                strLen -= 1;
                n      += 1;
            }
        }
    }

    string restoreUnion(string strIn)
    {
        for (auto letter : strUnion)

            strIn = strIn.substr(0,letter.first)
                    + string(1,letter.second)
                    + strIn.substr(letter.first, strIn.length() - letter.first);

        return strIn;
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


};

map <int, char> StringConvert::strUnion;

#endif //WEEK_8_STRINGCONVERT_H
