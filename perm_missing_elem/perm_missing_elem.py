'''
An array A consisting of `N` different integers is given. The array contains integers in the range `[1..(N + 1)]`,
which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:
```
    def solution(A)
```

that, given an array `A`, returns the value of the missing element.

For example, given array A such that:
```
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
```

the function should return `4`, as it is the missing element.

Write an efficient algorithm for the following assumptions:

* N is an integer within the range `[0..100,000]`;
* The elements of `A` are all distinct;
* Each element of array `A` is an integer within the range `[1..(N + 1)]`.
'''

def solution(A):
    '''
    Return missing element in array.

    Parameters
    ----------
    A : List
        Array with missing element.
    Returns
    -------
    Int
        Missing element.
    '''
    if not A:
        return 1

    A.sort()

    for i in range(len(A)):
        if i + 1 != A[i]:
            return i + 1

    return len(A) + 1


print(solution([2, 3, 1, 5]))
