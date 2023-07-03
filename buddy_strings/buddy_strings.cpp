/**
 * @brief Given two strings `s` and `goal`, return `true` if you can swap two letters in `s` so the result is equal to
 * `goal`, otherwise, return `false`.
 * 

    Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the
    characters at `s[i]` and `s[j]`.

    For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.
    
    #### Example 1:

    ```
    Input: s = "ab", goal = "ba"
    Output: true
    Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
    ```

    #### Example 2:

    ```
    Input: s = "ab", goal = "ab"
    Output: false
    Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
    ```

    #### Example 3:

    ```
    Input: s = "aa", goal = "aa"
    Output: true
    Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
    ```

    ### Constraints:

    `1 <= s.length, goal.length <= 2 * 10^4`
    `s` and `goal` consist of lowercase letters.
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    bool compareMaps(map<char, int> characters_s, map<char, int> characters_goal) {
        for (auto it = characters_s.begin(); it != characters_s.end(); ++it) {
            if (it->second != characters_goal[it->first]) {
                return false;
            }
        }
        
        return true;
    }
public:
    bool buddyStrings(string s, string goal) {
        map<char, int> characters_s, characters_goal;
        int different_chars = 0;

        if (s.length() == 1) {
            return false;   // You can't swap two letters if there's only one
        }

        if (s.length() != goal.length()) {
            return false;
        }

        if (s.length() == 2 && s == goal) {
            if (s[0] == s[1]) {
                return true;
            }

            return false;   // Swapping characters would make them different from  each other
        }

        for (int i = 0; i < s.length(); i++) {
            if (characters_s.count(s[i])) { // Character already in the map
                characters_s[s[i]]++;
            }
            else {
                characters_s[s[i]] = 1;
            }
        }

        for (int i = 0; i < goal.length(); i++) {
            if (characters_goal.count(goal[i])) { // Character already in the map
                characters_goal[goal[i]]++;
            }
            else {
                characters_goal[goal[i]] = 1;
            }
        }

        if (s == goal) {
            for (auto it = characters_s.begin(); it != characters_s.end(); ++it) {
                // If the same character is present twice
                if (it->second > 1) {
                    return true;
                }
            }

            return false;
        }

        if (!compareMaps(characters_s, characters_goal)) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                // If more than two characters are in different positions, at least two swaps will be needed
                different_chars++;

                if (different_chars > 2) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    if (sol.buddyStrings("abcacaba", "abbacaca")) {
        cout << "Good" << endl;
    }
    else {
        cout << "Bad" << endl;
    }
}
