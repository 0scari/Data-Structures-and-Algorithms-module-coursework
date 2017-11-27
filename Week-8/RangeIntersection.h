//
// Created by Oskars Pozdnakovs on 27/11/2017.
//

#ifndef WEEK_8_RANGEINTERSECTION_H
#define WEEK_8_RANGEINTERSECTION_H
class RangeIntersection
{
    vector <map <string, vector <unsigned int>>*> intersectingRangePairs;

    // pairs that can be merged not causing logic errors
    // example: [strA: "ABCDEF", strB: "XYWBAE"], merge B - E ranges (strA(2) to strB(6))
    map < map <string, vector <unsigned int>>*,
            vector < map <string, vector <unsigned int>>*>> consecutivePairs;

public:

    void addIntersectionRange(map <string, vector <unsigned int>>*)
    {

    }

    void addConsecutivePair(map <string, vector <unsigned int>>* key,
                            vector < map <string, vector <unsigned int>>*> value)
    {

    }
};

#endif //WEEK_8_RANGEINTERSECTION_H
