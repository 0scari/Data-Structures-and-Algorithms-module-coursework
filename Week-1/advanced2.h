//
// Created by Oskars Pozdnakovs on 12/10/2017.
//

#ifndef WEEK_1_ADVANCED2_H
#define WEEK_1_ADVANCED2_H

// MUST BE SORTED BY THE PRICE DESCENDING
map <string, map<string, int>> materials = {
        {"gold",    {{"amount", 7},    {"price", 10}}},
        {"silver",  {{"amount", 5},    {"price", 7}}},
        {"copper",  {{"amount", 9},    {"price", 6}}},
        {"iron",    {{"amount", 3},    {"price", 5}}},
        {"plastic", {{"amount", 3},    {"price", 3}}}
};

map<string, int> getAvailableMaterialAmount (map<string, int> & material, int kgFree) {

}

string advanced2 (int maxWeight) {

    map<string, int> materialLoad;
    int totalPayloadValue = 0;

    // Assuming the materials are sorted by their price
    for (auto &material : materials) {

        materialLoad        = getAvailableMaterialAmount(material.second, maxWeight);

        maxWeight           -= materialLoad["weight"];

        totalPayloadValue   += materialLoad["price"];

        if (maxWeight == 0)
            break;
    }

    


}

#endif //WEEK_1_ADVANCED2_H
