'''
    Write a function:
    ```
    def solution(A)
    ```

    that, given an array `A` of `N` integers, returns the smallest positive integer (greater than `0`) that does not
    occur in `A`.

    For example, given `A = [1, 3, 6, 4, 1, 2]`, the function should return `5`.

    Given `A = [1, 2, 3]`, the function should return `4`.

    Given `A = [-1, -3]`, the function should return `1`.

    Write an efficient algorithm for the following assumptions:

    * `N` is an integer within the range `[1..100,000]`;
    * Each element of array `A` is an integer within the range `[-1,000,000..1,000,000]`.
'''


def solution(A):
    '''
    Return the smallest possible integer that does not occur in A.

    Parameters
    ----------
    A : List
        Array of integers.
    Returns
    -------
    minimum : Integer
        Smallest possible integer that does not occur in A.
    '''
    minimum = 1

    A.sort()

    for elem in A:
        if elem == minimum:
            minimum += 1

    return minimum


uno = [1, 3, 6, 4, 1, 2]
dos = [1, 2, 3]
tres = [-1, -3]

cuatro = list()

for i in range(1, 100001):
    cuatro.append(i)

cuatro.remove(99999)

print(solution(uno))
print(solution(dos))
print(solution(tres))

print(solution(cuatro))
