//
// Created by Oskars Pozdnakovs on 11/10/2017.
//

#ifndef WEEK_1_ADVANCED1_H
#define WEEK_1_ADVANCED1_H

/**
 * 1. When the advanced1(i) function is called, it will call the function prompt for input,
 * which will deliver values for n and m variables, i times.
 *
 * 2. The delivered values will be appended to a vector which thereafter is passed to the function's
 * checkIfDivides(vector) parameter. Afterwards we calculate the factorial for an n value
 * and check weather or not divided by zero it has a reminder. Based on the output, a corresponding
 * string, that describes the outcome, will be prepared for each n and m pair and returned.
 *
 */

long unsigned int calcFactorial(long unsigned int number) {
    long unsigned int tmp;

    if(number <= 1) return 1;

    tmp = number * calcFactorial(number - 1);

    return tmp;
}

map <char, long unsigned int> promptToInputLine () {

    long unsigned int n, m;

    cout << endl << "n: ";
    cin >> n;

    cout << "m: ";
    cin >> m;

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

string advanced1 (int lines) {

    vector<map<char, long unsigned int>> input = {};

    for (int i = 0; i < lines; i++)
        input.push_back(promptToInputLine());

    return checkIfDivides(input);
}




#endif //WEEK_1_ADVANCED1_H
