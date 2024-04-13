/**
    Given an array nums with `n` objects colored red, white, or blue, sort them in-place so that objects of the same
    color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    ### Example 1:
    ```
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
    ```

    ### Example 2:
    ```
    Input: nums = [2,0,1]
    Output: [0,1,2]
    ```

    ## Constraints:

    * `n == nums.length`
    * `1 <= n <= 300`
    * `nums[i]` is either `0`, `1`, or `2`.
*/

#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void sortColors(int* nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);
}

int main(int argc, char const *argv[]) {
    int nums[6] = {2, 0, 2, 1, 1, 0};

    sortColors(nums, 6);

    printArray(nums, 6);

    return 0;
}

