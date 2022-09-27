"""
    We are given a matrix M of the order m x n, and we have to print its elements as we traverse it in spiral form.

    Example:


    matrix = [
        [13, 14, 17, 27],
        [81, 52, 31, 10],
        [12, 55, 23, 78]
    ]

    Output: [13, 14, 17, 27, 10, 78, 23, 55, 12, 81, 52, 31]

    TODO: This is the solution I presented in the interview. It can be improved because this solutiooon would only work
    with a matrix of the same dimensions as the given ones. It should work with every type of matrix.
"""

three_by_three = [
   [1, 2, 3],
   [4, 5, 6],
   [7, 8, 9],
]

five_by_two = [
    [1, 2, 3, 4, 5],
    [6, 7, 8, 9, 10]
]

one_by_five = [
    [1],
    [2],
    [3],
    [4],
    [5],
]


def spiral_order(matrix):
    """
        Transform matrix into liist inn spiral order.

        Parameters
        ----------
        matrix : List(List())
            Matrix to be transformed to spiral form.
    """
    result = []
    reversed_last_row = matrix[-1]
    reversed_matrix = list(matrix)
    saved_i = 0

    reversed_last_row.reverse()
    reversed_matrix.reverse()

    for elem in matrix[0]:
        result.append(elem)

    result.pop()

    for elem in matrix:
        result.append(elem[-1])

    if len(matrix[-1]) > 1:
        result.pop()

        for elem in reversed_last_row:
            result.append(elem)

        if len(matrix) > 2:
            for i in range(1, len(matrix) - 1):
                result.append(reversed_matrix[i][0])
                saved_i = i

            result.append(matrix[saved_i][1])

    return result


print(spiral_order(three_by_three))
# [1, 2, 3, 6, 9, 8, 7, 4, 5]

print(spiral_order(five_by_two))
# [1, 2, 3, 4, 5, 10, 9, 8, 7, 6]

print(spiral_order(one_by_five))
# [1, 2, 3, 4, 5]
