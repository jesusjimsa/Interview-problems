'''
    A non-empty array `A` consisting of `N` integers is given. The consecutive elements of array `A` represent
    consecutive cars on a road.

    Array `A` contains only 0s and/or 1s:

    * `0` represents a car traveling east,
    * `1` represents a car traveling west.

    The goal is to count passing cars. We say that a pair of cars `(P, Q)`, where `0 ≤ P < Q < N`, is passing when `P`
    is traveling to the east and `Q` is traveling to the west.

    For example, consider array `A` such that:
    ```
    A[0] = 0
    A[1] = 1
    A[2] = 0
    A[3] = 1
    A[4] = 1
    ```

    We have five pairs of passing cars: `(0, 1)`, `(0, 3)`, `(0, 4)`, `(2, 3)`, `(2, 4)`.

    Write a function:
    ```
    def solution(A)
    ```

    that, given a non-empty array `A` of `N` integers, returns the number of pairs of passing cars.

    The function should return `-1` if the number of pairs of passing cars exceeds `1,000,000,000`.

    For example, given:
    ```
    A[0] = 0
    A[1] = 1
    A[2] = 0
    A[3] = 1
    A[4] = 1
    ```

    the function should return `5`, as explained above.

    Write an efficient algorithm for the following assumptions:

    * `N` is an integer within the range `[1..100,000]`;
    * Each element of array `A` is an integer that can have one of the following values: `0`, `1`.
'''

from random import randint


def solution(A):
    '''
    Count pairs of passing cars.

    Return -1 if the number exceeds 1000000000.

    Parameters
    ----------
    A : List
        List containing directions of cars. 0 for east, 1 for west.

    Returns
    -------
    west : Integer
        Pairs of passing cars.
    '''
    # passes = []
    # all_passes = 0

    # for car in A:
    #     if car == 0:
    #         passes.append(0)
    #     elif car == 1:
    #         for i in range(0, len(passes)):
    #             passes[i] += 1

    # for passing in passes:
    #     all_passes += passing

    # if all_passes > 100000000:
    #     all_passes = -1

    # return all_passes
    east = 0
    west = 0

    for car in A:
        if car == 0:
            east += 1
        elif car == 1:
            west = east + west

            if west > 1000000000:
                return -1

    return west



highway = [0, 1, 0, 1, 1]

print(solution(highway))

big_highway = []

for i in range(0, 100000):
    big_highway.append(randint(0, 1))

print("Let's go")
print(solution(big_highway))
