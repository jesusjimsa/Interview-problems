/*
Imagine you are building a compiler. Before running any code, the compiler must check that the parentheses in the
program are balanced. Every opening bracket must have a corresponding closing bracket. We can approximate this using
strings.

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Note that an empty string is also considered valid.

Example:
    Input: "((()))"
    Output: True

    Input: "[()]{}"
    Output: True

    Input: "({[)]"
    Output: False
*/

#include <iostream>
#include <string>

using namespace std;

bool isValid(string s){
    int parenthesis = 0;
    int curly = 0;
    int square = 0;

    if (s.empty()) {
        return true;
    }

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(':
                parenthesis++;
                break;
            case ')':
                parenthesis--;

                if (parenthesis == -1) {
                    return false;
                }

                break;
            case '{':
                curly++;
                break;
            case '}':
                curly--;

                if (curly == -1) {
                    return false;
                }

                break;
            case '[':
                square++;
                break;
            case ']':
                square--;

                if (square == -1) {
                    return false;
                }

                break;
            default:
                continue;
        }
    }

    if (parenthesis != 0 || curly != 0 || square != 0) {
        return false;
    }

    return true;
}

int main(int argc, char **argv) {
    string s;

    s = "()(){(())";    // Should return false
    cout << (isValid(s) ? "true" : "false") << endl;

    s = "";     // Should return true
    cout << (isValid(s) ? "true" : "false") << endl;

    s = "([{}])()";     // Should return true
    cout << (isValid(s) ? "true" : "false") << endl;

    return 0;
}
