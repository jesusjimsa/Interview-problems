/*
    Given an integer `n`, return `true` if it is possible to represent `n` as the sum of distinct powers of three.
    Otherwise, return `false`.

    An integer `y` is a power of three if there exists an integer `x` such that `y == 3^x`.

    ## Example 1:
    ```
    Input: n = 12
    Output: true
    Explanation: 12 = 3^1 + 3^2
    ```

    ## Example 2:
    ```
    Input: n = 91
    Output: true
    Explanation: 91 = 3^0 + 3^2 + 3^4
    ```

    ## Example 3:
    ```
    Input: n = 21
    Output: false
    ```

    ## Constraints:

    * `1 <= n <= 10^7`
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }

            n /= 3;
        }

        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    if (sol.checkPowersOfThree(12)) {
        cout << "12 is good" << endl;
    }
    else {
        cout << "12 is not good" << endl;
    }

    if (sol.checkPowersOfThree(91)) {
        cout << "91 is good" << endl;
    }
    else {
        cout << "91 is not good" << endl;
    }

    if (sol.checkPowersOfThree(21)) {
        cout << "21 is good" << endl;
    }
    else {
        cout << "21 is not good" << endl;
    }

    return 0;
}
