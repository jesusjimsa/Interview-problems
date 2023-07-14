/**
 * @brief Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they
 * add up to `target`_.
 * 

    You may assume that each input would have **_exactly_ one solution**, and you may not use the same element twice.

    You can return the answer in any order.

    #### Example 1:

    ```
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    ```

    #### Example 2:

    ```
    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    ```

    #### Example 3:

    ```
    Input: nums = [3,3], target = 6
    Output: [0,1]
    ```

    ### Constraints:

    * `2 <= nums.length <= 104`
    * `-109 <= nums[i] <= 109`
    * `-109 <= target <= 109`
    * **Only one valid answer exists.**

 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums, result;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    // nums.push_back(15);

    result = sol.twoSum(nums, 6);

    cout << "["<< result[0] << ", " << result[1] << "]" << endl;
}
