/*
    Given an integer array `nums` sorted in **non-decreasing** order, return an array of **the squares of each number**
    sorted in non-decreasing order.

    ## Example 1:
    ```
    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].
    ```

    ## Example 2:
    ```
    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]
    ```

    ## Constraints:

    * `1 <= nums.length <= 10^4`
    * `-10^4 <= nums[i] <= 10^4`
    * `nums` is sorted in non-decreasing order.
*/

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int *solution = (int*)malloc(numsSize * sizeof(int));

    if (!solution) {
        return NULL;
    }

    *returnSize = numsSize;

    for (i = 0; i < numsSize; i++) {
        solution[i] = nums[i] * nums[i];
    }

    qsort(solution, *returnSize, sizeof(int), comp);

    return solution;
}

int* sortedSquaresFast(int* nums, int numsSize, int* returnSize) {
    int *solution = (int*)malloc(numsSize * sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    int pos = numsSize - 1;

    if (!solution) {
        return NULL;
    }

    *returnSize = numsSize;

    while (left <= right) {
        int left_square = nums[left] * nums[left];
        int right_square = nums[right] * nums[right];

        if (left_square > right_square) {
            solution[pos] = left_square;
            left++;
        }
        else {
            solution[pos] = right_square;
            right--;
        }

        pos--;
    }

    return solution;
}

int main(int argc, char const *argv[]) {
    int nums[] = {-4 ,-1, 0, 3, 10};
    int sol_size = 0;
    int *sol = sortedSquares(nums, sizeof(nums)/sizeof(nums[0]), &sol_size);
    int *sol_fast = sortedSquaresFast(nums, sizeof(nums)/sizeof(nums[0]), &sol_size);
    int i = 0;

    for (i = 0; i < sol_size; i++) {
        printf("%d, ", sol[i]);
    }

    printf("\n");

    for (i = 0; i < sol_size; i++) {
        printf("%d, ", sol_fast[i]);
    }

    printf("\n");

    free(sol);
    free(sol_fast);

    return 0;
}
