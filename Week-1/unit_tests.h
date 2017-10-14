//
// Created by Oskars Pozdnakovs on 13/10/2017.
//

#ifndef WEEK_1_UNIT_TESTS_H
#define WEEK_1_UNIT_TESTS_H

const int MAX_LORRY_WEIGHT = 9;

void task1UT() {

    vector<map<char, long unsigned int>> testInput = {
            {{'n', 6}, {'m', 9}},
            {{'n', 6}, {'m', 27}},
            {{'n', 20}, {'m', 10000}},
            {{'n', 20}, {'m', 100000}},
    };

    checkIfDivides(testInput) ==
        "9 divides 6!\n27 does not divide 6!\n10000 divides 20!\n100000 does not divide 20!\n" ?
            cout << "Task-1 UNIT TEST SUCCESSFUL\n" :
                cout << "Task-1 !! UNIT TEST FAILED\n";

}

/**
 * Warehouse tests to test the searching algorithm that seeks the most expensive material in stock.
 *
 * @param expectedOutput1
 * @param expectedOutput2
 * @param warehouse
 */
void task2WHTests(map<string, map<string, int>> expectedOutput1,
                  map<string, map<string, int>> expectedOutput2,
                  Warehouse warehouse) {

    bool testsOK = true;

    cout << "Task-2 WAREHOUSE TESTS STARTED\n";

    // 1
    if (warehouse.getMostExpensiveMaterial() != expectedOutput1) {
        cout << "WH Test1 failed\n";
        testsOK = false;
    };

    // 2
    if (warehouse.getMostExpensiveMaterial() != expectedOutput2) {
        cout << "WH Test2 failed\n";
        testsOK = false;
    };

    if (testsOK)
        cout << "Task-2 WAREHOUSE UNIT TESTS SUCCESSFUL\n";



}

/**
 * Testing the class Lorry for material loading by the way of ensuring the member attributes have
 * taken the appropriate value.
 *
 * @param input1
 * @param input2
 * @param lorry
 */
void task2LorryTests (map<string, map<string, int>> input1,
                      map<string, map<string, int>> input2,
                      Lorry lorry) {
    bool testsOK = true;

    /* LORRY TESTS */
    cout << "Task-2 LORRY TESTS STARTED\n";

    // LOAD 1

    string material1; // Material's name

    // Extracting the key
    for (auto payload : input1)
        material1 = payload.first;

    lorry.addPayload(material1, input1[material1]);

    if (lorry.getActualWeight() != input1[material1]["amount"]) {
        cout << "lorry Test1 failed\n";
        testsOK = false;
    }

    if (lorry.getTotalValue() != input1[material1]["price"] * input1[material1]["amount"]) {
        cout << "lorry Test2 failed\n";
        testsOK = false;
    }

    if (lorry.getLoadedMaterials().size() != 1) {
        cout << "lorry Test3 failed\n";
        testsOK = false;
    }

    // LOAD 2

    string material2;

    for (auto payload : input2)
        material2 = payload.first;

    lorry.addPayload(material2, input2[material2]);

    if (lorry.getActualWeight() != MAX_LORRY_WEIGHT) {
        cout << "lorry Test4 failed\n" << lorry.getActualWeight();
        testsOK = false;
    }

    // Calculating how much of material 2 could have been loaded
    // X = M2.amount - (M1.amount + M2.amount - max_weight)
    int loadedMaterial2Amount = input2[material2]["amount"]
                                - (input1[material1]["amount"]
                                   + input2[material2]["amount"]
                                   - MAX_LORRY_WEIGHT);

    int totalValue = input1[material1]["price"] * input1[material1]["amount"]
                     + loadedMaterial2Amount * input2[material2]["price"];

    if (lorry.getTotalValue() != totalValue) {
        cout << "lorry Test5 failed\n";
        testsOK = false;
    }

    if (lorry.getLoadedMaterials().size() != 2) {
        cout << "lorry Test6 failed\n";
        testsOK = false;
    }

    if (testsOK)
        cout << "Task-2 LORRY UNIT TESTS SUCCESSFUL\n";

}

void runUnitTests() {

    task1UT();

    Lorry      lorry(MAX_LORRY_WEIGHT);
    Warehouse  warehouse;

    map <string, map <string, int>> testsData1 = {{"gold", {{"amount", 7}, {"price", 10}}}};
    map <string, map <string, int>> testsData2 = {{"silver", {{"amount", 5}, {"price", 7}}}};

    task2WHTests(testsData1, testsData2, warehouse);

    task2LorryTests(testsData1, testsData2, lorry);

}

#endif //WEEK_1_UNIT_TESTS_H
