//
// Created by Oskars Pozdnakovs on 12/10/2017.
//

#ifndef WEEK_1_PAYLOAD_H
#define WEEK_1_PAYLOAD_H


class Lorry {

    int maxWeight;
    int actualWeight = 0;
    int totalValue   = 0;

    // "materialName": weight
    map <string, int> loadedMaterials = {};

public:

    Lorry(int maxWeight) {

        this->maxWeight = maxWeight;

    };

    int getActualWeight() {
        return actualWeight;
    }

    int getTotalValue() {
        return totalValue;
    }

    const map<string, int> &getLoadedMaterials() {
        return loadedMaterials;
    }

    bool isFull () {

        return maxWeight == actualWeight;

    }

    string prepareInvoice () {

        string invoice = "Total price: £" + to_string(totalValue);

        for (auto loadedMaterial : loadedMaterials)
            invoice += "\n" + loadedMaterial.first + " " + to_string(loadedMaterial.second) + "kg";


        return invoice;

    }

    void loadMaterial(string name, map <string, int> materialAttribs) {

        loadedMaterials[name] = materialAttribs["amount"];

        actualWeight          += materialAttribs["amount"];

        totalValue            += materialAttribs["price"] * materialAttribs["amount"];

    }

    void addPayload (string materialName, map <string, int> materialAttribs) {

        int loadableWeight = maxWeight - actualWeight;

        if (materialAttribs["amount"] <= loadableWeight)
            loadMaterial(materialName, materialAttribs);

        else {
            materialAttribs["amount"] = loadableWeight;
            loadMaterial(materialName, materialAttribs);
        }

    }
};


#endif //WEEK_1_PAYLOAD_H
