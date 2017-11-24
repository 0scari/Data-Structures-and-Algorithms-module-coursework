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


};

#endif //WEEK_8_STRINGCONVERT_H
