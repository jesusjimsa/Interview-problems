/*
    A string is **good** if there are no repeated characters.

    Given a string `s`​​​​​, return the number of **good substrings** of length **three** in `s​​​​​​`.

    Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

    A **substring** is a contiguous sequence of characters in a string.

    ## Example 1:
    ```
    Input: s = "xyzzaz"
    Output: 1
    Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
    The only good substring of length 3 is "xyz".
    ```

    ## Example 2:
    ```
    Input: s = "aababcabc"
    Output: 4
    Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
    The good substrings are "abc", "bca", "cab", and "abc".
    ```

    ## Constraints:

    * `1 <= s.length <= 100`
    * `s`​​​​​​ consists of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int good_substrings = 0;

        if (s.length() < 3) {
            return 0;
        }

        for (int i = 2; i < s.length(); i++) {
            set<char> substring_chars;

            substring_chars.insert(s[i - 2]);
            substring_chars.insert(s[i - 1]);
            substring_chars.insert(s[i]);

            if (substring_chars.size() == 3) {
                good_substrings++;
            }
        }

        return good_substrings;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    string first = "xyzzaz";
    string second = "aababcabc";

    cout << first << ": " << sol.countGoodSubstrings(first) << endl;
    cout << second << ": " << sol.countGoodSubstrings(second) << endl;

    return 0;
}
