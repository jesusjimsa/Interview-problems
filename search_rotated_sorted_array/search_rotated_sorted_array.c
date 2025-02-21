/*
    There is an integer array `nums` sorted in ascending order (with **distinct** values).

    Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k`
    (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1],
    ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become
    `[4,5,6,7,0,1,2]`.

    Given the array `nums` **after** the possible rotation and an integer `target`, return the *index* of `target` if it
    is in `nums`, or `-1` if it is not in `nums`.

    You must write an algorithm with `O(log n)` runtime complexity.

    ## Example 1:
    ```
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    ```

    ## Example 2:
    ```
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
    ```

    ## Example 3:
    ```
    Input: nums = [1], target = 0
    Output: -1
    ```

    ## Constraints:

    * `1 <= nums.length <= 5000`
    * `-10^4 <= nums[i] <= 10^4`
    * All values of `nums` are **unique**.
    * `nums` is an ascending array that is possibly rotated.
    * `-10^4 <= target <= 10^4`
*/

#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[low] <= nums[mid]) {   // The left side is sorted
            if (nums[low] <= target && target < nums[mid]) { // The target is inside this half
                high = mid - 1;
            }
            else {  // The target is in the other half
                low = mid + 1;
            }
        }
        else {  // The right side is sorted
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    int numsSize = 7;
    int *nums = (int *)malloc(numsSize * sizeof(int));

    nums[0] = 4;
    nums[1] = 5;
    nums[2] = 6;
    nums[3] = 7;
    nums[4] = 0;
    nums[5] = 1;
    nums[6] = 2;

    printf("Target %d is at index %d\n", 0, search(nums, numsSize, 0));
    printf("Target %d is at index %d\n", 3, search(nums, numsSize, 3));

    free(nums);

    numsSize = 1;
    nums = (int *)malloc(numsSize * sizeof(int));

    nums[0] = 1;

    printf("Target %d is at index %d\n", 0, search(nums, numsSize, 0));

    free(nums);

    return 0;
}
