//
// Created by Oskars Pozdnakovs on 25/11/2017.
//

#ifndef WEEK_8_RANGEINTERSECTIONRESOLVER_H
#define WEEK_8_RANGEINTERSECTIONRESOLVER_H

class RangeIntersectionResolver
{

public:
    static map <string, vector <unsigned int>>* hasRangeIntersection (
                                                vector < map <string, vector <unsigned int>> > &matchedPairContainer,
                                                map <string, vector <unsigned int>>   matchedPair)
    {
        for (auto &containerPair : matchedPairContainer)

            if (rangesIntersect(matchedPair, containerPair))

                return &containerPair;

        return nullptr;
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

    static unsigned int getRangeConvertingCosts (map <string, unsigned int> range,
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



    static vector < map <string, vector <unsigned int>> > resolveRangeIntersection ()
    {

    }

};

#endif //WEEK_8_RANGEINTERSECTIONRESOLVER_H
