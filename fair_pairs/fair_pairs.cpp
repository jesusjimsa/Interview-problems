/*
    Given a **0-indexed** integer array `nums` of size `n` and two integers `lower` and `upper`, return *the number of
    fair pairs*.

    A pair `(i, j)` is **fair** if:

    * `0 <= i < j < n, and`
    * `lower <= nums[i] + nums[j] <= upper`

    ## Example 1:
    ```
    Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
    Output: 6
    Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
    ```

    ## Example 2:
    ```
    Input: nums = [1,7,9,2,5], lower = 11, upper = 11
    Output: 1
    Explanation: There is a single fair pair: (2,3).
    ```

    ## Constraints:

    * `1 <= nums.length <= 10^5`
    * `nums.length == n`
    * `-10^9 <= nums[i] <= 10^9`
    * `-10^9 <= lower <= upper <= 10^9`
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long fair_pairs = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long sum = nums[i] + nums[j];

                if (lower <= sum && sum <= upper) {
                    fair_pairs++;
                }
                else if (sum > upper) {
                    break;  // No need to check further j's
                }
            }
        }

        return fair_pairs;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> one = {0, 1, 7, 4, 4, 5};
    vector<int> two = {1, 7, 9, 2, 5};
    vector<int> three = {-5, -7, -5, -7, -5};

    cout << "There are " << sol.countFairPairs(one, 3, 6) << " fair pairs in vector 'one'" << endl;
    cout << "There are " << sol.countFairPairs(two, 11, 11) << " fair pairs in vector 'two'" << endl;
    cout << "There are " << sol.countFairPairs(three, -12, -12) << " fair pairs in vector 'three'" << endl;

    return 0;
}
