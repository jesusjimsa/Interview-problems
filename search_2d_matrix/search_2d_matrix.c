/*
    Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix matrix. This matrix has
    the following properties:

    * Integers in each row are sorted in ascending from left to right.
    * Integers in each column are sorted in ascending from top to bottom.

    ## Example 1

    ```
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true
    ```

    ## Example 2

    ```
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false
    ```

    ## Constraints:

    * `m == matrix.length`
    * `n == matrix[i].length`
    * `1 <= n, m <= 300`
    * `-10^9 <= matrix[i][j] <= 10^9`
    * All the integers in each row are sorted in ascending order.
    * All the integers in each column are sorted in ascending order.
    * `-10^9 <= target <= 10^9`
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = 0;
    int column = 0;

    while (matrix[row][column] <= target) {
        bool size_columns = column + 1 < matrixColSize[0];

        if (matrix[row][column] == target) {
            return true;
        }

        if (size_columns && matrix[row][column+1] > target) {
            break;
        }

        if (size_columns) {
            column++;
        }
        else {
            break;
        }
    }

    while (matrix[row][column] <= target) {
        if (matrix[row][column] == target) {
            return true;
        }

        if (row + 1 < matrixSize) {
            row++;
        }
        else {
            break;
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {
    int rows = 5;
    int cols = 5;

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with the given values
    int values[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = values[i][j];
        }
    }

    if (searchMatrix(matrix, rows, &cols, 5)) {
        printf("Found\n");
    }
    else {
        printf("Not found\n");
    }

    return 0;
}
