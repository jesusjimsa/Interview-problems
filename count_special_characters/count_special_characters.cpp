/*
    You are given a string `word`. A letter `c` is called **special** if it appears **both** in lowercase and uppercase
    in `word`, and every lowercase occurrence of `c` appears before the **first** uppercase occurrence of `c`.

    Return the number of **special** letters in `word`.

    ## Example 1:
    ```
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:
    The special characters are 'a', 'b', and 'c'.
    ```

    ## Example 2:
    ```
    Input: word = "abc"
    Output: 0
    Explanation:
    There are no special characters in word.
    ```

    ## Example 3:
    ```
    Input: word = "AbBCab"
    Output: 0
    Explanation:
    There are no special characters in word.
    ```

    ## Constraints:

    * `1 <= word.length <= 2 * 105`
    * `word` consists of only lowercase and uppercase English letters.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    bool check_key(map<char, int> m, char key) {
        // Key is not present
        if (m.find(key) == m.end())
            return false;

        return true;
    }

public:
    int numberOfSpecialChars(string word) {
        map<char, int> first_upper_occurrence;
        map<char, int> last_lower_occurrence;
        set<char> available_letters;
        int special_characters = 0;

        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                last_lower_occurrence[word[i]] = i;
            }
            else if (isupper(word[i]) && !check_key(first_upper_occurrence, tolower(word[i]))) {
                first_upper_occurrence[tolower(word[i])] = i;
            }

            available_letters.insert(tolower(word[i]));
        }

        for (auto itr: available_letters) {
            if (check_key(first_upper_occurrence, itr) &&
                check_key(last_lower_occurrence, itr) &&
                last_lower_occurrence[itr] < first_upper_occurrence[itr]) {
                special_characters++;
            }
        }

        return special_characters;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    cout << sol.numberOfSpecialChars("aaAbcBC") << endl;
    cout << sol.numberOfSpecialChars("abc") << endl;
    cout << sol.numberOfSpecialChars("AbBCab") << endl;

    return 0;
}
