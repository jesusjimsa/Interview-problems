/*
    Implement an algorithm to determine if a string has all unique characters. What if you cannot use aditiobal data
    structures?
*/

#include <iostream>
#include <string>

using namespace std;

bool allUnique(string characters) {
    bool solution = true;

    for (int i = 0; i < characters.length() && solution; i++) {
        for (int j = i + 1; j < characters.length() && solution; j++) {
            if (characters[i] == characters[j]) {
                solution = false;
            }
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
