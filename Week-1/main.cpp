#include <iostream>
#include <array>
#include <vector>
#include <map>

using namespace std;

#include "advanced1.h"
#include "Lorry.h"
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

        cout << "How many kg can a lorry carry?\n-> ";

        cin >> maxWeight;

        Lorry lorry(maxWeight);

        string invoice = advanced2(lorry);

        cout << invoice;

    }



}