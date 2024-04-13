/*
    There is a robot on an `m x n` grid. The robot is initially located at the **top-left** corner (i.e., `grid[0][0]`).
    The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either
    down or right at any point in time.

    Given the two integers `m` and `n`, return _the number of possible unique paths that the robot can take to reach the
    bottom-right corner_.

    The test cases are generated so that the answer will be less than or equal to `2 * 109`.

    #### Example 1:

    ![Robot image](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

    > **Input:** `m = 3, n = 7`
    > **Output:** `28`


    #### Example 2:

    > **Input:** `m = 3, n = 2`
    > **Output:** `3`
    > **Explanation:** `From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:`
    > 1. `Right -> Down -> Down`
    > 2. `Down -> Down -> Right`
    > 3. `Down -> Right -> Down`


    #### Constraints:

    * `1 <= m, n <= 100`
*/

#include <stdio.h>

long double factorial(long double number) {
    long double result = 1;
    int i = 1;

    for (i = 1; i <= number; ++i) {
        result = result * i;
    }

    return result;
}

int uniquePaths(int m, int n) {
    return factorial(m + n - 2) / (factorial(m - 1) * factorial(n - 1));
}

int main(int argc, char const *argv[]) {
    int m = 19;
    int n = 13;

    printf("Results for m = %d; n = %d: %d\n", m, n, uniquePaths(m, n));

    return 0;
}

