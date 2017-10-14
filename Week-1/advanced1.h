//
// Created by Oskars Pozdnakovs on 11/10/2017.
//

#ifndef WEEK_1_ADVANCED1_H
#define WEEK_1_ADVANCED1_H

/**
 * 1. When the advanced1(i) function is called, it will call the function promptToInputLine(),
 * which will deliver values for n and m variables, i times.
 *
 * 2. The delivered values will be appended to a vector which thereafter is passed to the function's
 * checkIfDivides(vector) parameter. Afterwards we calculate the factorial for an n value
 * and check weather or not divided by a zero it has a reminder. Based on the output, a corresponding
 * string that describes the outcome will be prepared for each n and m pair and returned.
 *
 */

long unsigned int calcFactorial(long unsigned int number) {

    long unsigned int sum;

    if(number <= 1) return 1;

    sum = number * calcFactorial(number - 1);

    return sum;
}

map <char, long unsigned int> promptToInputLine () {

    cout << endl << "n: ";
    long unsigned int n = getIntInput();

    cout << "m: ";
    long unsigned int m = getIntInput();

    map<char, long unsigned int> output = {{'n', n}, {'m', m}};

    return output;

};

string checkIfDivides(vector<map<char, long unsigned int>> input) {

    string output = "";

    for (map<char, long unsigned int> entry : input ) {

        string n = to_string(entry['n']);
        string m = to_string(entry['m']);

        (calcFactorial(entry['n']) %  entry['m'] == 0) ?
            output += m + " divides " + n + "!\n" :
                output += m + " does not divide " + n + "!\n";
    }

    return output;
}

/**
 * High level logic for the first task.
 *
 * @param lines quantity of m and n pairs that need to be input
 *
 * @return
 */
string advanced1 (int lines) {

    // ['m': N, 'n': N]
    vector<map<char, long unsigned int>> userInput = {};

    for (int i = 0; i < lines; i++)
        userInput.push_back(promptToInputLine());

    return checkIfDivides(userInput);
}




#endif //WEEK_1_ADVANCED1_H
