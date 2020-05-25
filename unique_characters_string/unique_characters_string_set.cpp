/*
    Implement an algorithm to determine if a string has all unique characters. What if you cannot use aditiobal data
    structures?
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

bool allUnique(string characters) {
    bool solution = true;
    set<char> uniques;
    int last_length = 0;

    for (int i = 0; i < characters.length() && solution; i++) {
        uniques.insert(characters[i]);

        if (uniques.size() > last_length) {
            last_length = uniques.size();
        }
        else {
            solution = false;
        }
    }

    return solution;
}

int main (int argc, char **argv) {
    string example = "abcdefghijk";

    if (argc > 1) {
        example = argv[1];
    }

    if (allUnique(example)) {
        cout << "All characters are unique" << endl;
    }
    else {
        cout << "There are repeated characters" << endl;
    }
}
