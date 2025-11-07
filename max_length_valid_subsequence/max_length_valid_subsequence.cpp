/*
    You are given an integer array `nums` and a **positive** integer `k`.
    A subsequence `sub` of `nums` with length `x` is called **valid** if it satisfies:

    * `(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.`

    Return the length of the **longest valid** subsequence of `nums`.


    ## Example 1:
    ```
    Input: nums = [1,2,3,4,5], k = 2

    Output: 5
    ```

    **Explanation:**

    The longest valid subsequence is `[1, 2, 3, 4, 5]`.

    ## Example 2:
    ```
    Input: nums = [1,4,2,3,1,4], k = 3

    Output: 4
    ```

    **Explanation:**

    The longest valid subsequence is `[1, 4, 1, 4]`.

    ## Constraints:

    * `2 <= nums.length <= 10^3`
    * `1 <= nums[i] <= 10^7`
    * `1 <= k <= 10^3`
*/

#include <iostream>

using namespace std;

int myMax(int one, int other) {
    return one > other ? one : other;
}

int countSubsequence(int r1, int r2, const vector<int> &nums, int k) {
    int count = 0;
    int lookingFor = r1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % k == lookingFor) {
            count++;

            // Switch what we're looking for
            if (lookingFor == r1) {
                lookingFor = r2;
            }
            else {
                lookingFor = r1;
            }
        }
    }

    return count;
}

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) {
            return 0;
        }

        if (nums.size() == 1 || nums.size() == 2) {
            return nums.size();
        }

        int maxLength = 0;
        int previousValue = -1;

        for (int target = 0; target < k; target++) {
            for (int r1 = 0; r1 < k; r1++) {
                // Calculate r2 from: (r1 + r2) % k = target
                int r2 = (target - r1 + k) % k;

                int length = countSubsequence(r1, r2, nums, k);

                maxLength = myMax(maxLength, length);
            }
        }

        return maxLength;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {1, 4, 1, 4};
    Solution sol;
    
    cout << "First = " << sol.maximumLength(first, 2) << endl;
    cout << "Second = " << sol.maximumLength(second, 3) << endl;

    return 0;
}
