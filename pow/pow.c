/**
    Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `x^n`).

    ### Example 1:
    ```
    Input: x = 2.00000, n = 10
    Output: 1024.00000
    ```

    ### Example 2:
    ```
    Input: x = 2.10000, n = 3
    Output: 9.26100
    ```

    ### Example 3:
    ```
    Input: x = 2.00000, n = -2
    Output: 0.25000
    ```

    Explanation: 2^(-2) = 1/(2^2) = 1/4 = 0.25


    Constraints:

    * `-100.0 < x < 100.0`
    * `-2^31 <= n <= 2^31 - 1`
    * `n` is an integer.
    * Either `x` is not zero or `n > 0`.
    * `-10^4 <= x^n <= 10^4`
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double myPow(double x, int n) {
    double solution = x;
    int power = 0;
    int i = 0;

    if (x == 1.000) {
        return 1.000;
    }

    power = n > 0 ? n : -n;

    for (i = 1; i < power; i++) {
        solution *= x;
    }

    if (n < 0) {
        solution = 1 / solution;
    }

    if (n == 0) {
        return 1;
    }

    return solution;
}

int main(int argc, char const *argv[]) {
    printf("%f\n", myPow(2.0000000, 10));
    printf("%f\n", myPow(2.1000000, 3));
    printf("%f\n", myPow(2.0000000, -2));
    printf("%f\n", myPow(1.00000, 2147483647));

    return 0;
}

