/*
    You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and
    increment `nums[i]` by `1`.

    Return the minimum number of moves to make every value in `nums` **unique**.

    The test cases are generated so that the answer fits in a 32-bit integer.
*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* nums, int numsSize) {
    int i = 0;
    int increments = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (i = 1; i < numsSize; i++) {
        /*
            The following solution works, however, it takes too long when the array is very big with very big numbers.
            the solution inside this comment would fix it:
                int diff = nums[i - 1] - nums[i] + 1;
                nums[i] += diff;
                increments += diff;
        */
        if (nums[i] <= nums[i - 1]) {
            nums[i]++;
            increments++;
            i--;    // We check again in case we need more increments with this number
        }
    }

    return increments;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3, 2, 1, 2, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Min increment for unique array: %d\n", minIncrementForUnique(arr, size));

    return 0;
}
