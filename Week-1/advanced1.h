//
// Created by Oskars Pozdnakovs on 11/10/2017.
//

#ifndef WEEK_1_ADVANCED1_H
#define WEEK_1_ADVANCED1_H

unsigned int calcFactorial(unsigned int number) {
    unsigned int tmp;

    if(number <= 1) return 1;

    tmp = number * calcFactorial(number - 1);

    return tmp;
}

map <char, unsigned int> promptToInputLine () {

    unsigned int n, m;

    cout << endl << "n: ";
    cin >> n;

    cout << "m: ";
    cin >> m;

    map<char, unsigned int> output = {{'n', n}, {'m', m}};

    return output;

};

string checkIfDivides(vector<map<char, unsigned int>> input) {

    string output = "";

    for (map<char, unsigned int> entry : input ) {

        string n = to_string(entry['n']);
        string m = to_string(entry['m']);

        cout << "\n" << calcFactorial(entry['n']) % 9;
        cout << "\n" << calcFactorial(entry['n']) % 27;
//        (calcFactorial(entry['n']) %  entry['m'] == 0) ?
//            output += m + " divides " + n + "!\n" :
//                output += m + " does not divide " + n + "!\n";
    }

    return output;
}

string advanced1 (int lines) {

    vector<map<char, unsigned int>> input = {{}};

    for (int i = 0; i < lines; i++)
        input.push_back(promptToInputLine());

//    cout << "dbg";

    return checkIfDivides(input);
}




#endif //WEEK_1_ADVANCED1_H
