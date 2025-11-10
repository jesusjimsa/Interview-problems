/*
    Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to*
    `k`.

    A subarray is a contiguous **non-empty** sequence of elements within an array.

    ## Example 1:
    ```
    Input: nums = [1,1,1], k = 2
    Output: 2
    ```

    ## Example 2:
    ```
    Input: nums = [1,2,3], k = 3
    Output: 2
    ```

    ## Constraints:

    * `1 <= nums.length <= 2 * 10^4`
    * `-1000 <= nums[i] <= 1000`
    * `-10^7 <= k <= 10^7`
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            if (nums[0] == k) {
                return 1;
            }
            else {
                return 0;
            }
        }

        // sum(i, j) = sum(0, j) - sum(0, i)
        // vector = sum(0, nums.size())
        // vector[j] - vector[i]; vector[j] - vector[i-1,2,3,4......0]
        // vector[j-1] - vector[i-1].......

        vector<int> partial_sums;

        partial_sums.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            partial_sums.push_back(partial_sums[i] + nums[i]);
        }

        int result = 0;

        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if ((partial_sums[end] - partial_sums[start]) == k) {
                    result++;
                }
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> one = {1, 1, 1};
    vector<int> two = {1, 2, 3};

    cout << "Vector 'one' has " << sol.subarraySum(one, 2) << endl;
    cout << "Vector 'two' has " << sol.subarraySum(two, 3) << endl;

    return 0;
}
