#include <iostream>
#include <array>
#include <vector>
#include <map>

using namespace std;

/**
 * A function for robust int input
 * @return
 */
long unsigned int getIntInput () {

    long unsigned int userInput;

    do {

        cin >> userInput;

        if (cin.fail()) {

            //something went wrong, we reset the buffer's state
            cin.clear();
            //remove a lot of chars until a newline from the buffer
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Non integer input, try again\n\n->";

        }

        else
            break;

    } while (true);

    return userInput;
}

#include "advanced1.h"
#include "Lorry.h"
#include "Warehouse.h"
#include "advanced2.h"

int main() {

    string userInput;

    cout << "[1]: Task-1, [2]: Task-2, \"[ut]\": run unit tests\n-> ";

    cin >> userInput;

    if (userInput == "1") {

        cout << "How many input lines?\n-> ";

        int lines = getIntInput();

        string result = advanced1(lines);

        cout << result;

    } else if (userInput == "2") {


        cout << "How many kg can the lorry carry?\n-> ";

        int maxWeight = getIntInput();

        Lorry lorry(maxWeight);
        Warehouse warehouse;

        string invoice = advanced2(lorry, warehouse);

        cout << invoice;

    } else if (userInput == "ut")



}