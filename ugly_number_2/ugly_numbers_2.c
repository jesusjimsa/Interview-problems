/**
    An ugly number is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

    Given an integer `n`, return the `n^th` ugly number.

    ### Example 1:
    ```
    Input: n = 10
    Output: 12
    Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
    ```

    ### Example 2:
    ```
    Input: n = 1
    Output: 1
    Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
    ```

    ## Constraints:

    * `1 <= n <= 1690`
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUgly(int n) {
    // The number is 1 or one of the prime numbers
    if (n == 1 || n == 2 || n == 3 || n == 5) {
        return true;
    }

    if (n <= 0) {
        return false;
    }

    if (n % 2 == 0) {
        return isUgly(n / 2);
    }

    if (n % 3 == 0) {
        return isUgly(n / 3);
    }

    if (n % 5 == 0) {
        return isUgly(n / 5);
    }

    return false;
}

int nthUglyNumber(int n) {
    int count = 0;
    int num = 0;

    while (count != n) {
        num++;

        if (isUgly(num)) {
            count++;
        }
    }

    return num;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", nthUglyNumber(10));
    printf("%d\n", nthUglyNumber(1));
    printf("%d\n", nthUglyNumber(1352));

    return 0;
}
