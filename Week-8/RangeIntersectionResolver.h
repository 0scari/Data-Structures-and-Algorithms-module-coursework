//
// Created by Oskars Pozdnakovs on 25/11/2017.
//

#ifndef WEEK_8_RANGEINTERSECTIONRESOLVER_H
#define WEEK_8_RANGEINTERSECTIONRESOLVER_H

class RangeIntersectionResolver
{

public:

    static vector < map <string, vector <unsigned int>>> resolve (
                                    vector < map <string, vector <unsigned int>> > &matchedPairContainer)
    {
        vector < vector <map <string, vector <unsigned int>>*>> intersectingPairs;
        vector <map <string, vector <unsigned int>>*>           intersectingPair;

        // pairs that can be merged not causing logic errors
        // example: [strA: "ABCDEF", strB: "XYWBAE"], merge B - E ranges (strA(2) and strB(6))
        map < map <string, vector <unsigned int>>*,
                vector < map <string, vector <unsigned int>>*>> consecutivePairs;

        for (int i = 0; i < matchedPairContainer.size() -2; ++i) {

            for (int j = i + 1; j < matchedPairContainer.size() -1; ++j) {

                if (rangesIntersect(matchedPairContainer[i], matchedPairContainer[j])) {

                    // if intersects the preceding pair becomes a value of the other pair that becomes the key
                    // in consecutivePairs vector
                    checkIfConsecutive(matchedPairContainer[i], matchedPairContainer[j], consecutivePairs);

                    intersectingPair.push_back(&matchedPairContainer[i]);
                    intersectingPair.push_back(&matchedPairContainer[j]);
                }
            }

            // reset content of intersectingPair
            if (intersectingPair.size() > 0) {

                intersectingPairs.push_back(intersectingPair);
                intersectingPair = {};

            }
        }

        if (consecutivePairs.size() > 0)
            intersectingPairs = mergeConsecutivePairs(consecutivePairs, intersectingPairs);

        eliminateMostExpensivePairsInIntersections(intersectingPairs, matchedPairContainer);

    }

    static  map <string, vector <unsigned int>>* getCheapestIntersection (
            map <string, vector <unsigned int>> &containerPair,
            map <string, vector <unsigned int>> &matchedPair)
    {
        // TODO TEST!!!

        map <string, unsigned int> containerPairRange = calcRange(containerPair);
        map <string, unsigned int> matchedPairRange   = calcRange(matchedPair);

        map <string, unsigned int> totalRange         = calcTotalRange(containerPairRange,
                                                                       matchedPairRange);

    };

private:

    static bool checkIfConsecutive (map <string, vector <unsigned int>> &pair1,
                                    map <string, vector <unsigned int>> &pair2,
                                    map < map <string, vector <unsigned int>>*,
                                            vector < map <string, vector <unsigned int>>*>> &consecutivePairs)
    {

        if (pair1["min"] < pair2["min"] && pair1["max"] < pair2["max"]) { // pair2 precedes p1

            consecutivePairs[&pair1].push_back(&pair2);
            return true;

        } else if (pair1["min"] < pair2["min"] && pair1["max"] < pair2["max"]) { // pair1 precedes p2

            consecutivePairs[&pair2].push_back(&pair1);
            return true;

        } else
            return false;
    }

    static vector < vector <map <string, vector <unsigned int>>*>> mergeConsecutivePairs (
                map < map <string, vector <unsigned int>>*,
                    vector < map <string, vector <unsigned int>>*>>     consecutivePairs,
                vector < vector <map <string, vector <unsigned int>>*>> intersectingPairs)
    {

    }

    // TODO test
    static unsigned int getRangeConversionCosts (map <string, unsigned int> range,
                                                 map <string, unsigned int> totalRange)
    {
        unsigned int conversionCost = 0;

        if (range["min"] == totalRange["min"]) { // will be two substrings

            if (range["max"] <  totalRange["max"]) {

                conversionCost += StringMatch::calcConversionCost(range["min"], range["max"],
                                                                  true, range["max"] - range["max"] + 1);
                conversionCost += StringMatch::calcConversionCost(range["max"] + 1, totalRange["max"]);

            } else
                // the range spans across the entire total range
                conversionCost += StringMatch::calcConversionCost(range["min"], range["max"],
                                                                  true, range["max"] - range["max"] + 1);

        } else if (range["max"] == totalRange["max"]) {

            if (range["min"] >  totalRange["min"]) {

                conversionCost += StringMatch::calcConversionCost(range["min"], range["max"],
                                                                  true, range["max"] - range["max"] + 1);
                conversionCost += StringMatch::calcConversionCost(totalRange["min"], range["min"] -1);

            } else
                // the range spans across the entire total range
                conversionCost += StringMatch::calcConversionCost(range["min"], range["max"],
                                                                  true, range["max"] - range["max"] + 1);

        } else { // will be three substrings

            conversionCost += StringMatch::calcConversionCost(totalRange["min"], range["min"] - 1);
            conversionCost += StringMatch::calcConversionCost(range["min"], range["max"],
                                                              true, range["max"] - range["max"] + 1);
            conversionCost += StringMatch::calcConversionCost(range["max"] + 1, totalRange["max"]);
        }

        return conversionCost;
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

    static bool rangesIntersect(map<string, vector<unsigned int>> range1, map<string, vector<unsigned int>> range2)
    {
        if (range1["min"] >= range2["min"] and range1["min"] <= range2["max"])

            return true;

        return range1["max"] >= range2["min"] and range1["max"] <= range2["max"];
    }


    // TODO Implement
    static void eliminateMostExpensivePairsInIntersections(
            vector < vector <map <string, vector <unsigned int>>*>> intersectingPairs,
            vector < map <string, vector <unsigned int>> >          &matchedPairContainer)
    {

    }

};

#endif //WEEK_8_RANGEINTERSECTIONRESOLVER_H
