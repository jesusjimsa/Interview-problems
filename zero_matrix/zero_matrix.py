"""
    Write an algorithm such that if an element in an `M x N` matrix is `0`, its entire row and column are set to `0`.
"""


def zero_matrix(matrix):
    """
    Transform row and column into 0 if there is a 0 in them.

    Parameters
    ----------
    matrix : List
        Matrix to transform.
    """
    zero_pos = []

    for m in range(0, len(matrix)):
        for n in range(0, len(matrix[m])):
            if matrix[m][n] == 0:
                zero_pos.append((m, n))

    for pos in zero_pos:
        for i in range(0, len(matrix)):
            matrix[pos[0]][i] = 0

        for j in range(0, len(matrix[pos[0]])):
            matrix[j][pos[1]] = 0

    return matrix


mat = [[1, 2, 3, 4], [5, 6, 0, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

for elem in mat:
    print(elem)

new_mat = zero_matrix(mat)

print("\n---------------\n")

for elem in new_mat:
    print(elem)
