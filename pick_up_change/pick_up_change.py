"""
    Given a 2D `n x m` matrix where each cell has a certain amount of change on the floor, your goal is to start from
    the top left corner `mat[0][0]` and end in the bottom right corner `mat[n - 1][m - 1]` with the most amount of
    change. You can only move either right or down.
"""


def max_change(matrix):
    """
        Return maximum change that can be picked up from the matrix.

        Parameters
        ----------
        mat : List(List())
            Positions of the coins.
    """
    result = 0
    n = 0
    m = 0

    while n < len(matrix) and m < len(matrix[0]):
        result += matrix[n][m]

        if n >= len(matrix):
            m += 1
            continue

        if m >= len(matrix[0]):
            n += 1
            continue

        if matrix[n + 1][m] > matrix[n][m + 1]:
            n += 1
        else:
            m += 1

    return result


mat = [
    [0, 3, 0, 2],
    [1, 2, 3, 3],
    [6, 0, 3, 2]
]

print(max_change(mat))
# 13
