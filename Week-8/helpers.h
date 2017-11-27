//
// Created by Oskars Pozdnakovs on 25/11/2017.
//

#ifndef WEEK_8_HELPERS_H
#define WEEK_8_HELPERS_H

map <string, unsigned int> calcRange (map<string, vector<unsigned int>> matchedPair)
{
    unsigned int min = matchedPair["strA"][0];
    unsigned int max = matchedPair["strA"][0];

    for (auto matchingPos : matchedPair["strA"]) {

        if (matchingPos < min)
            min = matchingPos;

        if (matchingPos > max)
            max = matchingPos;
    }

    for (auto matchingPos : matchedPair["strB"]) {

        if (matchingPos < min)
            min = matchingPos;

        if (matchingPos > max)
            max = matchingPos;
    }

    return {{"min", min}, {"max", max}};
}

void printIntersectingPairs (vector < vector <map <string, vector <unsigned int>>*>> intersectingPairs)
{
    for (auto pair : intersectingPairs) {

        cout << "\n Pair \n";

        for (auto strPair : pair) {

            cout << "\nString Pair \n";

            for (auto strRange : *strPair) {

                cout << endl << strRange.first << ": ";

                for (auto letter : strRange.second) {

                    cout << letter << " - ";
                }

            }
            cout << endl;

        }
    }
}

void printIntersectingPair (vector <map <string, vector <unsigned int>>*> intersectingPair)
{
    cout << "\n Pair \n";

    for (auto strPair : intersectingPair) {

        cout << "\nString Pair \n";

        for (auto strRange : *strPair) {

            cout << endl << strRange.first << ": ";

            for (auto letter : strRange.second) {

                cout << letter << " - ";
            }

        }
        cout << endl;

    }
}

void printConsecutivePairs (map < map <string, vector <unsigned int>>*,
        vector < map <string, vector <unsigned int>>*>> consecutivePairs)
{
    for (auto pair : consecutivePairs) {

        cout << "\n Consecutive Pair \n";

        cout << "\n Key \n";


        for (auto strRange : *pair.first) {

            cout << endl << strRange.first << ": ";

            for (auto letter : strRange.second) {

                cout << letter << " - ";
            }
        }

        cout << "\n Value \n";


        for (auto strPair : pair.second) {

            cout << "\nString Pair \n";

            for (auto strRange : *strPair) {

                cout << endl << strRange.first << ": ";

                for (auto letter : strRange.second) {

                    cout << letter << " - ";
                }

            }
            cout << endl;

        }
    }
}

static map <string, unsigned int> calcTotalRange (map <string, unsigned int> range1,
                                                  map <string, unsigned int> range2)
{
    unsigned int min;
    unsigned int max;

    range1["min"] <= range2["min"] ? min = range1["min"] : min = range2["min"];
    range1["max"] >= range2["max"] ? max = range1["max"] : max = range2["max"];

    return {{"min", min}, {"max", max}};
}

//vector <const unique_ptr<map<string, unsigned int>>> getKeys (map < unique_ptr<map<string, unsigned int>>,
//        RangeIntersection> &rangeIntersections)
//{
//    vector <const unique_ptr<map<string, unsigned int>>> keys;
//
//    for (const auto &elem : rangeIntersections)
//        keys.push_back(elem.first);
//
//    return keys;
//};

#endif //WEEK_8_HELPERS_H
