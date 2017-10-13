//
// Created by Oskars Pozdnakovs on 13/10/2017.
//

#ifndef WEEK_1_WAREHOUSE_H
#define WEEK_1_WAREHOUSE_H

class Warehouse {

    // THE VECTOR MUST BE ORDERED BY THE MOST EXPENSIVE MATERIAL
    map <string, map <string, int>> stock = {
            {"gold",    {{"amount", 7},    {"price", 10}}},
            {"silver",  {{"amount", 5},    {"price", 7}}},
            {"copper",  {{"amount", 9},    {"price", 6}}},
            {"iron",    {{"amount", 3},    {"price", 5}}},
            {"plastic", {{"amount", 3},    {"price", 3}}}
    };

public:

    Warehouse() {}

    map <string, map <string, int>> getMostExpensiveMaterial() {

        map <string, map <string, int>> mostExpensiveMaterial;

        int highestMaterialPrice = 0;

        string highestPricedMaterialsName;

        for (auto material : stock) {

            if (material.second["price"] > highestMaterialPrice) {

                mostExpensiveMaterial.clear();

                mostExpensiveMaterial[material.first] = material.second;

                highestPricedMaterialsName = material.first;

                highestMaterialPrice = material.second["price"];

            }
        }

        stock.erase(highestPricedMaterialsName);

        return mostExpensiveMaterial;

    }

    bool hasStock() {

        return stock.size() > 0;

    }

};

#endif //WEEK_1_WAREHOUSE_H
