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

#endif //WEEK_8_HELPERS_H
