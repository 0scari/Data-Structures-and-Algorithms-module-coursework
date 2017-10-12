#include <iostream>
#include <array>
#include <vector>
#include <map>

#include "helpers.h"
#include "advanced1.h"
#include "advanced2.h"


int main() {
    string taskNumber;

    cout << "Task 1 or 2?\n-> ";
    cin >> taskNumber;

    if (taskNumber == "1") {

        int lines = 0;

        cout << "How many input lines?\n-> ";
        cin >> lines;

        string result = advanced1(lines);

        cout << result;

    } else if (taskNumber == "2") {

        int maxWeight;

        cout << "How many kg can be carried?\n-> ";
        cin >> maxWeight;

        string result = advanced2(maxWeight);

        cout << result;

    }



}