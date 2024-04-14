/**
    Given an integer `n`, return a string array `answer` (1-indexed) where:

    * `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
    * `answer[i] == "Fizz"` if `i` is divisible by `3`.
    * `answer[i] == "Buzz"` if `i` is divisible by `5`.
    * `answer[i] == i` (as a string) if none of the above conditions are true.

    ### Example 1:
    ```
    Input: n = 3
    Output: ["1","2","Fizz"]
    ```

    ### Example 2:
    ```
    Input: n = 5
    Output: ["1","2","Fizz","4","Buzz"]
    ```

    ### Example 3:
    ```
    Input: n = 15
    Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
    ```

    ## Constraints:

    * `1 <= n <= 10^4`
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIZZ        "Fizz"
#define BUZZ        "Buzz"
#define FIZZBUZZ    "FizzBuzz"
#define MAX_VALUE   "10000"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **solution = (char**)malloc(sizeof(char*) * n);
    int i = 0;

    if (solution == NULL) {
        printf("Failed to allocate memory\n");
        return NULL;
    }

    for (i = 1; i <= n; i++) {
        solution[i - 1] = (char*)malloc(sizeof(char) * strlen(FIZZBUZZ) + 1);
        snprintf(solution[i - 1], 1, "");

        if (i % 3 != 0 && i % 5 != 0) {
            snprintf(solution[i - 1], strlen(MAX_VALUE), "%d", i);
        }
        else {
            if (i % 3 == 0) {
                // snprintf(solution[i - 1], strlen(FIZZBUZZ) + 1, FIZZ);
                strcat(solution[i - 1], FIZZ);
            }

            if (i % 5 == 0) {
                // snprintf(solution[i - 1], strlen(FIZZBUZZ) + 1, "%s%s", solution[i - 1], BUZZ);
                strcat(solution[i - 1], BUZZ);
            }
        }
    }

    *returnSize = i - 1;

    return solution;
}

int main(int argc, char const *argv[]) {
    int arr_size = 0;
    int i = 0;
    char **test = fizzBuzz(15, &arr_size);

    for (i = 0; i < arr_size; i++) {
        printf("%s ", test[i]);
    }

    printf("\n");

    for (i = 0; i < arr_size; i++) {
        if (test[i]) {
            free(test[i]);
        }
    }

    free(test);

    return 0;
}

