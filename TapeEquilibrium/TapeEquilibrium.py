'''
    A non-empty array `A` consisting of `N` integers is given. Array `A` represents numbers on a tape.

    Any integer `P`, such that `0 < P < N`, splits this tape into two non-empty parts: `A[0], A[1], ..., A[P - 1] and
    A[P], A[P + 1], ..., A[N - 1]`.

    The difference between the two parts is the value of:
    `|(A[0] + A[1] + ... + A[P - 1]) - (A[P] + A[P + 1] + ... + A[N - 1])|`

    In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

    For example, consider array `A` such that:
    ```
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 4
    A[4] = 3
    ```

    We can split this tape in four places:

    * P = 1, difference = |3 - 10| = 7
    * P = 2, difference = |4 - 9| = 5
    * P = 3, difference = |6 - 7| = 1
    * P = 4, difference = |10 - 3| = 7


    Write a function:
    ```
    def solution(A)
    ```

    that, given a non-empty array `A` of `N` integers, returns the minimal difference that can be achieved.

    For example, given:
    ```
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 4
    A[4] = 3
    ```

    the function should return `1`, as explained above.

    Write an efficient algorithm for the following assumptions:

    * `N` is an integer within the range `[2..100,000]`;
    * Each element of array `A` is an integer within the range `[-1,000..1,000]`.
'''

def difference(A, P):
    '''
    Calculate the absolute difference between the two parts of the array.

    Parameters
    ----------
    A : List
        List with all the elements.
    P : Integer
        Point to divide the list.

    Returns
    -------
    : Integer
        Absolut difference between the two parts of the array.
    '''
    return abs(sum(A[0:P]) - sum(A[P:]))


def solution(A):
    '''
    Calculate the minimal difference that can be achieved.

    Parameters
    ----------
    A : List
        List with all the elements

    Returns
    -------
    : Integer
        Minimal difference.
    '''
    all_diffs = []

    if len(A) == 1:
        return A[0]
    elif len(A) == 2:
        return abs(A[0] - A[1])

    for i in range(1, len(A) + 1):
        last_diff = difference(A, i)

        if last_diff == 0:  # The absolute difference cannot be smaller
            return last_diff

        all_diffs.append(last_diff)

    return min(all_diffs)


tape = [3, 1, 2, 4, 3]

print(solution(tape))
