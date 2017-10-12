//
// Created by Oskars Pozdnakovs on 12/10/2017.
//

#ifndef WEEK_1_ADVANCED2_H
#define WEEK_1_ADVANCED2_H

// MUST BE SORTED BY THE PRICE DESCENDING
const map <string, map<string, int>> MATERIALS = {
        {"gold",    {{"amount", 7},    {"price", 10}}},
        {"silver",  {{"amount", 5},    {"price", 7}}},
        {"copper",  {{"amount", 9},    {"price", 6}}},
        {"iron",    {{"amount", 3},    {"price", 5}}},
        {"plastic", {{"amount", 3},    {"price", 3}}}
};

string advanced2 (Lorry lorry) {

    for (auto material : MATERIALS) {

        lorry.addPayload(material.first, material.second);

        if (lorry.isFull())
            break;
    }

    return lorry.prepareInvoice();


}

#endif //WEEK_1_ADVANCED2_H
