//
// Created by Oskars Pozdnakovs on 25/11/2017.
//

#ifndef WEEK_8_RANGEINTERSECTIONRESOLVER_H
#define WEEK_8_RANGEINTERSECTIONRESOLVER_H

class RangeIntersectionResolver
{
    static vector <RangeIntersection> rangeIntersections;

    static vector < map <string, vector <unsigned int>>> registeredIntersections;


public:

    static void resolve (
                                    vector < map <string, vector <unsigned int>> > &matchedPairsContainer)
    {



        for (int i = 0; i < matchedPairsContainer.size() -1; ++i) {

//            bool i_wasPushed = false;

            for (int j = i + 1; j < matchedPairsContainer.size(); ++j) {


                if (rangesIntersect(matchedPairsContainer[i], matchedPairsContainer[j])) {

                    addToRangeIntersections(matchedPairsContainer[i], matchedPairsContainer[j]);

//                    if (!i_wasPushed) {
//                        intersectingPair.push_back(&matchedPairsContainer[i]);
//                        i_wasPushed = true;
//                    }
//                    intersectingPair.push_back(&matchedPairsContainer[j]);
                }
            }

//            // reset content of intersectingPair
//            if (intersectingPair.size() > 0) {
//
//                intersectingPairs.push_back(intersectingPair);
//                intersectingPair = {};
//
//            }
        }

        // TODO keepCheapestIntersections();

//printIntersectingPairs(intersectingPairs);
//        printConsecutivePairs(consecutivePairs);
//
//
//        if (consecutivePairs.size() > 0)
//            intersectingPairs = mergeConsecutivePairs(consecutivePairs, intersectingPairs);


//        printConsecutivePairs(consecutivePairs);

//        eliminateMostExpensivePairsInIntersections(intersectingPairs, matchedPairsContainer);


    }

//    void eliminat

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

//private:

    static void addToRangeIntersections (map <string, vector<unsigned int>> &pair1,
                                         map <string, vector<unsigned int>> &pair2)
    {
        map <string, unsigned int> range1 = calcRange(pair1);
        map <string, unsigned int> range2 = calcRange(pair2);


        map <string, unsigned int> range = calcTotalRange(range1, range2);

        int i = 0;
        bool intersectionFound = false;

        for (auto &rangeIntersection : rangeIntersections) {

            if (rangesIntersect(rangeIntersection.getRange(), range)){
                i++;
                rangeIntersection.addRangeIntersection(pair1, pair2);
                intersectionFound = true;
            }

            // TODO remove once tested
            if (i > 1)
                throw logic_error("Intersection with 2 classes!");
        }

        if (!intersectionFound)
            rangeIntersections.push_back(RangeIntersection(pair1, pair2, range));
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

    static bool rangesIntersect(map <string, vector <unsigned int>> pair1,
                                map <string, vector <unsigned int>> pair2)
    {
        map <string, unsigned int> range1 = calcRange(pair1);
        map <string, unsigned int> range2 = calcRange(pair2);

        if (range1["min"] >= range2["min"] and range1["min"] <= range2["max"])

            return true;

        return range1["max"] >= range2["min"] and range1["max"] <= range2["max"];
    }

    static bool rangesIntersect(map <string, unsigned int> range1,
                                map <string, unsigned int> range2)
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

    static bool notRegistered (map <string, vector <unsigned int>> &pair1,
                               map <string, vector <unsigned int>> &pair2)
    {

    }

    static void registerIntersections (map <string, vector <unsigned int>> &pair1,
                                       map <string, vector <unsigned int>> &pair2)
    {

    }

    static void print()
    {

        int i = 0;

        for (auto X : rangeIntersections) {
            cout << "\nClass " << ++i<< endl;

            printIntersectingPair(X.intersectingRangePairs);

            printConsecutivePairs(X.consecutivePairs);

        }




    }

};

vector < map <string, vector <unsigned int>>>       RangeIntersectionResolver::registeredIntersections;
vector <RangeIntersection> RangeIntersectionResolver::rangeIntersections;

#endif //WEEK_8_RANGEINTERSECTIONRESOLVER_H
