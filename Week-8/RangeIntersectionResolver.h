//
// Created by Oskars Pozdnakovs on 25/11/2017.
//

#ifndef WEEK_8_RANGEINTERSECTIONRESOLVER_H
#define WEEK_8_RANGEINTERSECTIONRESOLVER_H

class RangeIntersectionResolver
{

public:
    static map <string, vector <unsigned int>>* hasRangeIntersection (
                                                vector < map <string, vector <unsigned int>> > containerVector,
                                                map <string, vector <unsigned int>>   matchedPair)
    {
        for (int i = 0; i < containerVector.size(); ++i) {

            for (int j = 0; j < containerVector.size(); ++j)

                if (j != i) {

                    if (rangesIntersect(containerVector[i], containerVector[j]) )


                }
        }
    }

    static  map <string, vector <unsigned int>>* getCheapestIntersection (
            map <string, vector <unsigned int>>* containerVector,
            map <string, vector <unsigned int>>* matchedPair)
    {

    };

private:

    static bool rangesIntersect(map<string, vector<unsigned int>> range1, map<string, vector<unsigned int>> range2)
    {
        if (range1["min"] >= range2["min"] and range1["min"] <= range2["max"])

            return true;

        return range1["max"] >= range2["min"] and range1["max"] <= range2["max"];
    }

    static map <string, vector<unsigned int>>* returnSmallest (map <string, vector<unsigned int>> *range1,
                                                               map <string, vector<unsigned int>> *range2)
    {

    }

    static vector < map <string, vector <unsigned int>> > resolveRangeIntersection ()
    {
    }

};

#endif //WEEK_8_RANGEINTERSECTIONRESOLVER_H
