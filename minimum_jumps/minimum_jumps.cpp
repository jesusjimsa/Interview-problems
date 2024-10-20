/*
    A certain bug's home is on the x-axis at position `x`. Help them get there from position `0`.

    The bug jumps according to the following rules:

    * It can jump exactly `a` positions **forward** (to the right).
    * It can jump exactly `b` positions **backward** (to the left).
    * It cannot jump backward twice in a row.
    * It cannot jump to any `forbidden` positions.

    The bug may jump forward **beyond** its home, but it **cannot jump** to positions numbered with **negative**
    integers.

    Given an array of integers `forbidden`, where `forbidden[i]` means that the bug cannot jump to the position
    `forbidden[i]`, and integers `a`, `b`, and `x`, return the *minimum number of jumps needed for the bug to reach
    its home*. If there is no possible sequence of jumps that lands the bug on position `x`, return `-1`.

    ## Example 1:
    ```
    Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
    Output: 3
    Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
    ```

    ## Example 2:
    ```
    Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
    Output: -1
    ```

    ## Example 3:
    ```
    Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
    Output: 2
    Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) will get the bug home.
    ```

    ## Constraints:

    * `1 <= forbidden.length <= 1000`
    * `1 <= a, b, forbidden[i] <= 2000`
    * `0 <= x <= 2000`
    * All the elements in `forbidden` are distinct.
    * Position `x` is not forbidden.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool is_forbidden(vector<int>& forbidden, int position) {
        return find(forbidden.begin(), forbidden.end(), position) != forbidden.end();
    }

public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        bool last_was_backward = false;
        int current_position = 0;
        int num_jumps = 0;
        
        while (current_position != x) {
            if (current_position < x && !is_forbidden(forbidden, current_position + a)) {
                current_position += a;
                num_jumps++;
                last_was_backward = false;
            }
            else if (!last_was_backward &&
                     current_position - b >= 0 &&
                     !is_forbidden(forbidden, current_position - b)) {
                current_position -= b;
                num_jumps++;
                last_was_backward = true;
            }
            else {
                return -1;
            }
        }

        return num_jumps;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> test1 = {14, 4, 18, 1, 15};
    vector<int> test2 = {8, 3, 16, 6, 12, 20};
    vector<int> test3 = {1, 6, 2, 14, 5, 17, 4};

    cout << "Test 1: " << sol.minimumJumps(test1, 3, 15, 9) << endl;
    cout << "Test 1: " << sol.minimumJumps(test2, 15, 13, 11) << endl;
    cout << "Test 1: " << sol.minimumJumps(test3, 16, 9, 7) << endl;

    return 0;
}
