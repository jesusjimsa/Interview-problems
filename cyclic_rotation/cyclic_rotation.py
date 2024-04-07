'''
An array `A` consisting of `N` integers is given. Rotation of the array means that each element is shifted right by one
index, and the last element of the array is moved to the first place. For example, the rotation of array
`A = [3, 8, 9, 7, 6]` is `[6, 3, 8, 9, 7]` (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array `A` `K` times; that is, each element of `A` will be shifted to the right `K` times.

Write a function:

```python
def solution(A, K)
```

that, given an array `A` consisting of `N` integers and an integer `K`, returns the array `A` rotated `K` times.

For example, given

```python
    A = [3, 8, 9, 7, 6]
    K = 3
```

the function should return `[9, 7, 6, 3, 8]`. Three rotations were made:

```python
    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
```

For another example, given

```python
    A = [0, 0, 0]
    K = 1
```

the function should return `[0, 0, 0]`.

Given

```python
    A = [1, 2, 3, 4]
    K = 4
```

the function should return `[1, 2, 3, 4]`.

Assume that:

* N and K are integers within the range `[0..100]`;
* Each element of array A is an integer within the range `[-1,000..1,000]`.
'''

def one_rotation(A):
    '''
    Perform one rotation for array `A`.

    Parameters
    ----------
    A : List
        List of integers to rotate.

    Returns
    -------
    new_array : List
        Rotated `A`.
    '''
    new_array = []

    new_array.append(A[-1]) # Begin by adding the last element of 'A' in the first place of the rotated array

    for i in range(0, len(A) - 1):  # We don't add the last element, it has been added in first place previously
        new_array.append(A[i])

    return new_array


def solution(A, K):
    '''
    Rotate `A` `K` times.

    Parameters
    ----------
    A : List
        List of integers to rotate.
    K : Int
        Numebr of times to rotate `A`.

    Returns
    -------
    new_array : List
        Rotated `A`.
    '''
    # There is no need to rotate at all if K is 0 or if K is equal to the size of the array, the elements would just
    # return to their original place after K rotations
    if K == 0 or K == len(A) or not A:
        return A

    new_array = one_rotation(A)

    for _ in range(1, K):
        new_array = one_rotation(new_array)

    return new_array


print(solution([3, 8, 9, 7, 6], 3))     # [9, 7, 6, 3, 8]
print(solution([1, 2, 3, 4], 4))        # [1, 2, 3, 4]
print(solution([], 1))                  # []
